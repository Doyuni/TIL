## Data Type

_**Size**_
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

#### 각 type별 범위의 한도 알기

```c++
#include <limits>

std::numeric_limits<int>::max(); // 최대 범위값
std::numeric_limits<int>::min(); // 절댓값일 때 가장 작은 수
std::numeric_limits<int>::lowest(); // 최소 범위값

int i = 2147483647;
i += 1; // overflow
i = -2147483648;
i -= 1; // overflow
```

#### c++11 fixed width integer types
```
#include <cstdint>
int8_t ic = 65; // 1bytes, same as signed char type
int16_t i_16(5); // 2bytes
int_fast8_t // 1bytes, fastest signed char
int_least64_t // 8bytes, least long long
```
