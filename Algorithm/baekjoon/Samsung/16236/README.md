## 아기 상어
[문제링크](https://www.acmicpc.net/problem/16236)

### Problem

- N x N 공간
- 물고기 M, 아기 상어 1마리 (1칸에 최대 1마리)
- 아기 상어 처음 크기 : 2, 물고기도 크기 존재
- 아기 상어 움직임 (1초마다 상하좌우)
자신보다 큰 물고기 있는 칸은 못 감 나머진 이동 가능
자신보다 작은 물고기만 먹을 수 있고, 크기가 같다면 지나가는건 가능
- 자신의 크기만큼 물고기를 먹어야 크기가 1 증가한다.
- 상어가 이동할 곳 결정 방법
    - 더 이상 먹을 물고기가 없으면 종료
    - 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹는다. (여기부터 이동)
    - 1마리보다 많다면, 거리가 가장 가까운 물고기부터 먹는다.
        - 가장 가까운 물고기가 여럿이면 가장 위
        - 그런 물고기가 또 여럿이면 가장 왼쪽에 있는 물고기를 먹는다.

**Goal: 종료되는 시간은?**

- 입력

    0: 빈 칸
    1~6: 물고기 크기
    9: 아기 상어

### Solution

- 입력값 다루기

    struct shark {
    	int r, c, size, cnt= 0;
    }baby;

아기 상어의 위치, 크기, 먹은 수를 저장할 수 있도록 구조체를 만든다.

- 다음 작업이 반복된다.
1. 먹이를 찾기
2. 찾았다면 그 중 규칙에 따라 먹이 선택하기
- **먹이 찾기**
1. 탐색할 queue와 먹을 수 있는 물고기를 저장할 queue가 필요하다.
2. 탐색 지점의 표시를 위해 check 배열이 필요하다.
3. 아기 상어가 이동한 후 다음 먹이까지 찾아가는데 걸리는 시간을 따로 저장해야 한다. (`part_time`)
4. 탐색할 지점은 경계를 넘지 않고 아기 상어 크기보다 작거나 같고 탐색표시가 안된 지점이다.
    - 탐색이 가능할 때
    1. 탐색 표시를 하고 탐색 queue에 넣어준다.
    2. 아기 상어 크기보다 작은 물고기라면 먹이 queue에 넣어준다.
5. 1초간 갈 수 있는 탐색이 끝나면 먹이 queue가 비어있는지를 판단한다.
    1. 먹이 queue에 먹이가 들어있으면 걸린 시간(`part_time`)을 더해준다.
    2. 먹이를 선택한다.
```c++
    void findPrey(int row, int col) {
    	queue<pair<int, int>> q, prey;
    	q.push({ row, col });
    	memset(check, 0, sizeof(check));
    	check[row][col] = true;
    	int part_time = 0;
    	while (!q.empty()) { // 순회할 때마다 1초 증가
    		part_time++;
    		int len = q.size();
    		for (int i = 0; i < len; ++i) {
    			int r = q.front().first;
    			int c = q.front().second;
    			q.pop();
    			for (int j = 0; j < 4; ++j) {
    				int x = r + dx[j];
    				int y = c + dy[j];
    				if (isBound(x, y) && baby.size >= map[x][y] && !check[x][y]) {
    					if (baby.size > map[x][y] && map[x][y] > 0) {
    						prey.push({ x, y });
    					}
    					check[x][y] = true;
    					q.push({ x, y });
    				}
    			}
    		}
    		if (!prey.empty()) {
    			selectPrey(prey);
    			time += part_time;
    			return;
    		}
    	}
    	isEnd = true;
    }
```
만약 탐색을 모두 했는데도 먹이가 없다면 `isEnd`는 **true**가 되므로 작업이 종료된다.

- **규칙에 따라 먹이 선택하기**
```c+
    void selectPrey(queue<pair<int, int>> &prey) {
    	int prior_x = n, prior_y = n;
    	while (!prey.empty()) {
    		int x = prey.front().first;
    		int y = prey.front().second;
    		prey.pop();
    		if (x < prior_x) {
    			prior_x = x;
    			prior_y = y;
    		}
    		else if (x == prior_x) {
    			if (y < prior_y) {
    				prior_y = y;
    			}
    		}
    	}
    	map[baby.r][baby.c] = 0;
    	map[prior_x][prior_y] = 9;
    	baby.r = prior_x;
    	baby.c = prior_y;
    	baby.cnt++;
    	if (baby.cnt == baby.size) {
    		baby.size++;
    		baby.cnt = 0;
    	}
    }
```
이 먹이 queue에 들어있는 (여럿이라면)물고기들은 모두 같은 거리이기에 문제의 규칙인 가장 위쪽 우선, 가장 왼쪽 우선을 따라 물고기를 선택한다.

먹을 물고기가 선택되면 아기 상어의 위치를 변경해준다. 크기 또한 먹은 수에 맞게 변경해준다.

### 1 Try

- 시간초과 코드

`while (!q.empty()) q.pop();` 라인 때문에 시간초과가 걸린 것 같아 굳이 이럴 필요 없이 먹을 수 있는 물고기가 있다면 `selectPrey()` 를 호출하여 물고기를 선택하고 시간을 갱신해준 후 return하도록 하였다. 이러면 다시 `findPrey()` 를 호출하기에 업데이트 된 아기 상어 위치가 queue에 들어가고 작업을 수행한다. `q`를 비울 필요가 없어짐.

### 2 Try
```c++
    #include <cstdio>
    #include <cstring>
    #include <queue>
    #define MAX 21
    using namespace std;
    int n, time;
    bool isEnd;
    int map[MAX][MAX];
    bool check[MAX][MAX];
    // 상좌우하
    int dx[4] = { -1, 0, 0, 1 };
    int dy[4] = { 0, -1, 1, 0 };
    struct shark {
    	int r, c, size, cnt= 0;
    }baby;
    bool isBound(int r, int c) {
    	if (r > -1 && c > -1 && r < n && c < n) return true;
    	return false;
    }
    void selectPrey(queue<pair<int, int>> &prey) {
    	int prior_x = n, prior_y = n;
    	while (!prey.empty()) {
    		int x = prey.front().first;
    		int y = prey.front().second;
    		prey.pop();
    		if (x < prior_x) {
    			prior_x = x;
    			prior_y = y;
    		}
    		else if (x == prior_x) {
    			if (y < prior_y) {
    				prior_y = y;
    			}
    		}
    	}
    	map[baby.r][baby.c] = 0;
    	map[prior_x][prior_y] = 9;
    	baby.r = prior_x;
    	baby.c = prior_y;
    	baby.cnt++;
    	if (baby.cnt == baby.size) {
    		baby.size++;
    		baby.cnt = 0;
    	}
    }
    void findPrey(int row, int col) {
    	queue<pair<int, int>> q, prey;
    	q.push({ row, col });
    	memset(check, 0, sizeof(check));
    	check[row][col] = true;
    	int part_time = 0;
    	while (!q.empty()) { // 순회할 때마다 1초 증가
    		part_time++;
    		int len = q.size();
    		for (int i = 0; i < len; ++i) {
    			int r = q.front().first;
    			int c = q.front().second;
    			q.pop();
    			for (int j = 0; j < 4; ++j) {
    				int x = r + dx[j];
    				int y = c + dy[j];
    				if (isBound(x, y) && baby.size >= map[x][y] && !check[x][y]) {
    					if (baby.size > map[x][y] && map[x][y] > 0) {
    						prey.push({ x, y });
    					}
    					check[x][y] = true;
    					q.push({ x, y });
    				}
    			}
    		}
    		if (!prey.empty()) {
    			selectPrey(prey);
    			time += part_time;
    			return;
    		}
    	}
    	isEnd = true;
    }
    int main() {
    	scanf("%d", &n);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			scanf("%d", &map[i][j]);
    			if (map[i][j] == 9) { // 아기 상어 정보
    				baby.r = i;
    				baby.c = j;
    				baby.size = 2;
    			}
    		}
    	}
    	while (!isEnd) {
    		findPrey(baby.r, baby.c);
    	}
    	printf("%d\n", time);
    	return 0;
    }
```
### Debug

- 코드
