[문제풀이](https://www.notion.so/doyuni/14889-e2ce6947fd8641e49857249afa1d2763)

## 스타트와 링크

[문제링크](https://www.acmicpc.net/problem/14889)

### Problem

- 총 N명 중 N/2명으로 두 팀을 만든다. (N은 짝수)
- Sij + Sji = 능력치 ( i번과 j번 사람이 같은 팀에 속했을 때)

**Goal: 두 팀의 능력치의 차이의 최솟값**

### Solution

1. 먼저 두 팀을 나눠야 한다.
1~N 중에 N/2를 골라 만들어야 하는데 중복X + 오름차순이어야 한다.
```c++
    void selectTeam(int idx, int cnt) {
    	if (cnt == n / 2) { // 성공 조건
    		// 능력치 계산
    	}
    	if (idx > n) return; // 실패 조건
    	for (int i = idx; i <= n; ++i) {
    		if (selected[i] == 0) {
    			selected[i] = i;
    			selectTeam(i+1, cnt + 1);
    			selected[i] = 0;
    		}
    	}
    }
```
- 1~20개의 번호를 담을 수 있는 selected 배열을 만든다.
- 선택 되면 선택된 번호의 값을 갖는다. 선택되지 않으면 0값을 갖는다.
- 중복 안되고, 오름차 순이기에 for문의 시작 조건을 위와 같이 한다.
- N/2 만큼 선택하면 능력치를 계산한다.

 2.  능력치 계산

    링크팀: 0, 3, 5
    -> 능력치 
    (0, 3) (0, 5)
    (3, 0) (3, 5)
    (5, 0) (5, 3)

그렇기에 선택된 숫자를 기준으로 나머지 선택된 숫자 하나만 고르면 된다.
```c++
    i는 앞에 선택된 숫자 (i, j)
    for (int j = 1; j <= n; ++j) {
    		if (selected[j] == 0 && i != j) {
    				team_start += ability[i-1][j-1];			
    		}
    }			
```
### 1 Try
```c++
    #include <cstdio>
    #include <cmath>
    using namespace std;
    int n, ans;
    int ability[21][21];
    int selected[21];
    void getDifference() {
    	int team_start = 0;
    	int team_link = 0;
    	for (int i = 1; i <= n; ++i) {
    		if (selected[i] == 0) { // 선택되지 않은 넘버가 다른 팀
    			for (int j = 1; j <= n; ++j) {
    				if (selected[j] == 0 && i != j) {
    					team_start += ability[i-1][j-1];
    				}
    			}
    		}
    		else {
    			for (int j = 1; j <= n; ++j) {
    				if (selected[j] != 0 && i != j) {
    					team_link += ability[i - 1][j - 1];
    				}
    			}
    		}
    	}
    	unsigned int diff = abs(team_start - team_link);
    	if (ans > diff) ans = diff;
    }
    void selectTeam(int idx, int cnt) {
    	if (cnt == n / 2) {
    		getDifference();
    	}
    	if (idx > n) return;
    	for (int i = idx; i <= n; ++i) {
    		if (selected[i] == 0) {
    			selected[i] = i;
    			selectTeam(i+1, cnt + 1);
    			selected[i] = 0;
    		}
    	}
    }
    int main() {
    	scanf("%d", &n);
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			scanf("%d", &ability[i][j]);
    		}
    	}
    	ans = 1e9;
    	selectTeam(1, 0);
    	printf("%d\n", ans);
    	return 0;
    }
```
