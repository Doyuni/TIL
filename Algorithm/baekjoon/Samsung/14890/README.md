## 경사로

[문제링크](https://www.acmicpc.net/problem/14890)

### Problem

- N x N 지도, 각 칸의 높이가 적힘
- 길은 한 행 또는 한 열 → 길에 속한 모든 칸의 높이가 모두 같아야 지나갈 수 있음
- 또는 경사로를 놓아서 지나갈 수 있는 길을 만들 수 있음( 경사로 높이 1, 길이 L), 경사로 개수는 매우 많음

경사로 놓을 수 있는 경우

- 낮은 칸과 높은 칸의 차이가 1인 경우
- L개의 칸이 같은 높이로 연속되게 있어야 한다.

### Solution

한 행

1. 맨 왼쪽에서부터 오른쪽으로 탐색한다. (첫 번째 원소부터 마지막 원소 바로 이전까지)
2. 현재 탐색한 원소와 바로 다음 원소와의 차이를 구한다.
3. +1인 경우
다음 원소부터 경사로 길이만큼 **오른쪽으로** 탐색을 시작한다.
탐색하면서 다음 경우를 확인한다.
범위를 벗어날 경우(n이상) or 경사로 길이만큼 같은 높이가 아닐 때 종료
그게 아니면 경사로를 놓는다.
4. -1인 경우
현재 원소부터 경사로 길이만큼 **왼쪽으로** 탐색을 시작한다.
탐색하면서 다음 경우를 확인한다.
범위를 벗어날 경우(0미만) or 경사로 길이만큼 같은 높이가 아닐 때 or **경사로가 놓여있을 때** 종료
그게 아니면 경사로를 놓는다.
5. 차이가 1 초과 -1 미만인 경우 종료
6. 그게 아니라면 성공

**+1인 경우는 아직 탐색하지 않은 부분에 경사로를 놓아 경사로가 놓여있는지 검사할 필요가 없다.**

한 열 또한 위와 마찬가지로 구현한다.

### 1 Try

- 하...

`checkCol` 함수에 return true 즉 반환값을 넣어주지 않았기에 틀렸다고 나왔다. bool 함수는 반드시 true와 false 둘 다 반환해주자.

이걸 몰라서 계속 문제만 주구장창 봤음...ㅠ

### 2 Try
```c++
    #include <cstdio>
    #include <cstring>
    using namespace std;
    int n, len, ans;
    int map[101][101];
    bool check[101][101];
    bool checkRow(int row) {
    	for (int j = 0; j < n - 1; ++j) {
    		if (map[row][j] - map[row][j + 1] == 1) {
    			for (int start = j + 1; start <= j + len; ++start) {
    				if (start >= n) return false; // 범위를 벗어나는 경우
    				if (map[row][j + 1] != map[row][start]) return false; // 칸의 높이가 같지 않을 때
    				check[row][start] = true; // 경사로 놓기
    			}
    		}
    		else if (map[row][j] - map[row][j + 1] == -1) {
    			for (int start = j; start > j - len; --start) {
    				if (start < 0) return false;
    				if (map[row][j] != map[row][start]) return false;
    				if (check[row][start]) return false; // 경사로가 이미 놓여진 경우
    				check[row][start] = true;
    			}
    		}
    		else if (map[row][j] - map[row][j + 1] > 1 || map[row][j] - map[row][j + 1] < -1)
    			return false;
    	}
    	return true;
    }
    bool checkCol(int col) {
    	for (int i = 0; i < n - 1; ++i) {
    		if (map[i][col] - map[i + 1][col] == 1) {
    			for (int start = i + 1; start <= i + len; ++start) {
    				if (start >= n) return false;
    				if (map[i + 1][col] != map[start][col]) return false;
    				check[start][col] = true;
    			}
    		}
    		else if (map[i][col] - map[i + 1][col] == -1) {
    			for (int start = i; start > i - len; --start) {
    				if (start < 0) return false;
    				if (map[i][col] != map[start][col]) return false;
    				if (check[start][col]) return false;
    				check[start][col] = true;
    			}
    		}
    		else if (map[i][col] - map[i + 1][col] > 1 || map[i][col] - map[i + 1][col] < -1)
    			return false;
    	}
    	return true;
    }
    int main() {
    	scanf("%d %d", &n, &len);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			scanf("%d", &map[i][j]);
    		}
    	}
    	for (int row = 0; row < n; ++row) {
    		if (checkRow(row)) ans++;
    	}
    	memset(check, 0, sizeof(check));
    	for (int col = 0; col < n; ++col) {
    		if (checkCol(col)) ans++;
    	}
    	printf("%d\n", ans);
    	return 0;
    }
```
