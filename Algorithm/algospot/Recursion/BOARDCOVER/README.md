# 게임판 덮기
[BOARDCOVER](https://algospot.com/judge/problem/read/BOARDCOVER)

* 재귀함수를 통해 게임판에 블록을 하나 놓고 남은 흰 칸들을 재귀 호출을 이용해 덮도록 한다.
* 중복을 제거하기 위해 특정 순서대로 답을 도출할 수 있도록 한다.  
-> 가장 윗줄 왼쪽 칸에 블록을 놓는다.  

**총 4가지 유형**

| . | . |       
|---|---|    
|   | . |    

| . | . | 
|---|---|
| . |   |

| . |   | 
|---|---|
| . | . |

|   | . | 
|---|---|
| . | . |

```c++
#include <iostream>
#include <vector>
using namespace std;
const int coverType[4][3][2] = { // 4개의 모양
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};
vector<vector<int> > board;
bool set(vector<vector<int> >& board, int y, int x, int type, int delta) {
	bool ok = true;
	for(int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		// 판을 벗어날 때
		if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) {
			ok = false;
		} else if((board[ny][nx] += delta) > 1) { // 서로 겹칠 때 or 검은 칸일 때
			ok = false;
		}
	}
	return ok;
}

int cover(vector<vector<int> >& board) {
	int y = -1, x = -1;
	// 가장 윗줄 왼쪽에 있는 칸 탐색
	for(int i = 0; i < board.size(); ++i) {
		for(int j = 0; j < board[i].size(); ++j) {
			if(board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}
	// 모든 칸을 채웠을 때 count
	if(y == -1) return 1;
	int ans = 0;
	for(int type = 0; type < 4; ++type) {
		if(set(board, y, x, type, 1)) { // delta 1 블록을 덮는다.
			ans += cover(board);
		}
		set(board, y, x, type, -1); // delta -1 덮었던 블록을 없앤다.(초기화)
	}
	return ans;
}
int main() {
	int test_case, height, width;
	cin >> test_case;
	while(test_case--) {
			cin >> height >> width;
			char shape;
			board.resize(height);
			for(int i = 0; i < height; ++i) {
				for(int j = 0; j < width; ++j) {
					cin >> shape;
					if(shape == '#') {
						board[i].push_back(1);
					} else {
						board[i].push_back(0);
					}
				}
			}
			cout << cover(board) << endl; 
			board.clear();
	}
	return 0;
}
```
