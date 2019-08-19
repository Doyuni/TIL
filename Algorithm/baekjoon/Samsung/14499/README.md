[문제풀이](https://www.notion.so/doyuni/14499-bc8362de50d14fffa71f430057124020)

## 주사위 굴리기

[문제링크](https://www.acmicpc.net/problem/14499)

### Problem

- N x M 지도 위에 주사위 하나
- 오른쪽(동), 위쪽(북)
- 주사위 위치는 (x, y) 모든 면에 0 적혀 있음
- 지도에는 정수가 쓰여있고 
주사위가 이동한 칸에 쓰여 있는 수가 0이면 주사위 바닥면 수가 지도로 복사
0이 아니면 지도위에 쓰여 있는 수가 주사위 바닥면으로 복사, 지도에 쓰여 있는 수는 0이 된다.

**Goal: 주사위가 이동했을 때마다 주사위의 윗 면에 쓰여 있는 수를 출력
범위를 벗어나는 명령이면 움직이지 않고 출력도 하지 않는다.**

1: 오른쪽, 2: 왼쪽, 3: 위쪽, 4: 아래쪽으로 이동한다.

### Solution

- 주사위 6면의 정보를 가지고 있어야 한다.
```c++
    struct INFO {
    	int up = 0, down = 0, front = 0, back = 0, left = 0, right = 0;
    	int x, y;
    }dice;
    // 윗면, 아랫면, 앞면, 뒷면, 왼면, 오른면
```
- 주사위를 움직일 때 6면의 정보가 방향에 맞게 업데이트 되어야 한다.

먼저 범위를 검사하고 검사한 후에 주사위 위치를 변경해준다.

1. 오른쪽 이동
위 → 오른 → 아래 → 왼 → 위
2. 왼쪽 이동
위 → 왼 → 아래  → 오른 → 위
3. 위쪽 이동
위 → 뒤 → 아래 → 앞 → 위
4. 아래쪽 이동
위 → 앞 → 아래 → 뒤 → 위

값을 제대로 업데이트 하기 위해서 사이클이 시작되기 전 값을 저장해놓고 순서대로 덮어씌우는 방식으로 값을 갱신한다.
```c++
    void moveDice(int dir) {
    	int d_x = dice.x + dx[dir - 1];
    	int d_y = dice.y + dy[dir - 1];
    	if (isBound(d_x, d_y)) {
    		dice.x = d_x; dice.y = d_y;
    		int tmp = 0;
    		if (dir == 1) { // right
    			tmp = dice.left;
    			dice.left = dice.down;
    			dice.down = dice.right;
    			dice.right = dice.up;
    			dice.up = tmp;
    		}
    		else if (dir == 2) { // left
    			tmp = dice.right;
    			dice.right = dice.down;
    			dice.down = dice.left;
    			dice.left = dice.up;
    			dice.up = tmp;
    		}
    		else if (dir == 3) { // up
    			tmp = dice.front;
    			dice.front = dice.down;
    			dice.down = dice.back;
    			dice.back = dice.up;
    			dice.up = tmp;
    		}
    		else if (dir == 4) { // down
    			tmp = dice.back;
    			dice.back = dice.down;
    			dice.down = dice.front;
    			dice.front = dice.up;
    			dice.up = tmp;
    		}
    }
```
- 움직였을 때
    - 지도의 칸이 0이면, 주사위 바닥면 수 → 지도
    - 지도의 칸이 0이 아니면, 지도 → 주사위 바닥면 수 &  0 → 지도
```c++
    if (map[dice.x][dice.y] == 0) map[dice.x][dice.y] = dice.down;
    else {
    		dice.down = map[dice.x][dice.y];
    		map[dice.x][dice.y] = 0;
    }
    cout << dice.up << "\n"; // 윗면 출력
```
### 1 Try
```c++
    #include <iostream>
    #include <vector>
    using namespace std;
    int n, m;
    vector<vector<int> > map;
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
    struct INFO {
    	int up = 0, down = 0, front = 0, back = 0, left = 0, right = 0;
    	int x, y;
    }dice;
    bool isBound(int x, int y) {
    	if (x > -1 && y > -1 && x < n && y < m) return true;
    	return false;
    }
    void moveDice(int dir) {
    	int d_x = dice.x + dx[dir-1];
    	int d_y = dice.y + dy[dir-1];
    	if (isBound(d_x, d_y)) {
    		dice.x = d_x; dice.y = d_y;
    		int tmp = 0;
    		if (dir == 1) { // right
    			tmp = dice.left;
    			dice.left = dice.down;
    			dice.down = dice.right;
    			dice.right = dice.up;
    			dice.up = tmp;
    		}
    		else if (dir == 2) { // left
    			tmp = dice.right;
    			dice.right = dice.down;
    			dice.down = dice.left;
    			dice.left = dice.up;
    			dice.up = tmp;
    		}
    		else if (dir == 3) { // up
    			tmp = dice.front;
    			dice.front = dice.down;
    			dice.down = dice.back;
    			dice.back = dice.up;
    			dice.up = tmp;
    		}
    		else if (dir == 4) { // down
    			tmp = dice.back;
    			dice.back = dice.down;
    			dice.down = dice.front;
    			dice.front = dice.up;
    			dice.up = tmp;
    		}
    		if (map[dice.x][dice.y] == 0) map[dice.x][dice.y] = dice.down;
    		else {
    			dice.down = map[dice.x][dice.y];
    			map[dice.x][dice.y] = 0;
    		}
    		cout << dice.up << "\n";
    	}
    }
    int main() {
    	int start_x, start_y, k, dir;
    	cin >> n >> m >> start_x >> start_y >> k;
    	dice.x = start_x; dice.y = start_y;
    	map.resize(n);
    	for (int i = 0; i < n; ++i) {
    		map[i].resize(m);
    		for (int j = 0; j < m; ++j) {
    			cin >> map[i][j];
    		}
    	}
    	for (int i = 0; i < k; ++i) {
    		cin >> dir;
    		moveDice(dir);
    	}
    	return 0;
    }
```
