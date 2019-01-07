# 시험 감독
자료형 범위 주의(int, long long)
## C++
```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, A, B, C;
	long long sum = 0; // 감독관의 최소 수가 1,000,000,000,000가 될 수 있음 
	vector<int> v;
	cin >> N;
	sum += N;
	while (N--) {
		cin >> A;
		v.push_back(A);
	}
	cin >> B >> C;
	for (auto i = v.begin(); i != v.end(); i++)
	{
		*i -= B;
		if (*i > 0) { // 0이하이면 부감독관 필요없음
			if (*i % C != 0) sum += (*i / C) + 1;
			else if (*i % C == 0) sum += (*i / C);
		}
	}
	cout << sum << endl;
	return 0;
}
```
