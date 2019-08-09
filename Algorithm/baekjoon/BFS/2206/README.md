[문제풀이](https://www.notion.so/doyuni/2206-2f3a942812b24d6b95069c9f9fa7413f)

## 벽 부수고 이동하기
[문제링크](https://www.acmicpc.net/problem/2206)

### Problem

- N x M 크기의 맵
- 0은 이동가능 1은 벽을 나타냄
- (0, 0) → (N-1, M-1)까지 이동 (상하좌우)
- 벽을 1개까지 부수고 이동 가능

**Goal: (0, 0)에서 (N-1, M-1)까지 이동하는데 걸리는 경로 중 최단 경로 구하기**

### Solution

- 이동하기

시작지점(0, 0)에서부터 상하좌우로 갈 수 있는 방향을 탐색한다. 
도착지점까지 모든 곳을 탐색해야 하며, 이때 BFS를 사용한다.
현재 지점에서 상하좌우로 가는데 걸리는 비용이 동일하기 때문이다.

- 벽을 부수었는지 여부를 경로를 갱신할 때마다 가지고 있어야 한다.

탐색할 때 이미 값이 있다면 이미 지나온 경로이므로 다른 지점을 탐색해야 한다. 그외는 다음을 확인하고 경로를 갱신한다.

1. 탐색할 지점이 0이라면 경로 갱신
2. 탐색할 지점이 1인데 이전까지 벽을 부수지 않았다면 경로 갱신

위와 같은 작업으로 문제를 해결할 수 있다.

### 1 Try
```c++
    #include <cstdio>
    #include <queue>
    #define MAX 1001
    using namespace std;
    int n, m;
    int map[MAX][MAX];
    int path[MAX][MAX][2];
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    struct INFO {
    	int r, c;
    	bool break_wall = false;
    };
    int bfs() {
    	queue<INFO> q;
    	q.push({ 0, 0, false });
    	path[0][0][0] = 1;
    	while (!q.empty()) {
    		int r = q.front().r; int c = q.front().c;
    		bool bw = q.front().break_wall;
    		q.pop();
    		if (r == n - 1 && c == m - 1) return path[r][c][bw];
    		for (int i = 0; i < 4; ++i) {
    			int x = r + dx[i];
    			int y = c + dy[i];
    			if (x > -1 && y > -1 && x < n && y < m) {
    				if (path[x][y][bw]) continue;
    				if (map[x][y] == 0) {
    					path[x][y][bw] = path[r][c][bw] + 1;
    					q.push({ x, y, bw });
    				}
    				else if(map[x][y] == 1 && bw == 0) {
    					path[x][y][1] = path[r][c][bw] + 1;
    					q.push({ x, y, true });
    				}
    			}
    		}
    	}
    	return -1;
    }
    int main() {
    	scanf("%d %d", &n, &m);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			scanf("%1d", &map[i][j]);
    		}
    	}
    	printf("%d\n", bfs());
    	return 0;
    }
```
