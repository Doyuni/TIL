## 모든 순열
[문제](https://www.acmicpc.net/problem/10974)
1. 첫 순열을 구한다.
2. 다음 순열을 구한다.
3. 마지막 순열까지 구한다.

### 다음 순열 구하기
1. 직접 구현
2. C++ STL algorithm의 함수 이용

#### 직접 구현
```c++
#include <iostream>
#include <algorithm>
using namespace std;
bool nextPermutation(int *a, int n) {
    int i = n-1;
    // a[i-1] < a[i]를 만족하는 가장 큰 i 찾기
    while(i > 0 && a[i-1] >= a[i]) i--;
    if(i <= 0) return false; // 마지막 순열
    int j = n-1;
    // a[i-1] 보다 크면서 가장 작은 수 찾기
    while(a[i-1] >= a[j]) j--;
    // 찾은 두 값 교환하기
    swap(a[i-1], a[j]);
    j = n-1;
    // 내림차순을 오름차순으로 바꾸기
    while(i < j) {
        swap(a[i], a[j]);
        i++, j--;
    }
    return true;
}
int main() {
    int a[9], n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    do { // 첫 순열 출력하기 위해서 do while
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }  while(nextPermutation(a, n));
    return 0;
}
```
#### 라이브러리 사용
```c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n); // 초기화된 n개의 원소를 갖는다
    for(int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }
    do { // 첫 순열 출력하기 위해서 do while
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << '\n';
    }  while(next_permutation(a.begin(), a.end()));
    return 0;
}
```
