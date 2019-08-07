## 미세먼지 안녕!

[문제링크](https://www.acmicpc.net/problem/17144)

### Problem

- 공기청정기 항상 왼쪽 열 (두 행 차지)
- 그외 미세먼지나 빈 칸이 존재
- 1초 동안 일어나는 일
1. 미세먼지 확산
4방향(상하좌우)
공기청정기나 경계를 벗어나는 칸은 확산이 일어나지 않음
미세먼지 양/5 만큼 확산된다. (각 방향에 대해 한 칸)
확산된 후 남은 미세먼지 양은 
현재 미세먼지 양 - 현재 미세먼지 양/5 * 확산된 방향 개수
2. 공기청정기 작동 (바람)
위쪽 → 반시계방향 순환
아래쪽 → 시계방향 순환
미세먼지가 바람의 방향대로 한 칸씩 이동
미세먼지가 공기청정기로 들어가면 모두 정화

**Goal: T초가 지난 후 남아있는 미세먼지의 양**

### Solution

1초가 지날 때마다 다음과 같은 작업이 수행된다.

1. 미세먼지 확산
2. 바람으로 인한 이동
- 미세먼지 확산

5 이상인 값만 확산이 일어난다.
확산이 일어나기 전에 queue에 이 값과 이 값이 있는 위치를 저장해놓는다.
(값을 저장해야 올바른 값을 구할 수 있음)
queue에서 하나씩 꺼내어 4가지 방향을 확인한다.
(공기청정기 있는 곳과 경계를 넘는 곳은 불가능)

    void spread() {
    	int len = q.size();
    	for (int i = 0; i < len; ++i) {
    		int r = q.front().r;
    		int c = q.front().c;
    		int mid = q.front().value;
    		q.pop();
    		for (int j = 0; j < 4; ++j) {
    			int x = r + dx[j];
    			int y = c + dy[j];
    			if (isBound(x, y) && map[x][y] != -1) {
    				map[x][y] += mid / 5;
    				map[r][c] -= mid / 5;
    			}
    		}
    	}
    }

확산이 가능하다면 연산을 수행한다.

- 바람으로 인한 이동

아래 순서대로 map을 바꿔준다. 

[사진](https://www.notion.so/doyuni/17144-f7b517ef0ee64d40be651521aefa8721#dfcc3da030bb48a08010b5b6e6353b78)

공기청정기로 들어간다는 것은 굳이 값을 바꿔줄 필요 없이 전의 값이 이를 덮어주기만 하면 된다. (1번째)
공기청정기에서 나아가는 바람으로(4번째) 값을 0으로 채워주어야 한다.

    void wind() {
    	int i, j, clean_row = clean[0];
    // 위쪽
    	for (i = clean_row - 2; i >= 0; --i) {
    		map[i + 1][0] = map[i][0];
    	}
    	for (j = 1; j < total_col; ++j) {
    		map[0][j - 1] = map[0][j];
    	}
    	for (i = 1; i <= clean_row; ++i) {
    		map[i - 1][total_col - 1] = map[i][total_col - 1];
    	}
    	for (j = total_col - 1; j >= 1; --j) {
    		map[clean_row][j + 1] = map[clean_row][j];
    	}
    // 아래쪽
    	map[clean_row][1] = 0;
    	clean_row = clean[1];
    	for (i = clean_row + 2; i < total_row; ++i) {
    		map[i - 1][0] = map[i][0];
    	}
    	for (j = 1; j < total_col; ++j) {
    		map[total_row - 1][j - 1] = map[total_row - 1][j];
    	}
    	for (i = total_row - 2; i >= clean_row; --i) {
    		map[i + 1][total_col - 1] = map[i][total_col - 1];
    	}
    	for (j = total_col - 2; j >= 1; --j) {
    		map[clean_row][j + 1] = map[clean_row][j];
    	}
    	map[clean_row][1] = 0;
    }

### 1 Try
테스트 케이스는 다 맞다는데 틀렸단다...ㅎ

그 이유는 MAX를 50이기 때문이다. (응? 뭔 🙄🤔...다음부터 넉넉히 잡자..)
MAX 51로 고쳐주니까 바로 정답 처리 되었다.

### 2 Try
```c++
    #include <cstdio>
    #include <queue>
    #define MAX 51
    using namespace std;
    int total_row, total_col, time;
    int map[MAX][MAX];
    int clean[2];
    struct info {
    	int r, c, value;
    };
    queue<info> q;
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    bool isBound(int r, int c) {
    	if (r > -1 && c > -1 && r < total_row && c < total_col) return true;
    	return false;
    }
    void spread() {
    	while(!q.empty()) {
    		int r = q.front().r;
    		int c = q.front().c;
    		int mid = q.front().value;
    		q.pop();
    		for (int j = 0; j < 4; ++j) {
    			int x = r + dx[j];
    			int y = c + dy[j];
    			if (isBound(x, y) && map[x][y] != -1) {
    				map[x][y] += mid / 5;
    				map[r][c] -= mid / 5;
    			}
    		}
    	}
    }
    void wind() {
    	int i, j, clean_row = clean[0];
    	for (i = clean_row - 2; i >= 0; --i) {
    		map[i + 1][0] = map[i][0];
    	}
    	for (j = 1; j < total_col; ++j) {
    		map[0][j - 1] = map[0][j];
    	}
    	for (i = 1; i <= clean_row; ++i) {
    		map[i - 1][total_col - 1] = map[i][total_col - 1];
    	}
    	for (j = total_col - 1; j >= 1; --j) {
    		map[clean_row][j + 1] = map[clean_row][j];
    	}
    	map[clean_row][1] = 0;
    	clean_row = clean[1];
    	for (i = clean_row + 2; i < total_row; ++i) {
    		map[i - 1][0] = map[i][0];
    	}
    	for (j = 1; j < total_col; ++j) {
    		map[total_row - 1][j - 1] = map[total_row - 1][j];
    	}
    	for (i = total_row - 2; i >= clean_row; --i) {
    		map[i + 1][total_col - 1] = map[i][total_col - 1];
    	}
    	for (j = total_col - 2; j >= 1; --j) {
    		map[clean_row][j + 1] = map[clean_row][j];
    	}
    	map[clean_row][1] = 0;
    }
    int main() {
    	int answer, idx = 0;
    	scanf("%d %d %d", &total_row, &total_col, &time);
    	for (int i = 0; i < total_row; ++i) {
    		for (int j = 0; j < total_col; ++j) {
    			scanf("%d", &map[i][j]);
    			if (map[i][j] >= 5) q.push({ i, j, map[i][j] });
    		}
    		if (map[i][0] == -1) clean[idx++] = i;
    	}
    	while (time--) {
    		answer = 0;
    		spread();
    		wind();
    		for (int i = 0; i < total_row; ++i) {
    			for (int j = 0; j < total_col; ++j) {
    				if (map[i][j] > 0) answer += map[i][j];
    				if (map[i][j] >= 5) q.push({ i, j, map[i][j] });
    			}
    		}
    	}
    	printf("%d\n", answer);
    	return 0;
    }
```
