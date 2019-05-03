## 최대공약수
[문제](https://www.acmicpc.net/problem/1850)
- 모든 자리가 1로만 이루어진 두 자연수 A, B이고 입력되는 수는 A, B의 1의 개수이기에  
A, B를 1로 변환하고 최대공약수를 구하라는 문제가 아니다. (입력 값이 2^63보다 작기에)
- 두 입력값의 최대공약수를 구하면 A, B의 최대공약수의 1의 개수가 나온다는 것을 알면 쉽게 풀 수 있다.
- 또한 1의 개수를 실제 수로 바꿀 필요 없이 그만큼 출력하면 된다.
```c++
#include <iostream>
using namespace std;
long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    long long a, b, ans;
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    ans = gcd(a, b);
    for(int i = 0; i < ans; ++i) {
        cout << 1;
    }
    cout << '\n';
    return 0;
}
```
