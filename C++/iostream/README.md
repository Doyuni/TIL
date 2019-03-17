## istream  
### cin
* 문자(char)를 입력 받을 때, input buffer에 저장되고 저장된 값을 읽어들여 변수에 저장한다.
* 숫자(ex. int)를 입력 받을 때, 변수에 바로 저장한다.  

  -> 입력을 여러 번 받아 정수형 변수에 입력 값을 할당하고자 할 때, 문자가 입력되면 문제가 생긴다.  
  
  * 문자가 입력되면 입력 버퍼에 문자가 저장되고 이 값을 읽어들여 변수에 저장하려고 한다.   
   정상적으로 저장되지 않을 뿐만 아니라 버퍼에 계속 값이 남아 있는 문제가 생긴다.   
   이는 cin.clear() 와 cin.ignore()을 사용하여 해결할 수 있다.  
  
#### Case 1. 엄청 큰 숫자를 입력받고자 할 때
```c++
int getIntBetter()
{
    cout << "Enter an integer number : ";
    int x;
    cin >> x;
    // cin error 발생 시에 1을 반환
    if (std::cin.fail())
    {   // cin의 상태 플래그를 초기화 시켜 cin 기능이 정상작동 하도록 한다. cin.fail()을 초기화
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
* 정수형 변수를 입력 받아야 하는데 문자를 입력한 경우처럼 입력 값과 변수형이 다를 때를 확인해줄 수 있는 함수이다.
* 에러가 발생하면 true(0이 아닌 값) 리턴
#### cin.clear()
* cin의 상태비트를 초기화 시켜준다. 즉, 오류가 난 상태일 경우 원래 값으로 돌려준다. fail()함수를 초기화시켜준다.
#### cin.ignore(n, character)

____
## ostream
* '\n' : new line으로 '\n'다음 문자들은 buffer에 저장만 되어있고 출력이 안될 수도 있다.
* endl : 줄바꿈을 하고 buffer에 있는 것을 모두 출력한다.(비운다)
* flush : 줄바꿈을 안하고 buffer에 있는 것을 모두 출력한다.(비운다)
