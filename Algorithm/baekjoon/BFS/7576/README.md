## 토마토
[문제](https://www.acmicpc.net/problem/7576)
- 입력값이 1인 경우 queue에 push(첫 BFS탐색을 위함)
- 입력값이 -1인 경우 visited를 true로 해주어 예외처리에 사용한다. (check 함수)
- 가능한 최대 루프는 모든 지점을 탐색했을 경우이다. n x m
  - 최대 루프 내에서 queue의 절반 크기(2차원 배열 인덱스 정보를 넣어주기 때문)만큼 반복을 실행한다.
    1. 탐색 시점을 정하기 위해 queue에서 pop을 한다.
    2. 탐색 시점으로부터 상하좌우 중 이동 가능한지 확인한다. ( 탐색할 지점이 0이고 방문하지 않았어야 한다.)
    3. 이동 가능하다면 탐색했다는 표시를 한 후, queue에 push 
  - 만일 queue가 비어있다면, 더이상 탐색할 지점이 없기에 루프를 종료한다.
  - 그렇지 않다면 루프가 계속 진행되고 일 수를 카운트한다.
- 모든 루프가 끝나면 check 함수를 통해 탐색 가능한 모든 지점을 방문했는지 확인한다. (토마토를 모두 탐색했는지)  
방문하지 않은 지점이 존재하면 -1을 출력한다.

```c++
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000
int visited[MAX][MAX];
int v[MAX][MAX];
queue<int> q;
int answer;
int direction[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
bool check(int n, int m) {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(visited[i][j] == false) return false;
        }
    }
    return true;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> v[i][j];
            if(v[i][j] == 1) {
                q.push(i);
                q.push(j);
                visited[i][j] = true;
            } else if(v[i][j] == -1) {
                visited[i][j] = true;
            }
        }
    }
    int max_total = n*m;
    while(max_total--) {
        int loop = q.size() / 2;
        while(loop--) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            for(int i = 0; i < 4; ++i) {
                int x_m = x - direction[i][0];
                int y_m = y - direction[i][1];
                if(x_m > -1 && x_m < m && y_m > -1 && y_m < n) {
                    if(visited[x_m][y_m] == false && v[x_m][y_m] == 0) {
                        visited[x_m][y_m] = true;
                        v[x_m][y_m] = 1;
                        q.push(x_m);
                        q.push(y_m);
                    }
                }   
            }
        }
        if(q.empty()) {
            break;
        }
        answer++;
    }
    if(check(n, m)) {
        cout << answer << endl;
    } else cout << -1 << endl;
	return 0;
}
```
