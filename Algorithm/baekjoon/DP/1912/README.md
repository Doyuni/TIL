# 연속합
Using _bottom-up_
* d[n] : n번째까지의 최대 합
* 경우의 수 2가지   
  1. n-1번째까지의 최대 합 + n번째 값  
  2. n번째 값  
## example
| num | 0| 1 | 2|
|----|---|---|--|
|    |10 |-4 |3 |
|d|0|1|2|
|    |10 |6 |9 |
* d[0] = num[0]  
* d[1] = max(-4, 10-4=6)
* d[2] = max( 3, 6+3)  

저장된 d[] 중 최댓값이 정답이 된다.

## C++
```c++
#include <iostream>
using namespace std;
int num[100000];
// n번째까지의 최댓값
long long d[100000]; // 값이 최대 100억이 나올 수 있음
// algorithm 헤더파일의 max는 아예 동일한 타입만 가능
long long max(long long a, long long b) {
    return (a > b) ? a : b;
}
int main()
{
    int n;
    long long result;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    d[0] = num[0];
    // result의 초기화는 0으로 하면 안된다. 최소 -1000이고 d[0]과 비교 안함
    result = d[0];
    for (int i = 1; i < n; ++i)
    { // 현재값 vs 바로 이전까지의 최댓값 + 현재값
        d[i] = max(num[i], d[i-1]+num[i]);
        result =  max(result, d[i]);
    }
    cout << result << endl;
    return 0;
}
```
