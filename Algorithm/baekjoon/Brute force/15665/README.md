## N과 M (11) [문제](https://www.acmicpc.net/problem/15665)  
- [N과 M (9)](../15663/README.md) 코드에서 check 부분을 모두 지워주면 된다. (같은 수를 여러 번 골라도 되기에)


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
``
