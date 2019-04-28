## 부분수열의 합
[문제](https://www.acmicpc.net/problem/1182)
* 주어진 정수들 중에 몇 개를 선택해야 하는지 주어져 있지 않다. (모든 경우의 수를 구해야 한다.)  
N은 20이 최대이고 각 정수마다 사용할지 안할지 2가지 경우가 존재하여  
최대 2^20 = 1048576(약 백만)가지가 존재한다.

* **재귀함수**를 이용하여 구현한다.
  1. 합이 S가 되는 지점을 판단하는 부분
      - **use**라는 flag를 추가로 두어, 중복된 답의 계산을 피하기 위해서 사용한다.   
    **_예시_**  : -3, -2, 5의 순열은 이미 0을 만족하고 count된 상황.  
    이 상태에서 다음 순번인 8을 사용하지 않았을 때도 순열은 이미 0을 만족하기에 count가 중복으로 계산될 수 있다.
      - **use**는 다음 순번을 사용했는지 안했는지를 나타내준다.
  2. **index**(입력 정수의 순번)이 전체 N개를 넘어가면 종료된다.
  3. 재귀함수 호출
      - 숫자를 사용할 경우, 그 숫자를 더해주고 use가 1이 된다.
      - 숫자를 사용하지 않을 경우, 그 숫자를 더해주지 않고 use가 0이 된다.
```c++
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int ans;
void sameSum(int goal, int current_sum, vector<int> &v, int index, int use) {
    if(goal == current_sum && use) { 
        ans++;
    }
    if(index == v.size()) {
        return;
    }
    // 숫자 사용
    sameSum(goal, current_sum + v[index], v, index+1, 1);
    // 숫자 미사용
    sameSum(goal, current_sum, v, index+1, 0);
}
int main() {
    int n, s, num;
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        cin >> num;
        v.push_back(num);
    }
    sameSum(s, 0, v, 0, 0);
    cout << ans << '\n';
    return 0;
}
```
