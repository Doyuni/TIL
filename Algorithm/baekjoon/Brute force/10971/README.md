## 외판원 순회 2
[문제](https://www.acmicpc.net/problem/10971)
* 1~N번의 도시를 순회하는 순번을 순열로 생각한다.  
ex) 1, 2, 3, 4, ... , N-1, N, 1 (첫 순열), 코드에선 0부터 시작하도록 구현
* N은 최대 10이므로 모든 경우의 수는 10!이다.
모든 순열을 구하는 경우 10! * 10 = 36288000(약 3천만)으로 시간 제한을 넘지 않는다.
* 모든 순열을 구하되, 순열 하나당 비용을 계산하고 최소인지 판단한다.
* 단, 도시를 순회할 수 있는 경우는 경로가 0이 아닌 경우이다.  
경우가 0이라면 순열은 만들어질 수 없으므로 MAX 값을 리턴하여 최소가 될 수 없게 한다.
```c++
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2100000000
using namespace std;
int a[10][10];
int calCost(int (*a)[10], vector<int> &b) {
    int size = b.size();
    int cost = 0;
    for(int i = 0; i < size-1; ++i) {
        if(a[b[i]][b[i+1]] == 0 || a[b[size-1]][b[0]] == 0){ // 경로에 0이 존재, 뒤의 조건은 출발지로 돌아가는 경로가 0인 경우
            return MAX;
        }
        cost += a[b[i]][b[i+1]];
    }
    return cost + a[b[size-1]][b[0]];
}
int main() {
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> b(n); // 순열을 만들 배열
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
        b[i] = i;
    }
    int ans = MAX;
    do {
        int temp = calCost(a, b);
        ans = min(ans, temp);
    } while(next_permutation(b.begin(), b.end()));
    cout << ans << '\n';
    return 0;
}
```
* O(N!*N)보다 더 짧은 시간 복잡도를 가진 방법이 존재한다.
```
0, 1, 2, 3
1, 2, 3, 0
2, 3, 0, 1
3, 0, 1, 2
```
* 위의 4가지 경우는 모두 같은 경우이다. (출발지로 다시 돌아오는 특징 때문에)  
이럴 경우, 시작점을 0으로 고정시킨 후, 모든 순열을 구하면 된다.  
* b.begin()+1을 하여 0으로 고정하고 모든 순열을 구하면, 모든 순서는 (N-1)!가 되기 때문에  
모든 순열을 구하는데 O(N*(N-1)!) 즉, O(N!)의 시간 복잡도를 가지게 된다.
```c++
 do {
        int temp = calCost(a, b);
        ans = min(ans, temp);
    } while(next_permutation(b.begin()+1, b.end()));
```
* 또는 반복문 내에서 b[0]이 0이 아닐 경우 종료시키도록 한다.
```c++
 do {
        if(b[0] != 0) break;
        int temp = calCost(a, b);
        ans = min(ans, temp);
    } while(next_permutation(b.begin(), b.end()));
```


