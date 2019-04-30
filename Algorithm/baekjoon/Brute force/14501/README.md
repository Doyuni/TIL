## 퇴사
[문제](https://www.acmicpc.net/problem/14501)
* N은 최대 15이다.  
각 일자의 상담을 할 수도 안할 수도 있는 경우 2가지가 존재하고 최대 나올 수 있는 경우는  
2^15이다.(상담 필요기간이 모두 1이라 가정했을 때) 이는 총 32768(약 3만)으로 시간 제한을 넘지 않는다.
* **재귀함수**를 이용하여 경우의 수를 구한다.  

**void maxWage(int day, int sum)** // day는 현재 일 수, sum은 현재까지 받을 수 있는 총 금액  
1. 성공 조건  
day가 퇴사일(n)과 같아야 한다. 이때 받을 수 있는 최대 금액을 판단한다.
2. 불가능 조건  
day가 퇴사일(n)을 넘기면 구할 수 없다.  
3. 함수 호출  
    - 상담 했을 때
    - 상담 안했을 때

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans, n;
vector<int> t, p;
void maxWage(int day, int sum) {
    if(day == n) {
        ans = max(ans, sum);
        return;
    } 
    if(day > n) return;
    maxWage(day+t[day], sum+p[day]); // 상담했을 때
    maxWage(day+1, sum); // 상담 안했을 때
}
int main() {
    int day, wage;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> day >> wage;
        t.push_back(day);
        p.push_back(wage);
    }
    maxWage(0, 0);
    cout << ans << '\n';
    return 0;
}
```
