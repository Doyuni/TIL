## N과 M (7) [문제](https://www.acmicpc.net/problem/15656)
[N과 M (5)](../15654/README.md) 문제와 차이점은 같은 수를 여러 번 골라도 된다는 것이다.    
그렇기에 N과 M (5) 코드에서 check 부분을 지워주면 된다.  

```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<int> ans, num;
void doSequence(int index) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; ++i) {
        ans[index] = num[i]; 
        doSequence(index+1);
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
    ans.resize(m);
    doSequence(0);
    return 0;
}
```
