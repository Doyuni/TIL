[문제풀이](https://www.notion.so/doyuni/15685-eda2e5465ccc4822b11ac58a03c1bac0)
## 드래곤 커브

[문제링크](https://www.acmicpc.net/problem/15685)

### Problem

- 좌표 평면
- 3가지 속성
1. 시작 점
2. 시작 방향
0:  x 좌표 증가 → 방향
1:  y 좌표 감소  ↑ 방향
2:  x 좌표 감소 ← 방향
3:  y 좌표 증가  ↓ 방향
3. 세대
- 0세대: 길이가 1인 선분
- 1세대: 0세대 드래곤 커브 **끝 점을 기준으로** 시계 방향 90도 회전시켜 0세대 끝 점에 붙인 것
- 2세대: 1세대를 이용하여 1세대를 만든 것처럼 만든다.
- N세대: N-1세대 커브를 끝 점 기준으로 90도 시계 방향 회전시킨 것을 붙인 것
- 입력

    드래곤 커브 개수 N (~20)
    x, y (드래곤 커브 시작 점) ~100
    d (시작 방향)
    g (세대) ~10

드래곤 커브는 서로 겹칠 수 있다.

**Goal: 만들어진 드래곤 커브에서 정사각형 4개의 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 구하기 (모양이 정사각형이 아니어도 4개의 꼭짓점만 만족하면 된다.)**

### Solution

- 끝점을 기준으로 시계방향 90도를 했을 때 각 방향의 이동은 다음과 같다.
1. 0 → 1
2. 1 → 2
3. 2 → 3
4. 3 → 0

아래 그림 참고.

[](https://www.notion.so/eda2e5465ccc4822b11ac58a03c1bac0#2af66f554bc84b4794e72812ac9b0142)

- 드래곤 커브를 그려주는 건 check 배열로 수행한다. 
(겹쳐도 되니까 초기화할 필요 없다.)
- 방향만 배열에 저장해주면 된다.
- 끝점에서 이동을 수행하니 위치 좌표는 끝점만 알면된다.

    // input : 3 3 0 1
    (3, 3) : 처음 시작 위치
    (4, 3) : 0세대 // 위치 좌표: (4, 3) 방향 0
    (4, 2) : 1세대 // 위치 좌표: (4, 2) 방향 0, 1
    (3, 2), (3, 1) : 2세대 // 위치 좌표: (3, 2) -> (3,1) 방향 0, 1, 2, 1

2세대 설명: 1세대에서 방향이 [0, 1]로 저장되어 있다. 끝점부터 시작하기에 방향 1이 시계방향으로 90도 회전하면 방향 2가 된다. [0, 1, 2]
이후 0이 시계방향으로 90도 회전하면 방향 1이된다. [0, 1, 2, 1]

- 드래곤 커브 위의 규칙대로 그리기

0세대 까지 그려놓고 (0세대가 아니라면) 1세대부터 그ㅣ

direction 배열에 위의 [0, 1, 2, 1]과 같은 값이 들어간다.
```c++
    int clockwise[4] = { 1, 2, 3, 0 };
    void draw(int x, int y, int d, int g) {
    	int idx = 0;
    	check[y][x] = true;
    	direction[idx++] = d;
    	while(g--) {
    		int len = idx;
    		for (int i = len-1; i >= 0; --i) {
    			d = clockwise[direction[i]];
    			x += dx[d];
    			y += dy[d];
    			if (x > -1 && y > -1 && x < MAX && y < MAX) {
    				check[y][x] = true;
    			}
    			direction[idx++] = d;	
    		}
    	}
    }
```
- 4개의 꼭짓점 확인

배열은 최대 100 x 100의 크기를 가지기에 0~99까지 check 값이 존재할 수 있다. (사실상 98까지만 확인하면 된다.)

    1 1   (0, 0)을 기준으로 오른쪽, 아래, 오른쪽 아래 대각선만 확인하면 된다.
    1 1

### 1 Try
```c++
    #include <cstdio>
    #define MAX 101
    using namespace std;
    bool check[MAX][MAX];
    int clockwise[4] = { 1, 2, 3, 0 };
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = { 0, -1, 0, 1 };
    int direction[MAX*MAX];
    void draw(int x, int y, int d, int g) {
    	int idx = 0;
    	check[y][x] = true;
    	direction[idx++] = d;
    	while(g--) {
    		int len = idx;
    		for (int i = len-1; i >= 0; --i) {
    			d = clockwise[direction[i]];
    			x += dx[d];
    			y += dy[d];
    			if (x > -1 && y > -1 && x < MAX && y < MAX) {
    				check[y][x] = true;
    			}
    			direction[idx++] = d;	
    		}
    	}
    }
    int main() {
    	int n, x, y, d, g, answer = 0;
    	scanf("%d", &n);
    	for (int i = 0; i < n; ++i) {
    		scanf("%d %d %d %d", &x, &y, &d, &g);
    		check[y][x] = true;
    		x += dx[d];
    		y += dy[d];
    		draw(x, y, d, g);
    	}
    	for (int i = 0; i <= 99; ++i) {
    		for (int j = 0; j <= 99; ++j) {
    			if (check[i][j]) {
    				if (check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1]) answer++;
    			}
    		}
    	}
    	printf("%d\n", answer);
    	
    	return 0;
    }
 ```
