# 쉬운 계단 수

Using _bottom-up_
## C++
```c++
#include <cstdio>
#include <iostream>
using namespace std;
long long d[101][10];
int main()
{
	int n;
	const long long mod = 1000000000LL;
	scanf(" %d", &n);
	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j > 0) d[i][j] += d[i - 1][j - 1]; // 0일 때는 1만 가능
			if (j < 9) d[i][j] += d[i - 1][j + 1]; // 9일 때는 8만 가능
			//이를 하지 않으면 엄청나게 큰 수가 나와 값을 제대로 다루지 못 한다.
			d[i][j] %= mod; // (A+B)%C = ((A%C)+(B%C))%C
		}
	}
	long long result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result += d[n][i];
	}
	printf("%0.lld\n", result%mod);
	return 0;
}
```
**_알아두기_**   
```c++
if (j == 0) d[i][j] = d[i - 1][j + 1];  
else if(j== 9) d[i][j] = d[i - 1][j - 1];  
else d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
```
```c++
if (j > 0) d[i][j] += d[i - 1][j - 1]; 
if (j < 9) d[i][j] += d[i - 1][j + 1]; 
```
