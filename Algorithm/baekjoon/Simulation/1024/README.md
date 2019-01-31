# 수열의 합
* 수열의 길이가 적어도 L이니까 L부터 100까지 수열이 존재를 확인해야 한다.

* 길이가 L인 수열을 합이 N이므로, N/L로 접근해야 한다.
* N/L 값이 수열의 중간값이 되고 길이가 L이니까 L/2만큼 더하거나 빼면 수열의 처음과 마지막 수를 알 수 있다.
  * 수열의 첫 번째 수를 이용해 답을 출력하려면 길이가 짝수인 경우에 답을 도출할 수 없게 된다.  
  
    * N = 10, L = 4 일 때 middle = 2, start = 2 - 4/2 = 0, end = 2 + 4/2 = 4
    
    start로 수열을 구한 경우
    ```
    0 1 2 3  sum = 6
    ```
    end로 수열을 구한 경우
    ```
    1 2 3 4  sum = 10
    ```
  그러므로, 마지막 수를 이용하여 수열을 구해야 한다.  
* 0도 수열에 속할 수 있다. (음이 아닌 정수)

* 음수가 나오면 다음 L로 넘어가야 한다.

* 모든 L을 비교해도 수열이 존재하지 않으면 -1을 출력한다.  

## C++
```c++
#include <iostream>
using namespace std;
int main()
{
    int N, L, middle, end, i;
    cin >> N >> L;
    for (i = L; i <= 100; ++i)
    {
        middle = N / i; 
        end = middle + i / 2; // 리스트 중 최댓값
        int sum = end;
        for (int j = 0; j < i-1; j++) // 이미 합에 끝의 값이 합해짐.
        {
            sum += (--end); // 하나씩 줄여가며 주어진 길이만큼 더해간다.
        }
        if (end < 0) // 음이 아닌 정수이어야 한다.
            continue;
        if (sum == N)
        {
            for (int j = 0; j < i; j++)
            { // 하나씩 늘려가며 음이 아닌 정수 리스트를 출력한다.
                cout << end++ << " "; 
            }
            break;
        }
    }
    if (i == 101) cout << -1 << endl;
    return 0;
}
```
### 다른 방법도 있다. (수학을 이용)
 * x를 수열의 첫 번째 수라고 하면 다음 식이 성립한다.
* N = x + (x + 1) + (x + 2) + … + (x + L - 1)  
  = x * L + (1 + 2 + 3 + … + L-1)  
  = x * L + ((L-1) * L / 2)  
  
* subtotal = (L-1) * L / 2  
* x는 음이 아닌 정수로 나누어 떨어져야 한다.  
  * x = (N - subtotal) / L

## C++
```c++
#include <iostream>
using namespace std;
int main()
{
    int N, L, start= -1, i;
    cin >> N >> L;
    for (i = L; i <= 100; i++)
    {
        int subtotal = i * (i- 1) / 2;
        if ((N - subtotal) / i >= 0 && (N - subtotal) % i == 0) {
            start = (N - subtotal) / i;
            break;
        }
    }
    if (start == -1)
        cout << -1;
    else
        for (int j = 0; j < i; j++)
            cout << start++ << " ";
    return 0;
}
```
