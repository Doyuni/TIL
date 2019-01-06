# 회전하는 큐

Using _Deque_ 

 *문제 속 연산을 보면 덱을 사용하면 편하다는 것을 알 수 있다.  
   1. pop_front  
   2. front를 pop하여 back에 push  
   3. back을 pop하여 front에 push

## C++
```c++
#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> d;
	int N, M, i;
	int num;
	int pos = 0, cnt = 0;
	cin >> N >> M;
	for (i = 1; i <= N; i++)	d.push_back(i);
	while (M--) {
		cin >> num;
		i = 0;
		for (auto j = d.begin(); j != d.end(); j++) // 뽑을 요소 검색
		{
			if (*j == num) {
				pos = i; // 뽑을 요소가 있는 위치
				break;
			}
			i++;
		}
		// pos는 front와 뽑을 요소와의 거리, d.size()-pos는 back과 뽑을 요소와의 거리
		if (pos < d.size() - pos) { // 2번 연산 수행
			for (int k = 0; k < pos; k++)
			{
				d.push_back(d.front());
				d.pop_front();
				cnt++;
			}
		}
		else { // 3번 연산 수행
			for (int k = 0; k < d.size() - pos; k++)
			{
				d.push_front(d.back());
				d.pop_back();
				cnt++;
			}
		}
		d.pop_front(); // 1번 연산 수행
	}
	cout << cnt << endl;
	return 0;
}
```
