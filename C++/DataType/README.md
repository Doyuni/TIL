## Data Type

### Size
```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "bool\t\tis " << sizeof(bool) << "bytes." << endl;
    cout << "char\t\tis " << sizeof(char) << "bytes." << endl;
    cout << "wchar_t\t\tis " << sizeof(wchar_t) << "bytes." << endl;
    cout << "char16_t\tis " << sizeof(char16_t) << "bytes." << endl;
    cout << "char32_t\tis " << sizeof(char32_t) << "bytes." << endl;
    cout << "short\t\tis " << sizeof(short) << "bytes." << endl;
    cout << "int\t\tis " << sizeof(int) << "bytes." << endl;
    cout << "long\t\tis " << sizeof(long) << "bytes." << endl;
    cout << "long long\tis " << sizeof(long long) << "bytes." << endl;
    cout << "float\t\tis " << sizeof(float) << "bytes." << endl;
    cout << "double\t\tis " << sizeof(double) << "bytes." << endl;
    cout << "long double\tis " << sizeof(long double) << "bytes." << endl;
    cout << endl;

    return 0;
}

// Print
/**************************/
// bool            is 1bytes.
// char            is 1bytes.
// wchar_t         is 2bytes.
// char16_t        is 2bytes.
// char32_t        is 4bytes.
// short           is 2bytes.
// int             is 4bytes.
// long            is 4bytes.
// long long       is 8bytes.
// float           is 4bytes.
// double          is 8bytes.
// long double     is 16bytes.
```

### 각 type별 범위의 한도 알기
```c++
#include <limits>

// std::pow(2, sizeof(int) * 8 - 1) - 1; // 2^31 - 1 (부호 비트 때문에 1을 빼주고, 숫자 0 때문에 1을 빼준다.)
std::numeric_limits<int>::max(); // 최대 범위값
std::numeric_limits<int>::min(); // 절댓값일 때 가장 작은 수
std::numeric_limits<int>::lowest(); // 최소 범위값

int i = 2147483647;
i += 1; // overflow
i = -2147483648;
i -= 1; // overflow
```
* char type은 int type으로 casting 해야 범위 출력 가능  

### c++11 fixed width integer types
```c++
#include <cstdint>
int8_t ic = 65; // 1bytes, same as signed char type
int16_t i_16(5); // 2bytes
int_fast8_t // 1bytes, fastest signed char
int_least64_t // 8bytes, least long long
```
### Real number
* **Floating point numbers**  
    소수점이 움직인다는 뜻  
    * sign(부호): 1bits, exponent(지수): 8bits, mantissa(가수) 23bits  
    
* IEEE 754 표준 방식을 따른다. (따로 정리할 예정)
* double은 float에 비해 메모리 크기가 2배이기에 꼭 double을 쓰는게 좋지 않을 수 있다.
* 1.234e5 = 1.234 * 10^5, 1e-8 = 1 * 10^(-8)
* 정밀도 표현
```c++
#include <iostream>
#include <iomanip> // io manipulation
cout << 1.0 / 3.0 << endl; // 0.333333 (소수점 아래 6자리까지 출력 )
cout << std::setprecision(16) << endl; (소수점 아래 16자리까지 출력 )
double d1(0.1);
double d2(1.0);
double d3(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
cout << std::setprecision(17);
cout << d1 << endl; // 0.10000000000000001
cout << d2 << endl; // 1
cout << d3 << endl; // 0.99999999999999989
```
* 정밀도에 따라 결과가 다름을 알 수 있다.

### Infinite, Not a number
```c++
#include <cmath>

double zero = 0.0;
double posinf = 1.0 / zero;  // inf
double neginf = -1.0 / zero; // -inf
double nan = zero / zero; // nan(ind): not a number (indetermine)
//cmath
    if (isinf(posinf))
        cout << "infinite" << endl;
    if (isinf(neginf))
        cout << "negative infinite" << endl;
    if (isnan(nan))
        cout << "not a number" << endl;
```

### bool
```c++
#include <iostream>

bool b1 = true; // copy initialization
bool b2(false); // direct initialization
bool b3{true};  // uniform initialization
//bool변수를 true or false로 출력해준다.
cout << std::boolalpha;
cout << b2 << endl; // false
cout << !false << endl; // true
cout << std::noboolalpha;
cout << b2 << endl; // 0
cout << !false << endl; // 1
bool binput = true;
cin >> binput; // 컴파일러에 따라 다르다. true 입력해도 false일 수 있다.
cout << binput << endl;
```

### literal constants & symbolic constants

_**constants.cpp**__
```c++
#include <iostream>
#include "MY_CONSTANTS.h"
using namespace std;

int main() {
// literal constants : 3.14는 바꿀 수 없다.
    // f가 없으면 double로 간주해서 float 으로 캐스팅 된다.
    float pi = 3.14f;  
    unsigned int n = 5u;
    long n2 = 5L;
    double d = 6.0e-10;

// 2진수, 8진수, 16진수 표현법
    int bi = 0b1010;
    // 컴파일러가 '를 무시하기 때문에 사람이 보기 편하게 구분지을 수 있다.
    int binary = 0b1011'1111'1010; 
    int octal = 012 ;
    int he = 0xF;
    int hexa = 0xFAED'1234'EFAB;

// symbolic constants
    int num_items = 123;
    // magic number로 사용하는 것은 좋지 못함.
    //int price = num_items * 10; // magic nunber = 10;
    const int price_per_item = 10;
    int price = num_items * price_per_item; // symbolic 상수를 쓰자.
    
// constexpr vs const
    const int compile_number(123); // 컴파일 타임 상수
    int num;
    cin >> num;
    const int runtime_number(num); // 런타임 상수
    // 컴파일 타임에 완전히 결정되는 상수라는 것을 표현, 런타임 상수에 못 씀
    constexpr int cnum(234);
    //상수로 대체하기 위해 macro를 쓰는 것은 좋지 않음
    // #define PRICE_ITEM 10;
    //1. 디버깅 힘들다. 2. 적용범위가 너무 넓다.

// 
    // const 상수들은 헤더파일에 따로 모아놓는게 좋다.
    double radius;
    cin >> radius;
    // 원둘레
    double circumference = 2.0 * radius * constants::pi;
    
    return 0;
}
```
_**MY_CONSTANTS.h**__
```c++
namespace constants
{
    constexpr double pi(3.141592);
    constexpr double avogadro(6.0221413e23);
    constexpr double moon_gravity(9.8/6.0);
    //...
}
```
