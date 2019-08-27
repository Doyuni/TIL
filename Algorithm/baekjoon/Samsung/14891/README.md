## 톱니바퀴

### Problem

- [문제링크](https://www.acmicpc.net/problem/14891)

### Solution

- SWEA 모의 SW 역량 테스트 `특이한 자석` 와 동일하다. (아래는 `특이한 자석` 풀이이다.)
1. 회전하기 전에 자성 확인
자성이 다르면 연관된 자석이 회전을 하게 되어 또 회전이 가능한 자석을 확인을 해주어야 한다.
이를 위해 이전에 확인한 자석 번호를 저장해 중복된 확인이 없도록 한다.
작업은 map에 저장하여 진행했다.
2. 작업 수행하기(회전하기)
- 시계 방향인 경우, 끝 원소를 기억하고 있다가 첫 번째에 넣어준다.
- 반시계 방향인 경우, 첫 원소를 기억하고 있다가 끝에 넣어준다.

3.  작업이 모두 끝났으면 점수를 계산한다.
### 1 Try
```c++
    #include <cstdio>
    #include <map>
    using namespace std;
    int magnatic[4][8];
    map<int, int> task;
    void rotate(int n, int dir) {
    	if (dir == 1) { // 시계 방향
    		int first_ele = magnatic[n][7];
    		for (int i = 6; i >= 0; --i) {
    			magnatic[n][i + 1] = magnatic[n][i];
    		}
    		magnatic[n][0] = first_ele;
    	}
    	else if (dir == -1) { // 반시계 방향
    		int last_ele = magnatic[n][0];
    		for (int i = 1; i < 8; ++i) {
    			magnatic[n][i - 1] = magnatic[n][i];
    		}
    		magnatic[n][7] = last_ele;
    	}
    }
    void checkRotate(int current_num, int prior_num, int dir) {
    	int count_dir = dir > 0 ? -1 : 1;
    	task.insert({ current_num, dir });
    	if (current_num == 0) {
    		if (prior_num != 1) {
    			if (magnatic[current_num][2] != magnatic[current_num + 1][6]) {
    				checkRotate(current_num + 1, current_num, count_dir);
    			}
    		}
    	}
    	else if (current_num == 1) {
    		if (prior_num != 0) {
    			if (magnatic[current_num - 1][2] != magnatic[current_num][6]) {
    				checkRotate(current_num - 1, current_num, count_dir);
    			}
    		}
    		if (prior_num != 2) {
    			if (magnatic[current_num][2] != magnatic[current_num + 1][6]) {
    				checkRotate(current_num + 1, current_num, count_dir);
    			}
    		}
    	}
    	else if (current_num == 2) {
    		if (prior_num != 1) {
    			if (magnatic[current_num - 1][2] != magnatic[current_num][6]) {
    				checkRotate(current_num - 1, current_num, count_dir);
    			}
    		}
    		if (prior_num != 3) {
    			if (magnatic[current_num][2] != magnatic[current_num + 1][6]) {
    				checkRotate(current_num + 1, current_num, count_dir);
    			}
    		}
    	}
    	else if (current_num == 3) {
    		if (prior_num != 2) {
    			if (magnatic[current_num - 1][2] != magnatic[current_num][6]) {
    				checkRotate(current_num - 1, current_num, count_dir);
    			}
    		}
    	}
    }
    int getScore() {
    	int ans = 0, score = 1;
    	for (int n = 0; n < 4; ++n) {
    		if (magnatic[n][0] == 1) {
    			ans += score;
    		}
    		score *= 2;
    	}
    	return ans;
    }
    int main() {
    	for (int i = 0; i < 4; ++i) {
    		for (int j = 0; j < 8; ++j) {
    			scanf("%1d", &magnatic[i][j]);
    		}
    	}
    	int k; scanf("%d", &k);
    	for (int i = 0; i < k; ++i) {
    		int number, dir; scanf("%d %d", &number, &dir);
    		checkRotate(number - 1, -1, dir);
    		for (auto e : task) {
    			rotate(e.first, e.second);
    		}
    		task.clear();
    	}
    	printf("%d\n", getScore());
    	return 0;
    }
 ```
