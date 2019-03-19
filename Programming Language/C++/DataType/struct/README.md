### struct
Why need this ?
* 다양한 타입을 한 번에 사용하고자 할 때
* 여러 개의 타입이 필요할 때
* 많은 타입의 특성을 지닌 객체를 표현하고자 할 때
```c++
#include <iostream>
#include <string>

using namespace std;

// 사람을 표현하기위해 많은 인자가 필요하다.
//void printPerson(double height, float weight, int age, ...) { }
struct Person{
    // member
    double  height;
    float   weight;
    int     age;
    string  name;

    void printName() {
        cout << name << endl;
    }
}; // ;로 끝난다는 것에 주의한다.

// struct in struct
struct Family {
    Person me, mom, dad{176.0, 80.0, 51, "Dad"};
};
// return type
Person getMe() {
    Person me{0.0, 0.0, 0, ""};
    return me;
}
void printPerson(Person ps) {
    cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name << endl;
}

struct Employee { // 14 ? No, 16 bytes
    short  id;     // 2bytes (padding 2bytes)
    int    age;    // 4bytes
    double salary; // 8bytes
};
int main() {
    
    double  height;
    float   weight;
    int     age;
    string  name;
// 여러 사람을 표현하기 위해 각각 배열을 사용해야 한다.
// 이런 문제점을 해결하고자 구조체를 쓴다.

    Person me{186.0, 75.0, 23, "Doyuni"};
    // member selection operator
    me.name;
    me.printName();
    Person me2;
    me2 = me; // 단순한 형식일 때만 쓴다.

    Family member;
    member.dad.printName(); // Dad
    member.dad = {0.0, 0.0, 0, "dad"};
    member.dad.printName(); // dad

    Employee employee;

    cout << sizeof(employee) << endl; // 16 bytes
    return 0;
}
```
### Type aliases 
* 자료형에게 가명 붙여주기 -> 유지보수 및 가독성 향상
```c++
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    typedef double distance_t;
/* 
    double이 아닌 float을 사용해야 할 경우 
    모든 변수의 타입을 바꿀 필요 없이 typedef float으로 바꾸기만 하면된다.
*/
    double     my_distance;
    distance_t my_double;
// 고정 너비 정수 _t 는 타입을 뜻한다.
    std::int8_t i(97);

// 자료형이 복잡하거나 길 경우 가독성을 위해서도 쓰인다.
    vector<pair<string, int> > pairlist1;
    vector<pair<string, int> > pairlist2;

    typedef vector<pair<string, int> > pairlist_t;
    pairlist_t pair1;
    pairlist_t pair2;

// using을 사용하여 alias 붙여주기
// 컴파일러에게 이 타입을 표현하기위해 이 이름을 쓰겠다는 뜻
    using weapon_list_t = vector<pair<string, int> >;
    weapon_list_t list1;
    weapon_list_t list2;
    
    return 0;
}
```
