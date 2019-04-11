## 차이를 최대로
[문제](https://www.acmicpc.net/problem/10819)
* n은 최대 8로 나올 수 있는 경우의 수의 최대는 8! = 40320이다.
* 모든 순열을 구하는데 걸리는 시간 복잡도는 O(N*N!)이다.  
순열의 개수는 총 N!, 순열을 만드는데 걸리는 시간은 N이기 때문이다.  
* 첫 순열은 정렬이 안되어있는 상태이기에 오름차순으로 정렬을 해줘야 next_permutation으로 모든 순열을 구할 수 있다.
```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // abs()
using namespace std;
int diffMax(vector<int> &a) {
    int sum = 0;
    int size = a.size();
    for (int i = 0; i < size-1; i++)
    {
        sum += abs(a[i] - a[i+1]);
    }
    return sum;
}
int main() {
    int n, ans = -1;
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n); // 초기화된 n개의 원소를 갖는다
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    do { // 첫 순열 계산하기 위해서 do while
        int temp = diffMax(a);
        ans = max(ans, temp);
    }  while(next_permutation(a.begin(), a.end()));
    cout << ans << '\n';
    return 0;
}
```
