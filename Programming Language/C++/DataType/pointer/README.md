## Pointer
```c++
#include <iostream>
#include <typeinfo>
#include <cstddef>
using namespace std;
/*
    지역 변수는 stack 메모리를 사용하고
    동적 할당 메모리는 heap 메모리를 사용한다.

    큰 메모리에 저장되어 있는 데이터 중에서 일부분을 CPU가
    사용하기 위하여 메모리로부터 가져올 때는 메모리 전체를 모두
    뒤지면서 찾는 것이 아니라 필요한 데이터가 저장되어 있는 '주소'를
    사용하여 직접 접근하여 가져옵니다.
*/
struct Alphabet
{
    int a, b, c, d; // 4  * 4 = 16 바이트
};

enum Type {
    INT,
    FLOAT,
    CHAR,
};

void printAddress(int *ptr) {
    cout << "address of pointer variable in func: " << &ptr << endl;
}
int main()
{
    /* 변수가 사용할 메모리 공간을 OS로부터 빌려오고(받아오고)
    빌려올 때 주소를 알고 있는데, 주소를 가지고 있는 메모리 공간에
    값을 넣고 사용한다.
*/
    int x = 5;
    // 16진수
    cout << &x << endl;                // &: address-of opeartor
    cout << typeid(&x).name() << endl; // Pi (Pointer to Integer)
    /* de-reference operator (*)
        포인터가 저쪽 주소에 가면 데이터가 있어요 라고 
        간접적으로 가리키기만 하는 것에 대해서,
        그럼 거기에 진짜 뭐가 있는지 내가 들여다볼께 라며
        직접적으로 접근하겠다는 의미이다.
    */
    cout << *(&x) << endl; // 5

    // 포인터 변수: 메모리 주소를 담는 변수
    int *ptr_x;                   // int*, int *, int * ptr_x 상관 없다.
    ptr_x = &x;                   // 주소를 담는다.
    int *ptr_y = &x, *ptr_z = &x; // 동시에 선언할 때는 *를 꼭 써줘야 한다.
    // 불편함 해소
    typedef int *ptr_int;
    ptr_int ptr_a, ptr_b, ptr_c; // 이렇게하면 *를 굳이 다 안써도 된다.
    ptr_b = &x;

    cout << ptr_x << endl;  // 주소 출력
    cout << *ptr_x << endl; // de-referencing
                            /* 왜 포인터를 쓸까?
        array에 data가 백만개가 있는데 이걸 parameter로 넘기면 복사가 된다.
        메모리에 백만개의 data를 for문에서 여러 번 복사하면 엄청 느려진다.
        pointer로 첫 번째 주소하고 data가 몇 개 있는지 알려주면 다 알 수 있다.

        변수를 그 자체로 여기저기 사용해야 할 때 매번 넘겨주면서 복사를 하면 부담이 된다.
        포인터를 넘겨주면 누구나 다 알게 된다.
    */

    // 포인터는 모든 타입에 대해서 사이즈가 같다. (구조체도 마찬가지)
    // PC가 64비트면 8바이트, 32비트면 4바이트
    int *ptr_i;
    double *ptr_d;
    cout << sizeof(ptr_i) << endl;
    cout << sizeof(ptr_d) << endl;

    Alphabet lower;
    Alphabet *ptr_lower;

    cout << sizeof(Alphabet) << endl; // 16
    cout << sizeof(ptr_lower) << endl;  // 8

    // 포인터는 초기화를 해야 사용가능
    // 초기화를 안하면 쓰레기 값을 가지고 있어 런타임 에러
    // 항상 초기화를 해주는게 좋다.
    int *ptr_in = 0;
    double *ptr_double(NULL);
    Alphabet *ptr_alphabet{nullptr}; // modern c++

    // cstddef
    // parameter로 nullptr만 넣어야할 때 쓰임
    std::nullptr_t nptr; // null pointer만 넣을 수 있음.
    
    // 인자가 포인터인 함수에서 인자의 주소값을 출력하면? -> 메모리 값이 다시 복사가 된다.
    cout << "address of pointer variable in main: " << &ptr_x << endl; // 0x61fe10
    printAddress(ptr_x); // 0x61fde0

    const int cval = 5;
    const int *cptr = &cval; // de-referencing은 불가
    // 즉 주소를 받을 수는 있으나 값 변경은 불가능
    cout << *cptr << endl; // 값 출력은 가능 
    // *cptr = 6; // not allowed
    // cval = 6; // not allowed
    int ival = 5;
    const int *icptr = &ival; // 바꾼 값을 가져올 수는 있다.
    ival = 6;
    // *icptr = 7; // not allowed

    int value1 = 5;
    const int *ptr1 = &value1; 
    /* 가리키고 있는 주소에 있는 값을 안 바꾸겠다.
     주소값을 안바꾼다는 뜻은 아니다. */

    int value2 = 6;
    ptr1 = &value2; // allowed

    int *const ptr2 = &value1; 
    /* 가리키고 있는 주소에 있는 값을 바꿀 수 있다.
     주소값을 바꿀 수는 없다. */
    *ptr2 = 10; // allowed
    cout << *ptr2 << endl;
    //ptr2 = &value2; // not allowed

    //const int *const ptr3; // not allowed  초기화 필요
    /* 주소에 있는 값도, 주소값도 바꿀 수 없다. */
    
    // void pointer ( generic pointer )
    int i = 1;
    float f = 2.0;
    char c = 'c';

    void *ptr = nullptr;

    ptr = &i;
    ptr = &c;
    ptr = &f;
    
    /* 포인터 연산 불가능 어떤 타입인지 알 수 없어서.
    ptr++; // not allowed
    cout << *ptr; // not allowed 어떤 타입을 표현하려고 넣어놓은건지 모른다.
    casting 필요 */
    cout << *static_cast<float*>(ptr) << endl;

    Type type = FLOAT;
    if(type == FLOAT) {
         cout << *static_cast<float*>(ptr) << endl;
    } else if (type == INT) {
         cout << *static_cast<int*>(ptr) << endl;
    }
    
    // 주소는 동일
    cout << &f << " " << ptr << endl; 
    return 0;
}
```
