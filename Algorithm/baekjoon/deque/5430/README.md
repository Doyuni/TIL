# AC
Using _Deque_

## C++
```c++
#include <cstdio>
#include <deque>
#include <cstdlib>
#include <cstring>
using namespace std;
char func[100000];
char element[400001]; // 100000*3(100인 요소가 최대 배열 크기만큼)+999999(,)+2(대괄호)
int main() {
	int T, n, num;
	scanf(" %d", &T);
	while (T--) {
		deque<int> d;
		bool error_check = false;
		scanf(" %s", func);
		scanf(" %d", &n);
		scanf(" %s", element);
		char *ptr = strtok(element, "[");
		if (*ptr == ']') ptr = NULL; // []일 때
		ptr = strtok(ptr, ",");
		while (ptr != NULL) {
			d.push_back(atoi(ptr));
			ptr = strtok(NULL, ",");
		}
		bool isR = false;
		int length = strlen(func); // 조건문에 넣으면 시간초과, strlen은 문자 처음부터 끝까지 확인한다.
		for (int i = 0; i < length; i++)
		{
			if (func[i] == 'R') {
				if (isR) isR = false;
				else isR = true;
			}
			else if (func[i] == 'D') {
				if (d.empty()) {
					printf("error\n");
					error_check = true;
					break;
				}
				if (isR) d.pop_back(); // 역순일 때 back이 첫 번째 요소
				else d.pop_front();
			}
		}
		if (isR) {
			if (!d.empty()) {
				printf("[");
				for (auto i = d.rbegin(); i != d.rend(); i++)
				{
					if (i == d.rend() - 1) printf("%d]\n", *i);
					else printf("%d,", *i);
				}
			}
		}
		else {
			if (!d.empty()) {
				printf("[");
				for (auto i = d.begin(); i != d.end(); i++)
				{
					if (i == d.end() - 1) printf("%d]\n", *i);
					else printf("%d,", *i);
				}
			}
		}
		if (d.empty() && !error_check) printf("[]\n");
	}
	return 0;
}
```
		
```c
// strtok를 쓰지 않고 아래와 같이 data를 받으면 시간초과
scanf(" %1c", &bucket);
while (n--) {
	scanf(" %d", &num);
	d.push_back(num);
	scanf(" %1c", &bucket);
}
```
