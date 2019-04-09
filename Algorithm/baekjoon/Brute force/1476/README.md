## 날짜 계산
[문제](https://www.acmicpc.net/problem/1476)
### 풀이 1
* 직관적으로 푼다.
* 가능한 경우의 수는 15 * 28 * 19 = 7980 (시간 제한에 문제 없다.)
* 하나씩 더해가며 답을 찾아낸다.
```c++
#include <iostream>
using namespace std;
int main() {
    int e = 1, s = 1, m = 1;
    int cnt = 1;
    int in_e, in_s, in_m;
    ios_base::sync_with_stdio(false);
    cin >> in_e >> in_s >> in_m;
    if(in_e != 1 || in_s != 1 || in_m != 1) {
        while(true) {
            e++, s++, m++, cnt++;
            if(e > 15) e = 1;
            if(s > 28) s = 1;
            if(m > 19) m = 1;
            if(e == in_e && s == in_s && m == in_m) break;
       }
    }
    cout << cnt << '\n';
    return 0;
}
```
### 풀이 2
* 나머지를 이용하여 풀기 때문에 각 입력 값에 1을 빼준다. (e는 0~14, s는 0~27, m은 0~18)
* year을 0부터 시작한다.
* year % 15 == e, year % 28 == s, year % 19 == m 을 만족하는 year를 구한다. ( 1을 빼주었기에 1을 더한 값이 답이된다.)
```c++
#include <iostream>
using namespace std;
int main() {
    int e, s, m;
    cin >> e >> s >> m;
    e -= 1, s -= 1, m -= 1; // 나머지로 나올 수 있는 경우이기에 1을 빼준다.
    for(int i = 0; ; i++) {
        if(i % 15 == e && i % 28 == s && i % 19 == m) {
            cout << i+1 << '\n';
            break;
        }
    }
    return 0;
}
```
