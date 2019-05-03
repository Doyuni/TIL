# 팩토리얼 0의 개수

**N!를 구하라는 문제가 아니다.**

N의 최대값이 500인데 500!는 엄청나게 큰 수이므로 구할 수 없다.

2와 5를 이용하자.
* 2x5 = 10, 2x2x5x5 = 100, 2x2x2x5x5 = 200를 보면 2, 5가 0의 갯수를 결정함을 알 수 있다.

## C++
```c++
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int two_cnt = 0; // 2가 곱해진 갯수
	int five_cnt = 0; // 5가 곱해진 갯수
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		// 2로 나눌 수 있을 때까지 나눈다.
		while(temp % 2 == 0)
		{
			temp /= 2;
			two_cnt++;
		}
		// 5로 나눌 수 있을 때까지 나눈다.
		while (temp % 5 == 0)
		{
			temp /= 5;
			five_cnt++;
		}
	}
	// 2와 5가 곱해진 갯수 중 최솟값이 끝자리 0의 갯수다.
	cout << min(two_cnt, five_cnt) << endl;
	return 0;
}
```
