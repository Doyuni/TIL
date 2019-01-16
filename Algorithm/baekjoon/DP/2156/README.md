# 포도주 시식
Using _bottom-up_

* 주어진 규칙(연속으로 세 잔 마실 수 없다.)을 잘 이용한다.

## C++
```c++
#include <iostream>
#include <algorithm>
using namespace std;
// 지금 마시는(n) 포도주 잔이 연속으로 j(0~2)번째 마시는 잔이다.
int d[10001][3]; 
int glass[10001];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> glass[i];	
	}
	for (int i = 1; i <= n; i++)
	{
		// n-1번째 잔은 0, 1, 2번째 마시는 잔이다.
		d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
		d[i][1] = d[i - 1][0] + glass[i]; // n-1번째 잔은 0번째 마시는 잔이어야 한다.
		d[i][2] = d[i - 1][1] + glass[i]; // n-1번째 잔은 1번째 마시는 잔이어야 한다.
	}
	cout << max(max(d[n][0], d[n][1]), d[n][2]) << endl;
	return 0;
}
```
