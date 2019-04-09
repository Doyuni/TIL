## 일곱 난쟁이
[문제](https://www.acmicpc.net/problem/2309)
* 9개 중에 7개를 고르는 경우는 9개 중 2개를 고르는 경우와 같다.
* 2개를 고른 후 n만큼 계산을 해주는 것까지 포함하여 총 O(N^3)의 시간 복잡도를 가진다.  
여기서 n은 9이기 때문에 9^3 = 729로 시간제한 내로 풀 수 있다.
```c++
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int dwarf[9];
    int sum = 0;
    int n = 9;
    for(int i = 0; i < n; ++i)
    {   
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf, dwarf+n); // 오름차순 출력을 위해
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(sum - dwarf[i] - dwarf[j] == 100) {
                for(int k = 0; k < n; k++) {
                    if( i != k && j != k)
                        cout << dwarf[k] << '\n';
                }
                return 0;
            }
        }
        
    }
    return 0;
}
```
