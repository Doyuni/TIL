### 골드바흐의 추측
[문제](https://www.acmicpc.net/problem/6588 "골드 바흐의 추측")

1. 에라토스테네스의 체를 이용해 소수를 구한다.
2. check array를 이용해서 N - a = b가 소수인지 아닌지를 판단한다.
3. N은 6이상의 수이기에 prime[1]부터 탐색을 시작한다. (6 = 3 + 3)
4. b가 소수인지 판단이 되면 출력하고 반복문을 종료한다.

```c++
#include <iostream>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn = 0;
bool check[MAX+1];
void primeFind() {
    for(int i = 2; i <= MAX; ++i) {
        if(!check[i]) {
            prime[pn++] = i;
        }
        for(int j = i*2; j <= MAX; j+=i) 
        {
            check[j] = true;
        }
    }
}
int main()
{   
    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primeFind();
    while(true) {
        cin >> n;
        if(n == 0) break;
        int i;
        int flag = 1;
        for(i = 1; i < pn; ++i) { // 테스트 케이스는 6부터 시작하기에 i는 1부터 시작한다. (3+3=6)
            if(!check[n-prime[i]]) {
                cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
                flag = 0;
                break;
            }
        }    
        if(flag) cout << "Goldbach's conjecture is wrong." << '\n';   
    }
    return 0;
}

```
