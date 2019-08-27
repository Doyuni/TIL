## 감시
### Problem

- [문제링크](https://www.acmicpc.net/problem/15683)

### Solution

1. 설치된 CCTV 위치정보, 번호 얻기
2. 설치된 CCTV 방향 정하기 (상하좌우: 0123)  
1번 cctv: 0, 1, 2, 3  
2번 cctv: (0, 1), (2, 3)  
3번 cctv: (0, 3), (1, 3), (0, 2), (1, 2)  
4번 cctv: (2, 0, 3), (0, 3, 1), (2, 1, 3), (0, 2, 1)  
5번 cctv: (0, 1, 2, 3)  
묶음을 왼쪽에서부터 0, 1, 2, 3이라고 정하고 (여기서 5번은 0만 갖게된다.)  
`selected` 배열에 넣어준다.  
```c++
    void selectDirection(int idx, int cnt) {
    	if (cnt == cctv.size()) {
    		task(); // 방향대로 감시 시작
    		return;
    	}
    	int type = cctv[idx].type;
    	for (int i = 0; i < 4; ++i) {
    		if (type == 2) { // 2번 cctv는 최대 1 값만 가능
    			if (i == 2) break; 
    		}
    		if(type == 5) { // 5번 cctv는 최대 0만 가능
    			if (i == 1) break;
    		}
    		selected[idx] = i;
    		selectDirection(idx + 1, cnt + 1);
    		selected[idx] = -1;
    	}
    }
```
  3.  선택된 방향대로 감시 시작

- 범위를 벗어나거나 벽을 만나면 감시를 중단한다. 그전까지는 정해진 방향대로 계속 check 표시를 한다.
- check는 check되어 있지 않고 맵의 값이 0인 경우에만 진행한다.
탐색된 곳의 개수를 구하기 위해서이다.
- 전체 칸의 개수 - 탐색된 곳의 개수 - 벽의 개수 - cctv 개수 = 사각지대 개수

  4.  사각지대가 최소가 되도록 갱신한다.

### 1 Try
```c++
    #include <iostream>
    #include <vector>
    using namespace std;
    int n, m, wall_cnt, ans;
    int room[9][9];
    int selected[9];
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int type_two[2][2] = {{0, 1}, {2, 3}};
    int type_three[4][2] = { {0, 3}, {1, 3}, {0, 2}, {1, 2} };
    int type_four[4][3] = { {2, 0, 3}, {0, 3, 1}, {2, 1, 3}, {0, 2, 1} };
    struct INFO {
    	int x, y, type;
    };
    vector<INFO> cctv;
    void init() {
    	for (int i = 0; i < 9; ++i) selected[i] = -1;
    	ans = 1e9; wall_cnt = 0;
    }
    bool isBound(int x, int y) {
    	if (x > -1 && y > -1 && x < n && y < m) return true;
    	return false;
    }
    void task() {
    	bool check[9][9] = { 0, };
    	int type, res = 0;
    	for (int i = 0; i < cctv.size(); ++i) {
    		int dir = selected[i];
    		int x = cctv[i].x, y = cctv[i].y;
    		int d_x, d_y;
    		if (cctv[i].type == 1) {
    			d_x = x + dx[dir];
    			d_y = y + dy[dir];
    			while (isBound(d_x, d_y) && room[d_x][d_y] != 6) {
    				if (!check[d_x][d_y] && room[d_x][d_y] == 0) {
    					check[d_x][d_y] = true;
    					res++;
    				}
    				d_x += dx[dir];
    				d_y += dy[dir];
    			}
    		}
    		else if (cctv[i].type == 2) {
    			for (int j = 0; j < 2; ++j) {
    				d_x = x + dx[type_two[dir][j]];
    				d_y = y + dy[type_two[dir][j]];
    				while (isBound(d_x, d_y) && room[d_x][d_y] != 6) {
    					if (!check[d_x][d_y] && room[d_x][d_y] == 0) {
    						check[d_x][d_y] = true;
    						res++;
    					}
    					d_x += dx[type_two[dir][j]];
    					d_y += dy[type_two[dir][j]];
    				}
    			}
    		}
    		else if (cctv[i].type == 3) {
    			for (int j = 0; j < 2; ++j) {
    				d_x = x + dx[type_three[dir][j]];
    				d_y = y + dy[type_three[dir][j]];
    				while (isBound(d_x, d_y) && room[d_x][d_y] != 6) {
    					if (!check[d_x][d_y] && room[d_x][d_y] == 0) {
    						check[d_x][d_y] = true;
    						res++;
    					}
    					d_x += dx[type_three[dir][j]];
    					d_y += dy[type_three[dir][j]];
    				}
    			}
    		}
    		else if (cctv[i].type == 4) {
    			for (int j = 0; j < 3; ++j) {
    				d_x = x + dx[type_four[dir][j]];
    				d_y = y + dy[type_four[dir][j]];
    				while (isBound(d_x, d_y) && room[d_x][d_y] != 6) {
    					if (!check[d_x][d_y] && room[d_x][d_y] == 0) {
    						check[d_x][d_y] = true;
    						res++;
    					}
    					d_x += dx[type_four[dir][j]];
    					d_y += dy[type_four[dir][j]];
    				}
    			}
    		}
    		else if (cctv[i].type == 5) {
    			for (int j = 0; j < 4; ++j) {
    				d_x = x + dx[j];
    				d_y = y + dy[j];
    				while (isBound(d_x, d_y) && room[d_x][d_y] != 6) {
    					if (!check[d_x][d_y] && room[d_x][d_y] == 0) {
    						check[d_x][d_y] = true;
    						res++;
    					}
    					d_x += dx[j];
    					d_y += dy[j];
    				}
    			}
    		}
    	}
    	res = (n * m) - res - wall_cnt - cctv.size();
    	if (res < ans) ans = res;
    }
    void selectDirection(int idx, int cnt) {
    	if (cnt == cctv.size()) {
    		task();
    		return;
    	}
    	int type = cctv[idx].type;
    	for (int i = 0; i < 4; ++i) {
    		if (type == 2) {
    			if (i == 2) break;
    		}
    		if(type == 5) {
    			if (i == 1) break;
    		}
    		selected[idx] = i;
    		selectDirection(idx + 1, cnt + 1);
    		selected[idx] = -1;
    	}
    }
    int main() {
    	cin >> n >> m;
    	init();
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			cin >> room[i][j];
    			if (room[i][j] >= 1 && room[i][j] <= 5) {
    				cctv.push_back({ i, j, room[i][j] });
    			}
    			else if (room[i][j] == 6) wall_cnt++;
    		}
    	}
    	selectDirection(0, 0);
    	cout << ans << "\n";
    	return 0;
    }
```
