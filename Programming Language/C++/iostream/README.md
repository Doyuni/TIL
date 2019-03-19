## istream  
### cin
* 문자(char)를 입력 받을 때, input buffer에 저장되고 저장된 값을 읽어들여 변수에 저장한다.
* 숫자(ex. int)를 입력 받을 때, 변수에 바로 저장한다.  

  -> 입력을 여러 번 받아 정수형 변수에 입력 값을 할당하고자 할 때, 문자가 입력되면 문제가 생긴다.  
  
  * 문자가 입력되면 입력 버퍼에 문자가 저장되고 이 값을 읽어들여 변수에 저장하려고 한다.   
   정상적으로 저장되지 않을 뿐만 아니라 버퍼에 계속 값이 남아 있는 문제가 생긴다.   
   이는 cin.clear() 와 cin.ignore()을 사용하여 해결할 수 있다.  
 
#### Case 1. cin.fail()
```c++
int a, b;
int num = 2;

cin >> a;
if (cin.fail())
{
    cout << "a error" << endl;
}
cin >> b;
if (cin.fail())
{
    cout << "b error" << endl;
}
```
* 첫 입력에서 에러가 났기 때문에 failbit 상태가 되었고 cin이 정상 작동하지 않게된다.
_input_
```
d
```
_output_
```
a error
b error
```
#### Case 2. Usage of cin.clear()
```c++
// cppreference 예제
double n;
while (std::cout << "Please, enter a number\n" && !(std::cin >> n))
{
    std::cin.clear();
    std::string line;
    std::getline(std::cin, line);
    std::cout << "I am sorry, but '" << line << "' is not a number\n";
}
std::cout << "Thank you for entering the number " << n << '\n';
```
* 문자를 입력하면 다시 입력을 받도록 한다. failbit를 goobit로 초기화 시키는 작업으로 cin이 정상으로 작동하도록 한다.

* cin.clear()를 사용하지 않고 문자를 입력하면 I am sorry ~가 끝없이 출력된다.  
-> failbit의 상태가 유지되기 때문에 getline의 cin, while 조건문의 cin이 모두 failbit로 작동하지 않기 때문이다.  

_input_
```
d
```
_output_
```
I am sorry, but "d" is not a number
```
#### Case 3. 엄청 큰 숫자를 입력받고자 할 때
```c++
int getIntBetter()
{
    cout << "Enter an integer number : ";
    int x;
    cin >> x;
    // cin error 발생 시에 1을 반환
    if (std::cin.fail())
    {   // cin.fail()을 초기화
        std::cin.clear();
        // 입력 버퍼에 있는 모든 내용을 버린다.
        std::cin.ignore(32767, '\n');
        cout << "Invalid number, please try again" << endl;
    }
    else
    {
        std::cin.ignore(32767, '\n');
        return x;
    }
}

```
#### cin.fail()
* 정수형 변수를 입력 받아야 하는데 문자를 입력한 경우처럼 입력 값과 변수형이 다를 때 에러가 났음을 확인할 수 있다.
* 에러가 발생하면(failbit) true(0이 아닌 값)를 리턴한다.
#### cin.clear()
* cin의 에러 상태 플래그(cin.fail())를 초기화 시킨다. failbit -> goodbit
* 실제로 입력버퍼를 비우는게 아닌 버퍼가 비었다고 인식하게 만든다.
* '\n'의 입력을 비었다고 인식하게 할 수 없어 ignore()이나 fflush(stdin)이 필요하다.
#### cin.ignore(n, character)
* n: 읽어들일 문자의 개수, character: 종료 기준 문자
* 예를들어, cin.ignore(3, '\n'): 은 문자 3개까지 읽어 버퍼에 저장하고 '\n'을 읽어들이면 버퍼를 비운다.  
  읽어들일 문자의 개수를 채우지 않은 상태에서 '\n'을 입력 받으면 버퍼를 비우고 종료된다.
____
## ostream
* '\n' : new line으로 '\n'다음 문자들은 buffer에 저장만 되어있고 출력이 안될 수도 있다.
* endl : 줄바꿈을 하고 buffer에 있는 것을 모두 출력한다.(비운다)
* flush : 줄바꿈을 안하고 buffer에 있는 것을 모두 출력한다.(비운다)
