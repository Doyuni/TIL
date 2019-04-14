## 로또
[문제](https://www.acmicpc.net/problem/6603)  
* N개 중에서 고정된 수만큼 고르는 경우, 순열을 사용하여 경우의 수를 구할 수 있다.
* next_permutation함수는 중복된 수를 포함한 순열도 문제없이 구한다.
* 골랐을 경우 -1, 고르지 않았을 경우 0  
-1인 이유는 사전 순으로 출력하기 위해서이다. (첫 순열은 -1 -1 ... 이다.)  
* 출력 시에 반복은 6번이 아니라 k번 반복해야 한다. (순열의 길이는 k이기 때문이다.)
```c++
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// 고른 경우 -1, 고르지 않은 경우 0
int lotto[13];
int main() {
    int k;
    while(true) {
        scanf(" %d", &k);
        if(k == 0) break;
        for(int i = 0; i < k; ++i) {
            scanf(" %d", &lotto[i]);
        }
        vector<int> a(k); // 순열
        for(int i = 0; i < 6; ++i) { // 사전 순 출력을 위해 -1을 앞에서부터 할당
            a[i] = -1;
        }
        do {
            for(int j = 0; j < k; ++j) { 
                if(a[j] == -1) {
                    printf("%d ", lotto[j]);                
                }
            }
            printf("\n");
        } while(next_permutation(a.begin(), a.end()));
        printf("\n");
    }
    return 0;
}
```
