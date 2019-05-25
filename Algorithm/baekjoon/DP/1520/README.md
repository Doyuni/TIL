# 내리막 길
Using _DP+DFS_

* d[m][n] : (m,n)으로 갈 수 있는 경로의 개수

* dfs탐색으로 도착지점부터 시작  
  1. 시작지점 탐색이면 경로 1개 존재, 1 리턴
  2. 방문한 곳이 아닐 때
    방문 표시, 상하좌우 갈 수 있는 곳 check  
    
      **OK**: map의 현재 높이와 갈 수 있는 map 높이 비교(현재 높이가 더 작아야 탐색가능)  
        
        **OK**: dfs 탐색, d[a][b]에 탐색한 결과 저장(중복된 dfs 탐색을 막기 위해->시간 제한 만족)  
  3. 방문한 곳이면 탐색한 결과가 저장된 d[a][b] 리턴
  
__수정__
- data가 추가되어 재채점 결과 실패라고 떠서 확인 결과 탐색 범위를 확인하는 구문에서 x <= m / y <= n 의 등호를 빼주어야 다. 애초에 0부터 index를 시작했기에 등호를 빼주는게 맞다.
## C++
```c++
#include <iostream>
using namespace std;
int map[500][500]; 
int d[500][500]; // (M, N)으로 갈 수 있는 경로의 수
int move_x[4] = { 0, -1, 0, 1 }; // move (left, up, right, down) of x
int move_y[4] = { -1, 0, 1, 0 }; // move (left, up, right, down) of y
int m, n; // 범위설정을 위해 global variable
int dfs(int a, int b)
{
	if (a == 0 && b == 0) return 1;
	// 방문한 곳은 이전에 탐색한 결과가 저장된 d[a][b]만 리턴해주어 굳이 탐색할 필요 없음
	if (d[a][b] == -1) { 
		d[a][b] = 0; // 방문 표시
		for (int i = 0; i < 4; i++) // left, up, right, down 최대 4번 가능
		{
			int x = a + move_x[i];
			int y = b + move_y[i];
			// map의 범위를 벗어나지 않을 때
			if (x >= 0 && x < m && y >= 0 && y < n)
			{  // 갈 수 있는 map 높이보다 작아야 탐색 가능
				if (map[a][b] < map[x][y])
				{
					d[a][b] += dfs(x, y);
				}
			}
		}
	}
	return d[a][b];
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			d[i][j] = -1;
		}
	}
	cout << dfs(m - 1, n - 1) << endl;

	return 0;
}
```
