# 소풍
[PICNIC](https://algospot.com/judge/problem/read/PICNIC)
* 완전 탐색 방법으로 재귀함수를 사용
* 중복된 값 제거를 위해 특정 형태의 답만 센다.
=> 가장 빠른 번호의 순번 하나만 센다.  
(0, 1)(2, 3) / (1, 0)(2, 3) / (2, 3)(1, 0) 중 (0, 1)(2, 3) 하나만 센다.  
_주의_  
* (0, 1)과 (1, 0)은 같다. 
* 테스트 케이스가 끝날 때 friends 2차원 배열 초기화

```c++
#include <iostream>
using namespace std;
int n; // 학생 수
bool friends[10][10]; // 친구면 true 아니면 false
bool found[10];
int countPair(bool found[10]) {
	// 남은 학생 중 가장 빠른 번호 수
	int first = -1;
	for (int i = 0; i < n; ++i) {
		if (!found[i]) {
			first = i;
			break;
		}
	}
	// 기저: 모든 학생이 짝을 찾는 경우 count 1 
	if (first == -1) return 1;
	int ans = 0;
	// 가장 빠른 번호의 학생과 짝지을 학생 결정
	for (int i = first + 1; i < n; ++i) {
		if (!found[i] && friends[first][i]) {
			found[first] = found[i] = true;
			ans += countPair(found);
			// count를 하나 세면, 다른 경우를 셈하기 위해 초기화
			found[first] = found[i] = false;
		}
	}
	return ans;
}
int main() {
	int test_case;
	cin >> test_case;
	int m;
	while (test_case--) {
		cin >> n >> m;
		int a, b;
		while (m--) {
			cin >> a >> b;
			friends[a][b] = true;
			friends[b][a] = true;
		}
		cout << countPair(found) << endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				friends[i][j] = false;
			}
		}
	}
	return 0;
}
```
