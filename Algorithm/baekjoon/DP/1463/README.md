# 1로 만들기
Using _bottom-up_  
  
## C++
```c++
#include <iostream>
#include <algorithm>
using namespace std;
int d[1000001]; // d[1] = 0, d[N]은 N에서 1로 만드는데 드는 연산 횟수의 최솟값
int main()
{
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		d[i] = d[i - 1] + 1; // 1을 빼는 연산은 어느 수든 가능
		if(i % 2 == 0)
		{
			d[i] = min(d[i], d[i / 2] + 1);
		}
		if(i % 3 == 0)
		{
			d[i] = min(d[i], d[i / 3] + 1);
		}
	}
	int min_cost = d[N];
	cout << min_cost << endl;
	return 0;
}
```
