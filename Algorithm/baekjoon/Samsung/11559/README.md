[블로그](https://www.notion.so/doyuni/11559-Puyo-Puyo-393a3fad7530416fa6adcd8d816c3687)

## Puyo Puyo

[문제링크](https://www.acmicpc.net/problem/11559)

### Problem

- 뿌요는 바닥이나 다른 뿌요가 있을 때까지 아래로 떨어짐
- 뿌요가 놓여지고 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면
연결된 같은 색 뿌요들이 모두 사라진다.
- 위 과정이 반복되면 1연쇄씩 늘어난다. (터지는 그룹이 동시에 여럿이라도 1연쇄)

입력

    12*6의 문자
    .은 빈공간
    이외 뿌요 색깔 R, G, B, P, Y
    뿌요들이 전부 아래로 떨어진 뒤의 상태가 주어짐

**Goal: 몇 연쇄가 되는지 출력, 안터지면 0 출력**

### Solution

다음과 같은 과정이 일어난다.

1. 현재 map에서 터뜨릴 수 있는 것들 터뜨리기
2. 아래로 떨어뜨리기
3. 위 과정 반복하기(더이상 터뜨릴 수 없는 경우 종료)
- 터뜨리기

BFS를 활용하여 4개 이상 연속인지 확인을 한다.

    void bfs(현재 위치)
    	탐색용도 queue와 지울(터뜨릴)용도 queue 선언
    	현재 위치 넣어주고, check
    	탐색용도 queue를 전부 비울 때까지 탐색
    	탐색이 끝나면(더이상 갈 때가 없는 것)
    	지울 용도의 queue 크기가 4이상이면 터뜨리기

- bfs 탐색이 끝나면 다음과 같이 4개 연속인 것들 터뜨리기

    void changeMap(queue<pair<int, int>> &erase) {
    	while (!erase.empty()) {
    		int r = erase.front().first;
    		int c = erase.front().second;
    		erase.pop();
    		map[r][c] = '.';
    	}
    }

이 과정이 모든 map의 각 행과 열에서 이루어지면 그때 아래로 떨어뜨린다.
(모든 위치에서 BFS탐색이 끝난 경우)

- 아래로 떨어뜨리기
1. Queue를 이용하여 맨 아래에서 부터 위로 탐색을 시작하여 **.** 인 지점을 순서대로 넣어준다.
2. . 이 아니라면 queue에 들어간 순서대로 위치를 교환한다.

    void update() {
    	for (int i = 0; i < 6; ++i) {
    		queue<pair<int, int>> point;
    		for (int j = 11; j >= 0; --j) {
    			if (map[j][i] == '.') point.push({ j, i });
    			else {
    				if (point.empty()) continue;
    				int x = point.front().first;
    				int y = point.front().second;
    				point.pop();
    				map[x][y] = map[j][i];
    				map[j][i] = '.';
    				point.push({ j, i });
    			}
    		}
    	}
    }

### 1 Try

- 틀린 코드

DFS로 하니까 map에서 연속인 것들을 제대로 지우지 못 한다는 것을 깨닫고
(실제 값 확인해보면 erase queue에 연속적으로 못 넣고 return하게 됨)

BFS를 사용하여 쉽게 풀었다..(진작에 할걸)

### 2 Try
```c++
    #include <cstdio>
    #include <cstring>
    #include <queue>
    using namespace std;
    char map[12][6];
    bool check[12][6];
    bool loop = true;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    bool isBound(int r, int c) {
    	if (r > -1 && c > -1 && r < 12 && c < 6) return true;
    	return false;
    }
    void update() {
    	for (int i = 0; i < 6; ++i) {
    		queue<pair<int, int>> point;
    		for (int j = 11; j >= 0; --j) {
    			if (map[j][i] == '.') point.push({ j, i });
    			else {
    				if (point.empty()) continue;
    				int x = point.front().first;
    				int y = point.front().second;
    				point.pop();
    				map[x][y] = map[j][i];
    				map[j][i] = '.';
    				point.push({ j, i });
    			}
    		}
    	}
    }
    void changeMap(queue<pair<int, int>> &erase) {
    	while (!erase.empty()) {
    		int r = erase.front().first;
    		int c = erase.front().second;
    		erase.pop();
    		map[r][c] = '.';
    	}
    }
    void bfs(int r, int c){
    	queue<pair<int, int>> q, erase;
    	q.push({ r, c });
    	erase.push({ r, c });
    	check[r][c] = true;
    	while (!q.empty()) {
    		int length = q.size();
    		for (int i = 0; i < length; ++i) {
    			r = q.front().first;
    			c = q.front().second;
    			q.pop();
    			for (int j = 0; j < 4; ++j) {
    				int x = r + dx[j];
    				int y = c + dy[j];
    				if (isBound(x, y) && !check[x][y] && map[x][y] == map[r][c] && map[x][y] != '.') {
    					check[x][y] = true;
    					q.push({ x, y });
    					erase.push({ x, y });
    				}	
    			}
    		}
    	}
    	if (erase.size() >= 4) {
    		loop = true;
    		changeMap(erase);
    	}
    }
    int main() {
    	for (int i = 0; i < 12; ++i) {
    		for (int j = 0; j < 6; ++j) {
    			scanf(" %c", &map[i][j]);
    		}
    	}
    	int answer = 0;
    	while (loop) {
    		loop = false;
    		memset(check, 0, sizeof(check));
    		for (int i = 0; i < 12; ++i) {
    			for (int j = 0; j < 6; ++j) {
    				if (map[i][j] != '.' && !check[i][j]) {
    					bfs(i, j);
    				}
    			}
    		}
    		if (loop) {
    			update();
    			answer++;
    		}
    	}
    	printf("%d\n", answer);
    	return 0;
    }
```
### Debug

- 디버깅용 코드
- 디버깅용 Test case

#1. output : 14

    Y.....
    B.....
    R.R...
    G.R...
    YG....
    YBR..Y
    RR...Y
    YYRBRB
    YRBGBB
    GBRBGR
    GBRBGR
    GBRBGR

#2. output : 1

    ......
    ......
    ......
    ......
    ......
    ......
    ......
    ......
    R.....
    ......
    RRYYGG
    RRYYGG

#3. output: 2

    ......
    ..R...
    ..R.GG
    ...GG.
    ..R...
    ......
    ..R...
    ......
    R.....
    ....G.
    RRY..G
    RRYYGG
