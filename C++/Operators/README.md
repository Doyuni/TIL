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
(a+b)에서 -1 (int)
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
y =  5 % -2;  // 1
y = -5 % -2;  // -1
```

### Increment & decrement operator
* 후위 증감 연산자
* 전위 증감 연산자
```c++
// add는 인자 두 값을 더한 값을 반환하는 함수

int v = add(x, ++x); // do not use
cout << v << endl;   // 컴파일러에 따라 다른 값이 출력

v = add(x, ++y);     // 영향을 주지 않으니 상관없다.
cout << v << endl;
```

### Sizeof operator
* sizeof는 operator라는 것을 표준에서 정해놓았고, operator이기에 ()가 필요 없다.
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
```c++
// >=, >>, <=, <<, ==, !=
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
* 대입 연산자
int z = x; // x변수가 가리키고 있는 메모리의 정보를 z변수가 가리키고 있는 메모리에 복사해서 넣어라.
