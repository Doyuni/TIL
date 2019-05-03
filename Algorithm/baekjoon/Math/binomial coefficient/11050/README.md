# 이항 계수 1
Using _recursion_

## C++
```c++
#include <iostream>
using namespace std;
int result = 1;
int divide = 1;
int binomial_coefficient(int n, int k)
{
	if (k >= 1)
	{
		result *= n;
		divide *= k;
		binomial_coefficient(n - 1, k - 1);
	}
	else {
		return result / divide;
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << binomial_coefficient(n, k) << endl;
	return 0;
}
```

## C
```c
#include <stdio.h>
int result = 1;
int divide = 1;

int binomial_coefficient(int n, int k)
{
	if (k >= 1)
	{
		result *= n;
		divide *= k;
		binomial_coefficient(n - 1, k - 1);
	}
	else {
		return result / divide;
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d\n", binomial_coefficient(n, k));
	return 0;
}
```
