# 에디터
Using _Stack_

## C++
```c++
#include <cstring> // string.h in C
#include <cstdio> // stdio.h in C
#include <stack>
using namespace std;
char word[600000];
int main() {
	scanf("%s", word);
	stack<char> left, right; // 커서를 기준으로 스택을 둘로 나눈다.
	int n = strlen(word);
	for (int i = 0; i < n; i++) {
		left.push(word[i]);
	}
	int N;
	scanf("%d", &N);
	while (N--) {
		char cmd;
		scanf(" %c", &cmd); // 공백문자 처리를 위해 한 칸을 띄운다. 
		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty()) left.pop();
		}
		else if (cmd == 'P') {
			scanf(" %c", &cmd);// 공백문자 처리를 위해 한 칸을 띄운다. 
			left.push(cmd);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	return 0;
}
```
