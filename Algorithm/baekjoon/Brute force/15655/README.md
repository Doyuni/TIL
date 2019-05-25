## N과 M (6) [문제](https://www.acmicpc.net/problem/15655)
[N과 M (5)](../15654/README.md) 문제와 차이점은 수열이 오름차순이어야 한다.  
그렇기에 넣으려는 숫자(num[i])와 가장 최근에 넣은 숫자(ans[index-1])을 비교해야 한다.

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> check, ans, num;
void doSequence(int index) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(check[i]) continue;
        if(index != 0) {
            if(num[i] < ans[index-1]) continue;
        }
        check[i] = 1; 
        ans[index] = num[i]; 
        doSequence(index+1);
        check[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    num.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    check.resize(n);
    ans.resize(m);
    doSequence(0);
    return 0;
}
```
