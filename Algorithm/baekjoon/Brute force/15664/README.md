## N과 M (10) [문제](https://www.acmicpc.net/problem/15664)
- [N과 M (9)](../15663/README.md) 코드에서 비내림차순(오름차순 + 같은 수) 조건만 추가하면 된다.
- 넣어야 할 숫자가 가장 최근에 넣은 숫자보다 크거나 같으면 된다.
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000
using namespace std;
int n, m;
vector<int> check, ans, num;
int cnt[MAX+1];
void doSequence(int index) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < num.size(); ++i) {
        if(check[i] == 0) continue;
        if(index != 0) {
            if(num[i] < ans[index-1]) continue;
        }
        if(cnt[num[i]] > 0) check[i]--; 
        ans[index] = num[i]; 
        doSequence(index+1);
        check[i]++;
    }
}
int main() {
    int number;
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> number;
        cnt[number]++;
        if(cnt[number] == 1) {
            num.push_back(number);
        }
    }
    sort(num.begin(), num.end());
    check.resize(n);
    for(int i = 0; i < num.size(); ++i) {
        check[i] = cnt[num[i]];
    }
    ans.resize(m);
    doSequence(0);
    return 0;
}
```
