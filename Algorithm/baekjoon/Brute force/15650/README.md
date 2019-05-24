# N과 M (2) [문제](https://www.acmicpc.net/problem/15650)  
[N과 M (1)](../15649/README.md) 의 코드를 조금만 수정하면 된다.
이 코드에서 사용된 재귀함수가 어떤 방식으로 돌아가는지 이해한다면 이번 문제도 어렵지 않게 풀 수 있다.
- 차이점은 수열이 오름차순이라는 것이다.
- ans 벡터에 숫자를 넣기 전에, 벡터에 가장 최근에 넣은 숫자와 비교해야 한다.  
만약 넣을 숫자가 더 크다면 넣고, 그렇지 않다면 continue로 건너뛴다.
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
        if(index != 0) { // 추가 부분
            if(i+1 < ans[index-1]) continue;
        }
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
