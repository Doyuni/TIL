## N과 M (12) [문제](https://www.acmicpc.net/problem/15666)
- [N과 M (11)](../15665/README.md) 코드에서 비내림차순 조건만 추가하면 된다.
- 넣을 숫자가 가장 최근에 넣은 숫자보다 크거나 같을 때만 넣을 수 있도록 한다.
- 이것으로 N과 M 시리즈를 **마친다**.
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000
using namespace std;
int n, m;
vector<int> ans, num;
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
        if(index != 0) {
            if(num[i] < ans[index-1]) continue;
        }
        ans[index] = num[i]; 
        doSequence(index+1);
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
    ans.resize(m);
    doSequence(0);
    return 0;
}
```
