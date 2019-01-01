# 쇠막대기

Using _Stack_

## C++
```c++
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	string buckets;
	cin >> buckets;
	int sum = 0;
	for (int i = 0; i < buckets.length(); ++i) {
		if (buckets[i] == '(') {
			s.push(i);
		}
		else {
			if (i - s.top() == 1) { // laser
				s.pop();
				sum += s.size();
			}
			else { // bar
				s.pop();
				sum += 1;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
```
