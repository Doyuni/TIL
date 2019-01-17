# 동전 1
Using _bottom-up_
* 메모리 제한 때문에 1차원 배열로 풀어야 한다.  
  int d[101][10001], coin[101]; // 4 * ( 101 + 101 * 10001)Bytes = 4MB 초과 가능

점화식 : **D(n, k) = D(n-1, k) + D(n, k-C(n))**  
 
  * n번째까지의 동전을 사용하여 k원을 만드는 경우  
  = n-1번째까지의 동전을 사용하여 k원을 만드는 경우 + n번째까지의 동전을 써서 k-C(n)원을 만드는 경우

## C++
```c++
#include <iostream>
using namespace std;
int d[10001];
int coin[101];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	d[0] = 1; // 동전을 아무것도 선택하지 않는 경우 1가지
	for (int i = 1; i <= n; i++)
	{	// i번째 동전 이전부터 시작하면 경우의 수 없음
		for (int j = coin[i]; j <= k; j++) 
		{	
		// 이전 동전으로 j를 만들 수 있는 경우 + coin[i]를 하나 선택하여 j를 만들 수 있는 경우 
			d[j] += d[j - coin[i]];
		}
	}
	cout << d[k] << endl;
	return 0;
}
```
