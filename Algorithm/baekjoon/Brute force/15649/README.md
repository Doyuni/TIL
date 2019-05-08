## N과 M (1)
[문제](https://www.acmicpc.net/problem/15649)
- **재귀함수**를 이용하여 해결한다.
- for문에서 i = 0부터 시작하여 나머지 구할 수 있는 경우를 모두 구한다.  
예를들어, n=3, m=3인 경우 i = 0부터 시작으로 1 _ _ 의 수열을 보인다.  
이때 _ _ 는 2 3 or 3 2인 경우가 있고, 더이상 경우의 수가 없으면 check를 false로 하여 다시 index = 0 으로 돌아오는 구조이다. 돌아오면 i = 1이 되고 2 _ _ 의 수열을 구하기 시작한다.
- 직접 손으로 호출 순서를 그려가며 이해하는 것이 좋다.
```c++
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> check, ans;
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
        check[i] = 1; ans[index] = i+1;
        doSequence(index+1);
        check[i] = 0;
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
