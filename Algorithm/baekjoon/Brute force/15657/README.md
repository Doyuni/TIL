## N과 M (8) [문제](https://www.acmicpc.net/problem/15657)
N과 M (7) 문제의 조건에서 비내림차순 조건이 추가된 문제이므로  
[N과 M (7)](../15656/README.md) 코드에 넣을 숫자가 가장 최근에 넣은 숫자보다 작으면 넣지 않도록  
조건문을 추가하면 된다.


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
        if(index != 0) {
            if(num[i] < ans[index-1]) continue;
        }
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
