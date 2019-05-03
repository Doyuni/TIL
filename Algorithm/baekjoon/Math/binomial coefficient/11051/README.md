# 이항계수 2

Using _DP_

* (A+B)%C = ((A%C)+(B%C))%C

## C++
```c++
#include <iostream>
using namespace std;
int d[1001][1001];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)
	{  // 이항계수에서 k가 0이면 무조건 1값을 갖는다.
		d[i][0] = 1; 
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{ //이항 계수 점화식
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	cout << d[n][k] % 10007 << endl;
	return 0;
}
```
