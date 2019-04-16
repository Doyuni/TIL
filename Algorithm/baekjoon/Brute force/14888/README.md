## 연산자 끼워넣기
[문제](https://www.acmicpc.net/problem/14888)
* 고정된 수열에서 연산자의 순서만 달리하여 식을 만드는 방식이다.  
그렇기에 연산자에 대한 모든 순열을 구하여 순서대로 고정된 수열을 계산하면 된다.
```
"+" : 0
"-" : 1
"*" : 2
"/" : 3
```
으로 두고 모든 순열을 구한다. 순열을 하나씩 구할 때마다 앞에서부터 계산을 진행한다.  
(기본 연산자 우선 순위를 무시하기 때문에)
* 각 식의 결과값이 최대인 것과 최소인 것을 구한다.

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000
using namespace std;
int main() {
    int n, op_count, max_ans = MIN, min_ans = MAX;
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> op;
    vector<int> num(n);
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for(int i = 0; i < 4; ++i) {
        cin >> op_count;
        for(int j = 0; j < op_count; ++j) {
            op.push_back(i); // 0: '+', 1: '-', 2: '*', 3: '/'
        }
    }
    do {
        int result = num[0];
        for(int i = 0; i < n-1; ++i) {
            if(op[i] == 0) {
                result += num[i+1];
            } else if(op[i] == 1) {
                result -= num[i+1];
            } else if(op[i] == 2) {
                result *= num[i+1];
            } else if(op[i] == 3) {
                result /= num[i+1];
            }
        }
        max_ans = max(max_ans, result);
        min_ans = min(min_ans, result);
    }while(next_permutation(op.begin(), op.end()));
    cout << max_ans << "\n" << min_ans << "\n";
    return 0;
}
```
