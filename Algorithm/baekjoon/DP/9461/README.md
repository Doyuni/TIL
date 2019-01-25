# 파도반 수열
Using _bottom-up_

* 규칙만 잘 찾으면 점화식이 바로 나오는 문제이다.
* int로 파도반 수열을 구하려하면 틀렸다고 나온다. (long long 이용)

**규칙**
```
 1, 1, 1     
 2, 2 
 3 =  2 + 1
 4 =  3 + 1
 5 =  4 + 1
 7 =  5 + 2
 9 =  7 + 2
12 =  9 + 3
16 = 12 + 4
```
1~5번까지는 초기화, 나머지 점화식
**d[n] = d[n-1] + d[n-5];**

## C++
```c++
#include <iostream>
using namespace std;
long long d[101];

int main() {
    int T, n;
    cin >> T;
    d[1] = d[2] = d[3] = 1;
    d[4] = d[5] = 2;
    while(T--){
        cin >> n;
        for(int i= 6; i <=n; ++i){
            d[i] = d[i-1] + d[i-5];
        }
        cout << d[n] << endl;
    }
    return 0;
}
