## 1, 2, 3 더하기
[문제](https://www.acmicpc.net/problem/9095)
* N은 최대 10이며 순서를 신경쓰지 않는다.  
그러므로 최대 경우의 수는 3^10 = 59049이다.
* 10중 for문을 사용해 모든 경우의 수를 구할 수 있지만,  
코드의 간결성과 오류를 줄이고자 **재귀함수**로 구현하였다.

```c++
#include <iostream>
using namespace std;
int goal, cnt;
void OneTwoThree(int n) {
    if(n == goal) {
        cnt++;
        return;
    } else if (n > goal) {
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        OneTwoThree(i+n);
    }
}
int main()
{
    int test_case;
    cin >> test_case;
    while(test_case--) {
        cnt = 0;
        cin >> goal;
        for(int i = 1; i <= 3; ++i) {
            OneTwoThree(i);
        }
        cout << cnt << endl;
    }
    return 0;
}
```
