# 피보나치 함수
Using _bottom-up DP_  

0일 때와 1일 때, 각각 나누어 문제를 풀어나가면 된다.

n번째 피보나치의 수를 기억할 필요가 없다.

## C++
```c++
#include <iostream>
using namespace std;
int a[41]; // 0 횟수 memoization
int b[41]; // 1 횟수 memoization

int main()
{
	int T,n;
	cin >> T;
	while (T--) {
		cin >> n;
		a[0] = 1, a[1] = 0;
		b[0] = 0; b[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			a[i] = a[i - 1] + a[i - 2]; // i일 때 0 출력 횟수
			b[i] = b[i - 1] + b[i - 2]; // i일 때 1 출력 횟수
		}
		cout << a[n] << " " << b[n] << endl;
	}
	return 0;
}
```
