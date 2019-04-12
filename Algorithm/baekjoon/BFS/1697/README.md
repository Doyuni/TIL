## 숨바꼭질 
* N에서 K로 가는 가장 빠른 시간을 구하는 문제 -> 최단 거리 문제
* N에서 다음 정점으로 가는 비용은 1(초)로 최소 시간을 구하는 것과 일치한다.   
-> BFS로 풀어야 한다.
* 정점은 최대 100000으로 시간 제한을 넘지 않는다.
* BFS 방식으로 풀되, dist[i]라는 배열을 두어  i번 노드로 가는 최소 시간을 저장한다.  
하나의 방법으로 갈 수 있을 때 dist[next] = dist[now] + 1 이다.  
다음 정점으로 가는 비용이 1초이기 때문이다.
```c++
#include <vector>
#include <queue>
#include <cstdio>
#define MAX 100000
using namespace std;
queue<int> q;
bool check[MAX+1];
int dist[MAX+1];
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    q.push(n);
    check[n] = n;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now - 1 >= 0) {
            if(check[now-1] == false) {
                check[now-1] = true;
                q.push(now-1);
                dist[now-1] = dist[now] + 1;
            } 
        }
        if(now + 1 <= MAX) {
             if(check[now+1] == false) {
                check[now+1] = true;
                q.push(now+1);
                dist[now+1] = dist[now] + 1;
            } 
        }
        if(now * 2 <= MAX) {
             if(check[now*2] == false) {
                check[now*2] = true;
                q.push(now*2);
                dist[now*2] = dist[now] + 1;
            } 
        }
    }
    printf("%d\n", dist[k]);
    return 0;
}
```
