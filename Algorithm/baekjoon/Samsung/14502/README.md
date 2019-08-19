[문제풀이](https://www.notion.so/doyuni/14502-8913e74cc9b04f608b861f681f46aa40)
## 연구소
[문제링크](https://www.acmicpc.net/problem/14502)

### Problem

- N x M 크기, 빈 칸(0), 벽(1), 바이러스(2) 존재
- 바이러스는 상하좌우 빈칸으로만 움직임
- 벽을 꼭 3개 세워야 한다.

**Goal: 벽을 3개 세운 뒤, 얻을 수 있는 안전 영역 크기의 최댓값
안전 영역은 벽 3개 세운 뒤 0의 개수**

### Solution

1. 벽을 3개 세우는 경우의 수를 모두 구한다. (브루트 포스 - 재귀)
```c++
    void buildWall(int idx, int cnt) {
    	if (cnt == 3) {
    		spreadVirus();
    		return;
    	}
    	if (idx == zero_point.size()) return;
    	buildWall(idx + 1, cnt);
    	wall[cnt].x = zero_point[idx].first;
    	wall[cnt].y = zero_point[idx].second;
    	buildWall(idx + 1, cnt+1);
    }
```
0인 지점을 저장해놓은 벡터에서 3개를 선택하도록 한다.

  2.  원래의 map은 보존해야 하므로 새로운 배열에 복사를 해놓고 위에서 구한 경우의 수에 맞게 벽을 세운다.
```c++
    copyMap(); // 새로운 배열(tmp)에 복사
    for (int i = 0; i < 3; ++i) {
    		tmp[wall[i].x][wall[i].y] = 1;
    }
```
  3.  벽을 세운 새로운 map에서 바이러스가 퍼지도록 한다. (BFS) 
```c++
    void spreadVirus() {
    	// 2번째 작업
    	// 아래부터 3번째 작업
    	queue<pair<int, int> > q;
    	for (int i = 0; i < total_virus; ++i) {
    		q.push({ virus[i].x, virus[i].y });
    	}
    	int minus_safe_area = 3;
    	while (!q.empty()) {
    		int len = q.size();
    		for (int i = 0; i < len; ++i) {
    			int x = q.front().first;
    			int y = q.front().second;
    			q.pop();
    			for (int dir = 0; dir < 4; ++dir) {
    				int d_x = x + dx[dir];
    				int d_y = y + dy[dir];
    				if (isBound(d_x, d_y) && tmp[d_x][d_y] == 0) {
    					q.push({ d_x, d_y });
    					tmp[d_x][d_y] = 2;
    					minus_safe_area++;
    				}
    			}
    		}
    	}
    	if (ans < safe_area - minus_safe_area) ans = safe_area - minus_safe_area;
    }
```
BFS 탐색이 끝나면 queue가 비워지게 되므로, 다음 탐색을 위해 바이러스 위치를 저장해놓을 배열이 필요하다는 것에 주의한다.

**안전영역 크기 = 원래 map의 0의 개수 - 벽 3개 - 모두 퍼진 바이러스 수**

### 1 Try
```c++
    #include <iostream>
    #include <vector>
    #include <queue>
    using namespace std;
    int n, m, ans, safe_area, total_virus;
    int tmp[9][9];
    vector<vector<int> > map;
    vector<pair<int, int> > zero_point;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    struct INFO {
    	int x, y;
    }wall[3], virus[10];
    bool isBound(int x, int y) {
    	if (x > -1 && y > -1 && x < n && y < m) return true;
    	return false;
    }
    void copyMap() {
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			tmp[i][j] = map[i][j];
    		}
    	}
    }
    void spreadVirus() {
    	copyMap();
    	for (int i = 0; i < 3; ++i) {
    		tmp[wall[i].x][wall[i].y] = 1;
    	}
    	queue<pair<int, int> > q;
    	for (int i = 0; i < total_virus; ++i) {
    		q.push({ virus[i].x, virus[i].y });
    	}
    	int minus_safe_area = 3;
    	while (!q.empty()) {
    		int len = q.size();
    		for (int i = 0; i < len; ++i) {
    			int x = q.front().first;
    			int y = q.front().second;
    			q.pop();
    			for (int dir = 0; dir < 4; ++dir) {
    				int d_x = x + dx[dir];
    				int d_y = y + dy[dir];
    				if (isBound(d_x, d_y) && tmp[d_x][d_y] == 0) {
    					q.push({ d_x, d_y });
    					tmp[d_x][d_y] = 2;
    					minus_safe_area++;
    				}
    			}
    		}
    	}
    	if (ans < safe_area - minus_safe_area) ans = safe_area - minus_safe_area;
    }
    void buildWall(int idx, int cnt) {
    	if (cnt == 3) {
    		spreadVirus();
    		return;
    	}
    	if (idx == zero_point.size()) return;
    	buildWall(idx + 1, cnt);
    	wall[cnt].x = zero_point[idx].first;
    	wall[cnt].y = zero_point[idx].second;
    	buildWall(idx + 1, cnt+1);
    }
    int main() {
    	cin >> n >> m;
    	map.resize(n);
    	for (int i = 0; i < n; ++i) {
    		map[i].resize(m);
    		for (int j = 0; j < m; ++j) {
    			cin >> map[i][j];
    			if (map[i][j] == 0) zero_point.push_back({ i, j });
    			else if (map[i][j] == 2) {
    				virus[total_virus].x = i;
    				virus[total_virus++].y = j;
    			}
    		}
    	}
    	safe_area = zero_point.size();
    	buildWall(0, 0);
    	cout << ans << "\n";
    	return 0;
    }
```
