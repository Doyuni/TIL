# 지능형 기차

Using _DP_

## C++
```c++
#include <iostream>
#include <algorithm>
using namespace std;
int d[4]; // n번째 역일 때, 기차 안의 사람 수
int main(){
    int sub, add, max_people;
    cin >> sub >> add;
    d[0] = add;
    max_people = add;
    for(int i = 1; i < 4; i++)
    {
        cin >> sub >> add;
        d[i] = d[i-1] - sub + add;
        max_people = max(d[i], max_people);
    }
    cout << max_people << endl;
}
```
