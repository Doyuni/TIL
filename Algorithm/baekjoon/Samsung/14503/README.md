## 로봇 청소기

[문제링크](https://www.acmicpc.net/problem/14503)

### Problem

- N x M 크기, 벽 또는 빈칸, 모든 외곽은 벽
- 청소기는 바라보는 방향이 있음(상하좌우)
- 작동
1. 현재 위치 청소
2. 현재 방향을 기준으로 왼쪽부터 탐색
왼쪽에 청소하지 않은 공간이 있으면 그 방향으로 회전, 1칸 전진, 1번 진행
없다면, 그 방향으로 회전 2번 진행
상하좌우 모두 청소 되어 있거나 벽이라면, 방향 유지한 채 한 칸 후진 후 2번 진행 ( 현재 위치에서 4방향 다 청소나 벽일 때 현재 방향 유지한 채 후진)
바로 위의 경우에서 뒤쪽이 벽이라 후진도 못 하는 경우 **작동 종료**

**Goal: 로봇 청소기가 청소하는 칸의 개수 출력**

방향: 0 → 위, 1 → 우, 2 → 아래, 3 → 왼

### Solution

시뮬레이션 문제이다. 각 순서에 맞게 잘 구현하면 된다.

1. 현재 탐색 지점의 값이 0이라면 청소하는 칸의 개수 1 증가 후 2로 표시
2. 최대 5번 방향을 바꾸게 된다. (자신으로 돌아오는 것까지 포함)
- 0(위쪽) → 3(왼쪽)
- 1(오른쪽) → 0(위쪽)
- 2(아래쪽) → 1(오른쪽)
- 3(왼쪽) → 2(아래쪽)

위는 현재 방향에 따른 왼쪽 방향(다음 탐색 방향)이다.

현재 방향을 토대로 다음 방향을 결정하고 다음 방향에 맞는 좌표를 구한다.

- 탐색 가능하면(값이 0이면) 현재 방향을 이 방향으로 바꾸고 좌표를 바꾸고 반복문 종료
- 탐색 불가능하면 현재 방향만 이 방향으로 바꾼다.
- 처음 방향과 같게 나오면(5번째일 경우) 후진이 가능한지 조사한다.
가능하면 좌표만 바꿔주고 아니면 시뮬레이션을 종료한다.
```c++
    for (int i = 0; i < 5; ++i) {
    			int next_dir = left_dir[current_dir];
    			if (i == 4) {
    				int back_x = x + dx[back_dir[dir]];
    				int back_y = y + dy[back_dir[dir]];
    				if (map[back_x][back_y] == 1) return;
    				else {
    					x = back_x; y = back_y;
    					break;
    				}
    			}
    			int d_x = x + dx[next_dir];
    			int d_y = y + dy[next_dir];
    			if (map[d_x][d_y] == 0) {
    				dir = next_dir;
    				x = d_x; y = d_y;
    				break;
    			}
    			else {
    				current_dir = next_dir;
    			}
    }
```
### 1 Try
```c++
    #include <iostream>
    using namespace std;
    int n, m, ans;
    int map[51][51];
    int left_dir[4] = { 3, 0, 1, 2 };
    int back_dir[4] = { 2, 3, 0, 1 };
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    bool isBound(int x, int y) {
    	if (x > -1 && y > -1 && x < n && y < m) return true;
    	return false;
    }
    void cleanMap(int x, int y, int dir) {
    	while (true) {
    		if (map[x][y] == 0) ans++;
    		map[x][y] = 2;
    		int current_dir = dir;
    		for (int i = 0; i < 5; ++i) {
    			int next_dir = left_dir[current_dir];
    			if (i == 4) {
    				int back_x = x + dx[back_dir[dir]];
    				int back_y = y + dy[back_dir[dir]];
    				if (map[back_x][back_y] == 1) return;
    				else {
    					x = back_x; y = back_y;
    					break;
    				}
    			}
    			int d_x = x + dx[next_dir];
    			int d_y = y + dy[next_dir];
    			if (map[d_x][d_y] == 0) {
    				dir = next_dir;
    				x = d_x; y = d_y;
    				break;
    			}
    			else {
    				current_dir = next_dir;
    			}
    		}	
    	}
    }
    int main() {
    	int start_x, start_y, dir;
    	cin >> n >> m;
    	cin >> start_x >> start_y >> dir;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			cin >> map[i][j];
    		}
    	}
    	cleanMap(start_x, start_y, dir);
    	cout << ans << "\n";
    	return 0;
    }
```
