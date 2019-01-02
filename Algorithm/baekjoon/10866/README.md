# 덱
Using _Deque_

## C++
```c++
#include <iostream>
#include <deque>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	deque<int> d;
	int N;
	string cmd;
	cin >> N;
	while(N--) {
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> cmd;
			d.push_front(stoi(cmd));
		}
		else if (cmd == "push_back") {
			cin >> cmd;
			d.push_back(stoi(cmd));
		}
		else if (cmd == "pop_front") {
			if (!d.empty()) {
				cout << d.front() << endl;
				d.pop_front();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (cmd == "pop_back") {
			if (!d.empty()) {
				cout << d.back() << endl;
				d.pop_back();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (cmd == "size") {
			cout << d.size() << endl;
		}
		else if (cmd == "empty") {
			cout << (d.empty() ? 1 : 0) << endl;
		}
		else if (cmd == "front") {
			cout << (d.empty() ? -1 : d.front()) << endl;
		}
		else if (cmd == "back") {
			cout << (d.empty() ? -1 : d.back()) <<endl;
		}
	}
	return 0;
}
