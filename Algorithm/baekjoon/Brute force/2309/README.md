## 일곱 난쟁이
[문제](https://www.acmicpc.net/problem/2309)

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
