## 날짜 계산
[문제](https://www.acmicpc.net/problem/1476)
* 직관적으로 푼다.
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
