## 숨바꼭질 2
* [숨바꼭질](https://github.com/Doyuni/TIL/tree/master/Algorithm/baekjoon/BFS/1697)의 방식과 동일
* 차이점: 최소 시간으로 가는 방법이 몇 가지인지 구해야 한다.
* 다른 방법으로 같은 노드에 접근하는 경우를 생각해주어야 한다.  

예를 들어 1 -> 4로 가는 경우  
1->0, 1->2, 1->2로 갈 수 있다.   
이 경우 중간에 있는 2와 마지막에 있는 2로 가는 방법은 다른 방법이기에,  
마지막에 있는 2에서도 탐색을 계속 해주어야 한다.

```c++
#include <vector>
#include <queue>
#include <cstdio>
#define MAX 100000
using namespace std;
queue<int> q;
bool check[MAX+1];
int dist[MAX+1];
int way[MAX+1];
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
            // 방문하지 않은 경우 or 방법이 다르지만 같은 시간으로 간 경우
            if(check[now-1] == false || dist[now-1] == dist[now] + 1) {
                check[now-1] = true;
                q.push(now-1);
                if(dist[now-1] == 0) { // 방문하지 않은 경우
                    dist[now-1] = dist[now] + 1;
                } else { // 방문했지만 다른 방법으로 같은 시간에 간 경우
                    way[now-1]++;
                }
            } 
        }
        if(now + 1 <= MAX) {
             if(check[now+1] == false || dist[now+1] == dist[now] + 1) {
                check[now+1] = true;
                q.push(now+1);
                if(dist[now+1] == 0) {
                    dist[now+1] = dist[now] + 1;
                } else {
                    way[now+1]++;
                }
            } 
        }
        if(now * 2 <= MAX) {
             if(check[now*2] == false || dist[now*2] == dist[now] + 1) {
                check[now*2] = true;
                q.push(now*2);
                if(dist[now*2] == 0) {
                    dist[now*2] = dist[now] + 1;
                } else {
                    way[now*2]++;
                }
            } 
        }
    }
    printf("%d\n", dist[k]);
    printf("%d\n", way[k]+1);
    return 0;
}
```
