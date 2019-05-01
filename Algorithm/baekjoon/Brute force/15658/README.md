## 연산자 끼워넣기(2)
[문제](https://www.acmicpc.net/problem/15658)
- **재귀함수**를 이용하여 경우의 수를 구한다.  
void calculate(int index, int sum, int plus, int minus, int mul, int div)  
  - index: 수열의 인덱스
  - sum  : 지금까지 계산한 값
  - plus, minus, mul, div: 각 연산자 남은 개수(사용할 때마다 줄어든다.)
  - 수식이 완료되는 조건: index == n(수열의 길이)
    - 최대, 최소 비교
  - 함수 호출  
    - 주의사항은 if(plus < 0 || minus < 0 || mul < 0 || div < 0) return; 을   
  불가능 조건으로 두려면  맨 위에 두어야 한다.  
만일 수식 완료 조건이 먼저 있다면 수식이 불가능한 값을 계산하고 최대 최소를 판단한기 때문이다.
    - 혹은, 종료 조건 없이 각 연산자의 개수가 양수일 때만 해당 함수를 호출하도록 한다.

#### 종료 조건이 없는 코드
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000
using namespace std;
vector<int> a;
int n, max_ans = MIN, min_ans = MAX;
void calculate(int index, int sum, int plus, int minus, int mul, int div) {
    if(index == n) {
        max_ans = max(max_ans, sum);
        min_ans = min(min_ans, sum);
        return;
    }
    if(plus > 0) {
        calculate(index+1, sum+a[index], plus-1, minus, mul, div);
    }
    if(minus > 0) {
        calculate(index+1, sum-a[index], plus, minus-1, mul, div);
    }
    if(mul > 0) {
        calculate(index+1, sum*a[index], plus, minus, mul-1, div);
    }
    if(div > 0) {
        calculate(index+1, sum/a[index], plus, minus, mul, div-1);
    }
}
int main() {
    int num, plus, minus, mul, div;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        a.push_back(num); 
    }
    cin >> plus >> minus >> mul >> div;
    calculate(1, a[0], plus, minus, mul, div);
    cout << max_ans << '\n';
    cout << min_ans << '\n';
    return 0;
}
```
#### 종료 조건이 있는 코드
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
#define MIN -1000000000
using namespace std;
vector<int> a;
int n, max_ans = MIN, min_ans = MAX;
void calculate(int index, int sum, int plus, int minus, int mul, int div) {
    if(plus < 0 || minus < 0 || mul < 0 || div < 0) return;
    if(index == n) {
        max_ans = max(max_ans, sum);
        min_ans = min(min_ans, sum);
        return;
    }
    calculate(index+1, sum+a[index], plus-1, minus, mul, div);
    calculate(index+1, sum-a[index], plus, minus-1, mul, div);
    calculate(index+1, sum*a[index], plus, minus, mul-1, div);
    calculate(index+1, sum/a[index], plus, minus, mul, div-1);
}
int main() {
    int num, plus, minus, mul, div;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        a.push_back(num); 
    }
    cin >> plus >> minus >> mul >> div;
    calculate(1, a[0], plus, minus, mul, div);
    cout << max_ans << '\n';
    cout << min_ans << '\n';
    return 0;
}
```
