### Control flow
* if, else / for / while / do-while / switch / goto

#### return 과 exit
* return은 return type에 맞게 써주어야 종료되며 종료 이후에도 실행될 가능성이 있다.
* exit은 긴급하게 종료할 때 사용되며 더이상 실행되면 안되는 경우 즉, 무조건 여기서 끝내야 하는 경우에 사용한다.
```c++
#include <cstdlib>
return 0;
exit(0);
```

#### if 문 자주하는 실수
```c++
if(x = 0) {...}

if(x == 1); // null statement
{
  ...
}
```
#### for 문  
변수 여러 개를 동시에 사용 가능하다.
```c++
for(int i=0, j= 9; (i + j) < 10; ++i, --j) {
    if(j < 0) break;
    cout << i << " " << j << endl;
}
```
#### while 문  
static을 사용하여 변수를 한 번만 초기화하여 사용할 수 있다.
```c++
while(1) {
    static int count = 0; // 이러면 굳이 밖에 선언하지 않아도 된다.
    cout << count << endl;
    ++count;
}
```
#### switch 문
* 블록 끝에 도달하거나 return, goto, break, exit을 만나면 종료된다.  
* case label에 종료 조건이 없으면 다음 case 문으로 넘어간다. (fall-through)  
* switch 문 내부에서 case label 과 default label 밖이나 안에 변수를 선언할 수 있지만 초기화는 불가능하다.  
=> 초기화가 포함된 label이 실행되지 않을 수 있기 때문이다. 물론 모든 case label 이전에도 초기화는 불가능하다.  
  * case label에 블럭을 만들면 블럭 내에서 초기화가 가능하다. 단, 블럭 내에서만 사용가능  
  * label은 모두 같은 scope(범위)에 속하여 선언된 변수를 선언한 label 이후의 case label에서도 사용할 수 있다.  
  
```c++
    char d;
    cin >> d;
   
    const int e = 1;
    switch (d) // char, short, int, long, long long, enum과 같은 정수형만으로 평가된다.
    {
        int a; // 선언은 가능
        int b = 5; // 초기화는 불가능
// case label에는 상수 표현식(리터럴 상수, 열거형 or 상수 변수(const int))만 가능하다.
    case e: 
        int b;
        cout << "one";
        break;
// 중복 값을 허용하지 않는다.
    case 1: 
    case 2: {
      int x = 2;
    }
    case 3:
        b = 3;
        cout << b << endl;
        cout << x << endl; // 
    default:
        cout << e << endl;
    }
```
#### goto 문  
라벨을 지정하여 해당 라인에서 실행시킬 수 있다.  
```c++
int input;
restart : // label
    cout << "Enter a native number" << endl;
    cin >> input;
if(input < 1) goto restart;
```
