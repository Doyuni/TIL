## N과 M (3) [문제](https://www.acmicpc.net/problem/15651)
[N과 M (1)](../15649/README.md) 문제와 차이점은 "같은 수를 여러 번 골라도 된다." 이다.  
N과 M (1) 코드에서 같은 수를 고르는걸 방지하기 위해 사용되었던 check를 사용하지 않으면 된다.


```c++
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> ans;
void doSequence(int index) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; ++i) {
        ans[index] = i+1;
        doSequence(index+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    check.resize(n); 
    ans.resize(m);
    doSequence(0);
    return 0;
}
```
