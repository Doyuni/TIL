## 숨바꼭질4
[문제](https://www.acmicpc.net/problem/13913)
* [숨바꼭질](https://github.com/Doyuni/TIL/tree/master/Algorithm/baekjoon/BFS/1697)의 방식과 동일
* 차이점: 가장 빠른 시간으로 간 경로를 출력해야 한다.  
그렇기에 답이 여러 개일 수도 있다.
* 경로를 출력하기위해 path라는 배열을 만들어 이전 경로의 정보를 저장한다.  
path[next] = now  
3 -> 4 -> 5 가 경로라면  
path[5]는 4의 값을, path[4]는 3의 값을 갖는다.  
* stack을 이용해 도착지점부터 출발지점까지 경로를 쌓고 stack이 비어있을 때까지 출력한다.

```c++
#include <stack>
#include <queue>
#include <cstdio>
#define MAX 100000
using namespace std;
queue<int> q;
bool check[MAX+1];
int dist[MAX+1];
int path[MAX+1];
stack<int> ans;
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    q.push(n);
    check[n] = n;
    path[n] = n;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now - 1 >= 0) {
            if(check[now-1] == false) {
                check[now-1] = true;
                q.push(now-1);
                path[now-1] = now;
                dist[now-1] = dist[now] + 1;
            } 
        }
        if(now + 1 <= MAX) {
             if(check[now+1] == false) {
                check[now+1] = true;
                q.push(now+1);
                path[now+1] = now;
                dist[now+1] = dist[now] + 1;
            } 
        }
        if(now * 2 <= MAX) {
             if(check[now*2] == false) {
                check[now*2] = true;
                q.push(now*2);
                path[now*2] = now;
                dist[now*2] = dist[now] + 1;
            } 
        }
    }
    printf("%d\n", dist[k]);
    for(int i = k; i != n; i = path[i]) {
        ans.push(i);
    }
    ans.push(n);
    while(!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    printf("\n");
    return 0;
}
```
