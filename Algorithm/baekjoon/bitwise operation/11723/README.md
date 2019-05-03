## 집합
[문제](https://www.acmicpc.net/problem/11723)
- bit mask(& | ^ ~)를 사용하여 메모리 제한을 만족시킨다.  
bit mask는 정수이기에 배열보다 공간적인면에서 효율적이다.

- remove 연산은 toggle 연산과 동일하게 수행이 가능하다. (제거할 대상이 항상 1인 경우) 

- 시간 제한을 만족시키기 위해 cin과 cout이 아닌 scanf와 printf를 사용한다.

- strcmp로 문자열 전체를 비교하며 진행할 수도 있다. (아래 코드는 특정 문자만 비교)

- 전체 집합(all)은 모두 1로 이루어진 집합이므로 2^21 - 1이다.
```c++
#include <cstdio>
using namespace std;
int main() {
    unsigned int m, x, s_set = 0;
    char op[7];
    scanf("%d", &m);
    while(m--) {
        scanf(" %s", op);
        if(op[1] != 'l' && op[1] != 'm') scanf(" %d", &x);
        if(op[1] == 'd') {
            s_set |= (1<<x);
        } else if(op[1] == 'e') {
            s_set ^= (1<<x); // same as s_set &= ~(1<<x)
        } else if(op[1] == 'h') {
            if(s_set & (1<<x)) {
                printf("1\n");
            } else printf("0\n");
        } else if(op[1] == 'o') {
            s_set ^= (1<<x);
        } else if(op[1] == 'l') {
            s_set = (1<<21)-1;
        } else if(op[1] == 'm') {
            s_set = 0;
        }
    }
    return 0;
}
```
