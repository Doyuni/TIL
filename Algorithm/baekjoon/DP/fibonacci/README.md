# 피보나치
Using _bottom-up_

## C++
```c++
#include <iostream>
using namespace std;
int d[46]; // 0~45
int fibo(int n) //bottom-up
{
	d[0] = 0, d[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}
	return d[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
```
