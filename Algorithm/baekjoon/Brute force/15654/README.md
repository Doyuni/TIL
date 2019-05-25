## N과 M (5) [문제](https://www.acmicpc.net/problem/15654)
[N과 M (1)](../15649/README.md) 문제와 차이점은 수열을 이룰 숫자가 입력값으로 주어진다는 것이다.  
그렇기에 벡터를 새로 만들어 숫자를 입력받고, ans에 같은 방식으로 넣어주면 된다.

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
