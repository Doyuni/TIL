### namespace
_Usage_
```c++
namespace fun1 {
    int a = 1;
    void doSomething() {
        a += 3;
    }
}
namespace fun2 {
    int a = 1;
    void doSomething() {
        a *= 3;
    }
}

namespace work1::work11::work111 {
    int a = 1;
    void doSomething()
    { 
        a += 3;
    }
}
int main(){  
// scope resolution operation
    fun1::a;
    fun1::doSomething();
    fun2::a;
    fun2::doSomething();
    cout << fun1::a << endl;
    cout << fun2::a << endl;

    work1::work11::work111::doSomething();
    cout << work1::work11::work111::a << endl;
    ...    
}
```
### local / global / static variable
* global variable은 main밖의 함수에서도 사용이 가능하다.. scope ::를 통해 접근이 가능하다.
* local variable은 block 내에서만 사용할 수 있다. 
* static variable은 global variable와 다르게 직접 접근이 어렵다.  
OS로부터 받은 변수의 메모리가 동적이므로 초기화는 한 번만 실행된다.
```c++
int value = 123; // external linkage

static int s_value = 1;

int main() {
  int value = 3;
  cout << ::value << endl; // 123
  cout << value << endl;   // 3
  ...
}
```
```c++
void doSomething() {
// 호출될 때마다 OS로부터 메모리를 받아온다. (정적)
    int a = 1;
    ++a;
    cout << a << endl;
}

void static_doSomething() {
    static int a = 1;
    ++a;
    cout << a << endl;
}
int main() {
   doSomething();        // 2
   doSomething();        // 2

   static_doSomething(); // 2
   static_doSomething(); // 3
    ...
}
```
### extern
* 몸체는 어딘가에 있기에 compile에선 넘어간다. linking할 때 몸체가 어딨는지 확인한다.  
단, 몸체에서 초기화를 해주지 않으면 메모리를 갖고 있지 않게 되므로 에러가 난다.  
또한, 초기화를 두 번 이상 해주면 에러가 난다.    

extern.cpp
```c++
#include <iostream>

extern int ex_a;
extern int ex_b = 456;

void globalDoSomething() {
    using namespace std;
    cout << "Hi" << endl;
}
```

main.cpp
```c++
//forward declarartion
extern void globalDoSomething(); // extern 생략 가능

// ERROR
extern int ex_a;       // 몸체에서 초기화를 해주지 않아서 메모리를 갖고있지 않다.
extern int ex_b = 123; // Multiple define(LINK ERROR)

int main() {
//external linkage
  globalDoSomething();
  ...
}
```
* 메모리 낭비를 막기 위해 extern을 사용한다.  

constant.cpp
```c++
#include <iostream>
#include "MY_CONSTANTS.h"

using namespace std;

void doSomething(); 

int main() {

    cout << "In constant.cpp " << constants::pi << 
    " " << &constants::pi << endl;
    doSomething();
    return 0;
}
```
constant_test.cpp
```c++
#include <iostream>
#include "MY_CONSTANTS.h"

using namespace std;

void doSomething() {

    cout << "In constant_test.cpp " << constants::pi << 
    " " << &constants::pi << endl;
    // 이렇게 되면 메모리 낭비가 심해질 수 있다.
    // solution
    // ->  헤더파일에 extern const pi;
    // -> 헤더파일에서 초기화를 해주면 다른 cpp파일에서 쓸 때마다
    // 초기화를 해준다는 뜻으로 multiple defined error 발생
    // -> my_constatant.cpp에 extern const pi(3.141592);
}
```
![output1](./output1.png)  
* 둘의 메모리 주소가 다름을 알 수 있다.  
=> 헤더파일에 extern const로만 변수를 선언해준다.  
초기화를 하면 다른 cpp파일에서 헤더파일을 포함할 때마다 초기화를 해주기에 multiple define error가 발생한다.

MY_CONSTANTS.h
```c++
namespace constants
{
    extern const double pi;
    extern const double avogadro;
    extern const double moon_gravity;
    //...
} 
```
my_constant.cpp
```c++
namespace constants
{
    extern const double pi(3.141592);
    extern const double avogadro(6.0221413e23);
    extern const double moon_gravity(9.8/6.0);
    //...
}
```
![output2](./output2.png)  
* 메모리 주소가 같으므로, 메모리 낭비를 해결하였음을 알 수 있다.

### using
* namespace에만 using을 사용할 수 있다.
* header파일에 namespace를 큰 영역(전역 변수처럼)으로 사용하면 위험하다.
이 header파일을 포함하는 cpp 파일 전체가 namespace의 영향을 받기 때문이다.
그래서 작은 블럭 단위로 사용해야 안전성을 높일 수 있다.
```c++
namespace a {
    int my_var(10);
    int my_a(1);
    int count(123);
}
namespace b {
    int my_var(20);
    int my_b(2);
}
int main() {
    
    // cout, endl은 namespace가 아니다.
    using std::cout; 
    using std::endl;
    cout << "using" << endl;

    using namespace a;
    using namespace b;
    // 이름이 같다면 error 발생
    cout << my_var << endl; // ambiguous 
    // 이름이 다르면 상관없다.
    cout << my_a << endl;
    cout << my_b << endl;

    using namespace std;
    {
        using namespace a;
        cout << my_var << endl;
        // std 에 count가 있으므로 a::count라 써야한다.
        cout << count << endl; 
    }
    {
        using namespace b;
        cout << my_var << endl;
    }
    ...
}
```

### auto
* 함수의 return type으로 auto를 사용할 수 있다.
하지만, 함수의 parameter type에는 auto를 사용할 수 없다.
=> 이는 parameter type을 자동으로 추론해달라는 auto를 사용하는 의도와 달리,  
다양한 경우에 대해서 함수가 만들고자 하는 의도이기에 이는 template를 사용해야 한다.
```c++
auto sum(double a, double b) {
    return a+b;
}
// trailing return type을 쓰면 어떤 타입을 반환하는지에 대한 가독성이 좋다.
auto sum(float a, float b) -> double {
    return a+b;
}
auto sum(int a, int b) -> int {
    return a+b;
}
int main() {
// 초기화를 해줘야 컴파일이 무슨 type인지 알 수 있다.
    auto a = 1;
    auto b = 1.0;
    auto c = 1 + 2.0;
    auto result = sum(1, 2); 
    ...
}
```
