### 프로모션
* 피연산자의 자료형이 다르거나 자료형의 범위가 너무 작은 경우 컴파일러는 이들을 같은 자료형으로 변환해서 계산

1. 정수 & 실수 : 정수형이 실수형으로 변환
2. 양쪽 다 정수형 or 양쪽 다 실수형: 보다 넓은 범위를 갖는 자료형으로 변환
3. 양쪽 다 int형보다 작은 정수형: 양쪽 다 int형으로 변환
4. 부호 없는 정수형 & 부호 있는 정수형: 부호 없는 정수형으로 변환
```c++
unsigned char a = 17;
short b = -18;
int c = 2;
unsigned int d = 0;
cout << (a+b) * c + d << endl;
```
* -2가 되어야 하는데 4294967294라는 값이 출력됨
```
(a+b)  에서 -1 (int)
-1 * c 에서 -2 (int)
-2 + d 에서 unsigned int
=> 2^32 - 2 = 4294967294
```

### Arithmetic operators
```c++
int x = 3 * 2 / 3;     // 2
int a = (3 * 2) / 3;   // 2
int b = 3 * (2 / 3);   // 0
int c = 1;
// 왼쪽엔 아무것도 없고 오른쪽에만 있으니
// 오른쪽에서 왼쪽으로
// right to left: -3, !true
int t = 10, w = 2;
t /= --w + 1;   // --, +, /= 순으로 판단된다.
// t: 5, w: 1

if (a || b && c) {  // same as a || (b && c)
  //...  
} 
// Precedence of && operator  is higher than that of || operator

x = 1;
int y = -x;   // 단항 연산자는 헷갈리지 않게 붙여쓰는게 좋다.
```

#### 음의 정수를 나누는 경우 (C++11 이후)
-5 / 2 = -2.5가 아닌 버림을 하여 -2  
-5 % 2 = -1  왼쪽의 부호에 따라 부호가 결정된다.
```c++
y = -5 /  2;  // -2
y =  5 % -2;  //  1
y = -5 % -2;  // -1
```

### Increment & decrement operator
* 후위 증감 연산자
* 전위 증감 연산자
```c++
// add는 인자 두 값을 더한 값을 반환하는 함수

int v = add(x, ++x); // do not use
cout << v << endl;   // depending on compiler

v = add(x, ++y);     // 영향을 주지 않으니 .
cout << v << endl;
```

### Sizeof operator
* sizeof가 operator라는 것을 표준에서 정해놓았고, operator이기에 ()가 필요 없다.
```c++
float f;
// type or variable 모두 가능
sizeof(float);
sizeof(f);
sizeof f;   // type일 때는 () 필요
```

### Comma operator
```c++
int xc = 3;
int yc = 10;
// using in for statement
int zc = (++x, ++y); // 11
//same as below
++xc;
++yc;
zc = yc;

// just distinguish
int ac = 1, bc = 10;
add(1, 2); 

// comma의 우선순위는 가장 낮기에 = 연산자가 먼저 판단된다.
zc = ac, bc;  
// zc는 1의 값을 갖는다.
zc = (ac++, ac + bc++); // 12
zc = (ac++, ac + ++bc); // 13
zc = (ac, ac++ + bc++); // 11
```

### Conditional operator (arithmetic if)
```c++
// const를 쓰려면 선언과 동시에 초기화를 해줘야 하기 때문에 조건문으로 나눠서 초기화는 불가
bool onSale = true;

// use in simple case
const int price = (onSale == true) ? 10 : 100;

// precedence of << operator is higher than conditional operator
cout << ((x % 2 == 0) ? "even" : "odd") << endl;
```

### Relational operators
 **>=, >>, <=, <<, ==, !=**
```c++
double d1(100 - 99.99);
double d2(10 - 9.99);

// caution !! be careful if use floating point numbers
if (d1 == d2)
{
    cout << "equal" << endl;
}
else
{
    cout << "not equal" << endl; 
    if (d1 > d2)
        cout << "d1 > d2" << endl;
    else
        cout << "d1 < d2" << endl;
}
// Print "not equal" and "d1 > d2"

const double epsilon = 1e-10;
// abs(d1 - d2): 5.32907e-15

if (abs(d1 - d2) < epsilon)
{
    cout << "Approximately equal" << endl;
}
else
{
    cout << "Not equal" << endl;
}
// Print "Approximately equal"
```

### Logical operators
* logical NOT : !
* logical AND : &&
* logical  OR : ||
```c++
//short circuit evaluation
int lx = 2;
int ly = 2;
if (lx == 1 && ly++ == 2)
{
    // ly++ == 2를 판단하지 않는다.
}
cout << ly << endl;   // 2

// De Morgan's Law
!(x || y);  // same as !x && !y

bool bx = true;
bool by = false;
// XOR (if two values differ, return true otherwise return false)
cout << (bx != by) << endl;
```

### Binary numbers 
* 2로 나눈 나머지로 구하는 방법 외에 다른 방법으로 구하기.
 
* 10진수 양의 정수 148을 2진수로 변환
```
1 2 4 8 16 32 64 128 256

    148 >= 128              Yes -> 8번째 자리 1
    148-128=20, 20 >= 64    No  -> 7번째 자리 0
                20 >= 32    No  -> 6번째 자리 0
                20 >= 16    Yes -> 5번째 자리 1
    20-16=4,    4 >= 8      No  -> 4번째 자리 0
                4 >= 4      Yes -> 3번째 자리 1
    4-4=0
   => 1001 0100
```
  * 10진수 음의 정수 -5를 2진수로 변환
```
음의 정수 2진수 표현
    -5 (decimal)
  1. 숫자만 이진수로 바꾼다.
    0000 0101
  2. 보수 complement
    1111 1010
  3. 1을 더한다.
    1111 1011 
   * 왜 1을 더하는가 ?
    맨 앞의 1비트는 부호비트로 0이면 양수, 1이면 음수이다.
    0이 2가지 형태가 되는 것을 막기위해 1을 더한다.
    양의 정수에서 0
    0000 0000
    음의 정수에서 0
    1111 1111
    여기에 1을 더해야 같은 형태가 된다.
```
* 2진수 1001 1110을 10진수로 변환
  * 맨 앞의 비트는 부호 비트(1이면 음수, 0이면 양수)
```
  1. 보수를 취한다.
    0110 0001
  2. 1을 더한다.
    0110 0010 -> 98
  3. 부호를 붙인다.
    -98 
```
### Bitwise operators
**<<(left shift), >>(right shift)**  
 _Why need these ?_  
 * bool type을 예로 들면, bool은 0, 1만 저장하는데 메모리는 byte 단위 즉, 주소를 셀 수 있는 단위는 최소 8bits이다.
   2^8 중 2개만 사용하기에 메모리를 낭비하게 된다.  
   이런 메모리를 아끼고 전부 의미있게 사용하기 위해 비트 단위 연산자가 이용된다.    
   또한, 비트 단위 연산자를 이용하면 계산속도가 빠르다.    
    * 1024 / 8 보다 shift 연산이 더 빠르다.
    컴퓨터 내부의 data가 저장된 방식으로 밀기 때문이다.
```c++
#include <bitset>
unsigned int bit_a = 3;
//어떻게 저장되는지 내부적으로 보여준다.
cout << std::bitset<4>(bit_a) << endl; // 0011

unsigned int bit_b = bit_a << 1;              // 3 * 2^1 (left shift one time)
cout << std::bitset<4>(bit_b) << endl;        // 0110, 6
cout << std::bitset<8>(bit_b << 2) << endl;   // 00011000, 6 * 2^2
cout << std::bitset<8>(bit_b << 3) << endl;   // 00110000, 6 * 2^3
cout << std::bitset<32>(bit_b << 29) << endl; // 11000000000000000000000000000000, 6 * 2^29
// int형이기에 32이상 쓸 수 없음 << 30으로 shift하면 맨 앞의 1은 잘려나간다.
cout << std::bitset<4>(bit_b >> 2) << endl;   // 0011, 6 / 2^1 = 3
cout << std::bitset<4>(bit_b >> 3) << endl;   // 0001, 6 / 2^2 = 1
```
* bitwise not: **~**
```c++
#include <bitset>
// 0b (binary number)
unsigned int bi_a = 0b1100;
unsigned int bi_b = 0b0101;
cout << bitset<4>(~bi_a) << endl;       // bitwise NOT  0011
cout << bitset<4>(bi_a & bi_b) << endl; // bitwise AND  0100
cout << bitset<4>(bi_a | bi_b) << endl; // bitwise  OR  1101
cout << bitset<4>(bi_a ^ bi_b) << endl; // bitwise XOR  1001
```
* **bit flag, bit mask**
1. 예제) 특정 아이템
```c++
#include <bitset>
const unsigned char opt0 = 1 << 0;
const unsigned char opt1 = 1 << 1;
const unsigned char opt2 = 1 << 2;
const unsigned char opt3 = 1 << 3;
// ... opt4 , 5, 6, 7

unsigned char items_flag = 0;
// item 8개의 소지 여부를 확인 가능 (1bytes만으로)
cout << "No item " << bitset<8>(items_flag) << endl;

// get item0
items_flag |= opt0;
cout << "Item0 obtained " << bitset<8>(items_flag) << endl; // 00000001

// get item3
items_flag |= opt3;
cout << "Item3 obtained " << bitset<8>(items_flag) << endl;

// lost item3
items_flag &= ~opt3;
cout << "Item3 lost " << bitset<8>(items_flag) << endl;

// has item1 ?
if (items_flag & opt1)
    cout << "Has item1" << endl;

// has item0 ?
if (items_flag & opt0)
    cout << "Has item0" << endl;

// obtain item2 & item3
items_flag |= (opt2 | opt3);
cout << "Item2 & item3 obtained " << bitset<8>(items_flag) << endl;
// item이 많으면 for문으로 해결
// 상태를 바꿔주는 XOR
//  item2 on -> off, item1 off -> on
if ((items_flag & opt2) && !(items_flag & opt1))
{
    items_flag ^= (opt2 | opt1);
}
cout << "swap item2 & item3  " << bitset<8>(items_flag) << endl;
```
2. 예제) RGB pixel
* RGB + α : FF FF FF α => 4bytes(same as size of integer type)
  * Red color pixel: 00000000 11111111 00000000 00000000  (255, 0, 0)
```c++
const unsigned int red_mask   = 0xFF0000;
const unsigned int green_mask = 0x00FF00;
const unsigned int blue_mask  = 0x0000FF;

unsigned int pixel_color = 0xDAA520;

cout << bitset<32>(pixel_color) << endl;
// mask를 이용해 색깔 추출

unsigned char blue = pixel_color & blue_mask;   // 최대 bitset 8까지만 가능
unsigned int green = pixel_color & green_mask;  // 최대 bitset 32까지만 가능
cout << "blue " << bitset<8>(blue) << " " << int(blue) << endl;
cout << "green " << bitset<16>(green) << " " << int(green) << endl; // 42240이 출력된다.(shift 필요)
green >>= 8;
cout << "green " << bitset<8>(green) << " " << int(green) << endl;  // 165
unsigned int red = (pixel_color & red_mask) >> 16;
cout << "red " << bitset<8>(red) << " " << int(red) << endl;        // 218
```
3. 예제) bit_mask_quiz.cpp 참고

