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
* 둘의 메모리 주소가 다름을 알 수 있다.  
=> 헤더파일에 extern const로만 변수를 선언해준다.
초기화를 하면 다른 cpp파일에서 헤더파일을 include(포함)할 때마다 초기화를 해주기에 multiple define error가 발생한다."  

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
* 메모리 주소가 같으므로, 메모리 낭비를 해결하였음을 알 수 있다.

### using / auto
