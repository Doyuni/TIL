# 계단 오르기
Using _bottom-up_  

1. 초기화할 때 상수가 아닌 입력값을 넣어야 한다. ( 예제의 입력값을 넣는 실수 주의 )  
2. n 번째 계단으로 올 수 있는 경우는 n-1 번째 계단 / n-2 번째 계단 에서 넘어오는 경우이다.  
 * 단, n-1번째 계단의 최대값은 두 계단 이전에서 넘어오는 최대값이다.  
 n-2번째 계단은 두 계단 이전의 경우와 한 계단 이전의 경우 중 최대값이다.

## C++
```c++
#include <iostream>
#include <algorithm>
using namespace std;
int d[301][2]; // 0으로 초기화
int cost[301];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	//점화식에 적용안되는 값 초기화
	d[1][0] = cost[1];
	d[2][0] = cost[1] + cost[2]; d[2][1] = cost[2];
	for (int j = 3; j <= n; j++)
	{
		d[j][0] = d[j - 1][1] + cost[j]; // 한 계단 이전에서 왔을 경우 최대값
		d[j][1] = max(d[j - 2][0], d[j - 2][1]) + cost[j]; // 두 계단 이전에서 왔을 경우 최대값
	}
	int max_cost = max(d[n][0], d[n][1]);
	cout << max_cost << endl;
	return 0;
}
```
