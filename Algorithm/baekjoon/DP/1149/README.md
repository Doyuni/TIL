# RGB거리
Using _bottom-up Dynamic Programming_

## C++
```c++
#include <iostream>
#include <algorithm> //using min(a,b)
using namespace std;
int cost[1000][3]; 
int d[1000][3]; //memoization

int Min(int n)
{	
	for (int i = 1; i < n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + cost[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + cost[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + cost[i][2];
	}
	return min(d[n-1][0], min(d[n-1][1], d[n-1][2]));
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	for (int j = 0; j < 3; j++) //initialize the value
	{
		d[0][j] = cost[0][j];
	}
	cout << Min(N);
	return 0;
}
```
