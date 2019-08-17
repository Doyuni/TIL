## 뱀
[문제링크](https://www.acmicpc.net/problem/3190)

### Problem

- N x N 보드판
- 양 끝 모서리에 벽이 있음
- 뱀의 길이 1, 시작 위치 (1, 1), 방향: →
- 매 초마다 이동
1. 머리를 다음 칸에 위치
2. 이동한 칸에 사과가 있으면 사과 먹고 꼬리 움직이지 않음(몸길이 늘어남)
3. 꼬리 움직인다. (몸길이 그대로)

**Goal: 사과의 위치와 뱀의 이동경로가 주어질 때 게임이 몇 초만에 끝나는지 계산**

게임은 벽이나 자기자신의 몸과 부딪히면 끝난다.

뱀의 이동 경로는 (왼쪽 오른쪽 으로 90도 방향 회전)

- 입력

방향 변환 정보에서 주어진 초는 게임 시작 시간으로부터 X초가 끝난 뒤를 말한다.

### Solution

- 주어진 문제대로 구현하면 된다. (시뮬레이션)
- 방향전환 시간은 오름차순으로 주어지기에 queue에 저장
- 사과가 있는 곳은 -1로 표시
- 뱀이 있는 곳은 1부터~현재 길이까지 표시 (머리가 가장 큰 수)
1. 머리를 기준으로 현재 방향에 맞게 움직인다.
2. 머리가 움직였을 때 그곳이 벽이거나 자신의 몸인지 확인한다.
필자는 다음과 같은 경우에 뱀이 동시에 움직일거라 생각하여 게임이 안끝난다고 생각했다.
```
    // 4가 머리이고 머리가 위쪽으로 가는 경우일 때
    1 2  ->  4 1
    4 3      3 2
```
하지만 동시에 움직이지 않고 머리부터 움직여서 꼬리가 따라온다. 그렇기에 위와 같은 경우는 게임이 종료된다.

  3.  방향 전환 시간인지 확인한다.
해당 경우에 맞게 방향을 변경한다.

  4.  사과가 있는지 확인한다.
사과가 있으면 길이가 1 늘어나고 이동하지 않는다.

  5.  이동한다.
이동방법: 머리에서부터 시작해서 자신보다 1 적은 수를 찾는다. 찾으면 그 값을 넣는다. 이를 총 길이-1만큼 반복하고(머리를 제외하기 때문) 다음 탐색 부분에 머리를, 원래 꼬리 부분을 0으로 변경해준다.

    1 2 3 4   -->    1 1 2 3   -->   0 1 2 3
          5                4             5 4

### 1 Try
```c++
    #include <cstdio>  
    #include <queue>
    using namespace std;
    int n, k, l;
    int board[101][101];
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int d_left[4] = { 2, 3, 1, 0 }; // 'L'
    int d_right[4] = { 3, 2, 0, 1 }; // 'D'
    queue<pair<int, char> > direction;
    bool isWall(int x, int y) { // 벽이면 true
    	if (x < 1 || y < 1 || x > n || y > n) return true;
    	return false;
    }
    bool isBound(int x, int y) {
    	if (x > 0 && y > 0 && x <= n && y <= n) return true;
    	return false;
    }
    int game() {
    	int x = 1; int y = 1; // 시작위치
    	int dir = 3; // 시작방향: 오른쪽
    	int len = 1; // 뱀의 길이
    	int time = 0; // 게임 시작 시간
    	board[x][y] = 1;
    	while (true) {
    		int convert = 0;
    		if (!direction.empty()) {
    			convert = direction.front().first;
    		}
    		time++;
    		// 현재 방향에 맞는 한 칸 이동
    		int d_x = x + dx[dir];
    		int d_y = y + dy[dir];
    		// 벽인지 자신의 몸인지 확인
    		if (isWall(d_x, d_y) || board[d_x][d_y] > 0) return time;
    		// 방향 전환 시간인지 확인
    		if (time == convert) {
    			if (direction.front().second == 'D') {
    				dir = d_right[dir];
    			}
    			else {
    				dir = d_left[dir];
    			}
    			direction.pop();
    		}
    		// 사과 있는지 확인
    		if (board[d_x][d_y] == -1) {
    			board[d_x][d_y] = ++len;
    			x = d_x; y = d_y;
    			continue;
    		}
    		// 이동
    		int tmp_x = x, tmp_y = y;
    		for (int i = 1; i < len; ++i) {
    			for (int j = 0; j < 4; ++j) {
    				int d_tmp_x = tmp_x + dx[j];
    				int d_tmp_y = tmp_y + dy[j];
    				if (isBound(d_tmp_x, d_tmp_y)) {
    					if (board[d_tmp_x][d_tmp_y] == board[tmp_x][tmp_y] - 1) {
    						board[tmp_x][tmp_y] = board[d_tmp_x][d_tmp_y];
    						tmp_x = d_tmp_x; tmp_y = d_tmp_y;
    						break;
    					}
    				}
    			}
    		}
    		board[d_x][d_y] = len;
    		board[tmp_x][tmp_y] = 0;
    		x = d_x;
    		y = d_y;
    	}
    }
    int main() {
    	scanf("%d %d", &n, &k);
    	for (int i = 0; i < k; ++i) {
    		int r, c;
    		scanf("%d %d", &r, &c);
    		board[r][c] = -1;
    	}
    	scanf("%d", &l);
    	for (int i = 0; i < l; ++i) {
    		int x; char dir;
    		scanf("%d %c", &x, &dir);
    		direction.push({ x, dir });
    	}
    	printf("%d\n", game());
    	return 0;
    }
```
