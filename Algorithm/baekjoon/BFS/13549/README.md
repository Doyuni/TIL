## 숨바꼭질 3
[문제](https://www.acmicpc.net/problem/13549)
* [숨바꼭질](https://github.com/Doyuni/TIL/tree/master/Algorithm/baekjoon/BFS/1697)의 방식과 동일
* 차이점: 2*X의 위치로 이동할 때 비용이 0이다.  
* 2*X 탐색 분기문을 가장 위로 옮겨서 우선순위를 가장 높게 두고,  
원래 1초를 추가했던 비용을 0으로 수정한다.
```c++
#include <iostream>
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
        if(now * 2 <= MAX) { // "숨바꼭질"과 다른 부분: 가장 먼저 실행되게 한다.
             if(check[now*2] == false) {
                check[now*2] = true;
                q.push(now*2);
                dist[now*2] = dist[now]; // 0초가 걸린다.
            } 
        }
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
    }
    printf("%d\n", dist[k]);
    return 0;
}
```
