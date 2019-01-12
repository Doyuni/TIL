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