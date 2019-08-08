## 치킨 배달

[문제링크](https://www.acmicpc.net/problem/15686)

### Problem

- N x N 도시
- 0: 빈 칸, 1: 집, 2: 치킨 집
- 도시의 치킨 거리는 모든 집의 치킨 거리의 합
- 치킨 거리 ( 집: (r1, c1) 치킨집: (r2, c2) )
집과 가장 가까운 치킨집 사이의 거리를 말한다.

|r_1-r_2|+|c_1-c_2|

**Goal: 치킨집 중에서 최대 M개를 골랐을 때 도시의 치킨 거리 최솟값**

### Solution

- 치킨 집을 M개 고르는 모든 조합 구하기

해당 집을 고르면 배열에 넣고 아니면 넣지 않음
```c++
    void combination(int idx) { 
    	if (select_idx == m) {
    		BFS 이용하여 치킨 거리 구하기
    		return;
    	}
    	if (idx == total_chicken) return;
    	combination(idx + 1); // 선택하지 않기
    	select[select_idx++] = idx;
    	combination(idx + 1); // 선택하기
    	select_idx--; // 다른 경우의 수를 위해 인덱스 빼주기 (중요)
    }
```
**중요**라고 되어있는 부분을 작성하지 않으면 모든 경우의 수를 구할 수 없다. 경우의 수가 꼬여버림. 

4개 중에 2개를 고른다고 하면 

    comb(0)
    	comb(1)
    		comb(2)
    			comb(3)
    			...
    		이런식으로 호출이 이루어지기에 (3, 2) 경우가 먼저 완성된다.
    		완성되고 BFS이용하여 치킨 거리 구하고 return되면 select_idx를 빼준다.
    		그럼 2자리에 다른 경우가 넣어질 수 있다. (3, 1)

- 각 조합에 대한 최소한의 치킨 거리 구하기

BFS를 이용하여 한 칸씩 갈 때 1초 증가

그러다 1을 만나면 해당 초를 더 해준다.
BFS를 이용하면 동시에 1을 만나기에 time만 더해주어서는 안된다.
동시에 발견한 집의 수만큼 time을 더해주어야 한다.

모든 1을 만났으면 종료
```c++
    void bfs() {
    	int time = 0, house = 0, dist = 0;
    	memset(check, 0, sizeof(check));
    	queue<pair<int, int>> q;
    	for (int i = 0; i < select_idx; ++i) {
    		q.push({ chicken[select[i]].r, chicken[select[i]].c }); 
    	while (!q.empty()) {
    		time++;
    		int cnt = 0;
    		int len = q.size();
    		for (int i = 0; i < len; ++i) {
    			int r = q.front().first;
    			int c = q.front().second;
    			q.pop();
    			check[r][c] = true;
    			for (int i = 0; i < 4; ++i) {
    				int x = r + dx[i];
    				int y = c + dy[i];
    				if (isBound(x, y) && !check[x][y]) {
    					check[x][y] = true;
    					if (city[x][y] == 1) {
    						house++; cnt++;
    					}
    					q.push({ x, y });
    				}
    			}
    		}
    		dist += time * cnt; // 해당 초에 만난 집의 수 만큼 이동거리 더해주기
    	}
    }
```
- 이 중 가장 최소인 치킨 거리 구하기
```c++
    		dist += time * cnt; // 해당 초에 만난 집의 수 만큼 이동거리 더해주기
    		if (total_house == house) {
    			answer = answer > dist ? dist : answer;
    			return;
    		}
```
### 1 Try

- 컴파일 에러 (index라는 변수명은 기피하자...) **select_idx**로 변경

### 2 Try
```c++
    #include <cstdio>
    #include <cstring>
    #include <queue>
    #define MAX 51
    using namespace std;
    int n, m, total_chicken, total_house, select_idx, answer;
    int city[MAX][MAX];
    bool check[MAX][MAX];
    int select[13];
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    struct INFO {
    	int r, c;
    }chicken[13];
    bool isBound(int r, int c) {
    	if (r > -1 && c > -1 && r < n && c < n) return true;
    	return false;
    }
    void bfs() {
    	int time = 0, house = 0, dist = 0;
    	memset(check, 0, sizeof(check));
    	queue<pair<int, int>> q;
    	for (int i = 0; i < select_idx; ++i) {
    		q.push({ chicken[select[i]].r, chicken[select[i]].c }); // 선택한 치킨집 queue에 저장
    	}
    	while (!q.empty()) {
    		time++;
    		int cnt = 0;
    		int len = q.size();
    		for (int i = 0; i < len; ++i) {
    			int r = q.front().first;
    			int c = q.front().second;
    			q.pop();
    			check[r][c] = true;
    			for (int i = 0; i < 4; ++i) {
    				int x = r + dx[i];
    				int y = c + dy[i];
    				if (isBound(x, y) && !check[x][y]) {
    					check[x][y] = true;
    					if (city[x][y] == 1) {
    						house++; cnt++;
    					}
    					q.push({ x, y });
    				}
    			}
    		}
    		dist += time * cnt; // 해당 초에 만난 집의 수 만큼 이동거리 더해주기
    		if (total_house == house) {
    			answer = answer > dist ? dist : answer;
    			return;
    		}
    	}
    }
    void combination(int idx) { // M개를 선택하는 모든 경우의 수 구하기
    	if (select_idx == m) {
    		bfs();
    		return;
    	}
    	if (idx == total_chicken) return;
    	combination(idx + 1);
    	select[select_idx++] = idx;
    	combination(idx + 1);
    	select_idx--;
    }
    int main() {
    	scanf("%d %d", &n, &m);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			scanf("%d", &city[i][j]);
    			if (city[i][j] == 2) { // 치킨집 정보 저장
    				chicken[total_chicken].r = i;
    				chicken[total_chicken++].c = j;
    			}
    			else if (city[i][j] == 1) total_house++;
    		}
    	}
    	answer = 1e9;
    	combination(0);
    	printf("%d\n", answer);
    	return 0;
    }
    ```
