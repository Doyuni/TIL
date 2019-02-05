# 헨리
#### 헨리식 표현법을 구하는 방법을 예제에 적용하여 구해보면 규칙이 나온다.
* 5/7 의 헨리식 표현법을 구하는 과정
	* a = 5, b = 7, x = ?
	* 5/7 >= 1/x 를 만족하는 x를 찾는 과정이다.
		* 이는 결국 x >= 7 / 5로 나타낼 수 있고, 이를 만족하는 x의 최솟값을 구한다.  
		* x는 2가 되고, 다음 a, b를 구하는 방법은 다음과 같다.  
       x를 구할 때는 나누어 떨어지는 경우와 나누어 떨어지지 않는 경우로 나눠서 계산해야 한다.
		* a = 5 * 2 - 7,  b = 7 * 2  
  * 3/14 >= 1/x 를 만족하는 x를 위와 같은 방식으로 찾아낼 수 있다.  
  
그렇다면 언제 이 과정을 멈추어야 할까 ? 이 과정을 계속하면 a가 1보다 작게 되는 경우가 나온다.
    
| No | a | b | x |
|----|---|---|---|
| 1  | 5 | 7 | 2 |
| 2  | 3 | 14 | 5 |
| 3  | 1 | 70 | 70 |
| 4  | 0 | 4900 | X |
* a가 1보다 작을 때까지 이 과정을 수행하고 이때 x의 값이 정답이 된다.  

*주의 )*  
 아래 코드에서 a = a * x - b를 a *= x - b로 하면 절대 안된다. ( a *= x 가 먼저 수행되어 a에 값이 할당되고 - b가 수행된다.)
## C++
```c++
#include <iostream>
using namespace std;
int main()
{
    int T, a, b, x;
    cin >> T;
    while (T--)
    {   // a는 분자, b는 분모.
        cin >> a >> b;
        while (a > 0)
        {
            if (b % a == 0)
            {
                x = b / a;
            }
            else
            {
                x = b / a + 1;
            }
            a = a * x - b;
            b *= x;
        }
        cout << x << endl;
    }
    return 0;
}
```