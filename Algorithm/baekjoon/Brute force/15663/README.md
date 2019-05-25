## N과 M (9) [문제](https://www.acmicpc.net/problem/15663)
- 이번 문제는 다른 N과 M (1~8)와는 다르다.
- N개의 자연수 중에서 M개를 골라 수열을 만들어야 한다.  
그렇기에 동일한 숫자가 입력값으로 주어질 때 주의해야 한다.

Input        | Output 
-------------|----------
 [4 4, 1211] | [1112, 1121, 1211, 2111] 
 [4 4, 1212] | [1122, 1212, 1221, 2112, 2121, 2211]
  
 특히, 위의 두 경우에 대해 주의하며 문제를 푼다. 
 - cnt라는 배열을 두어 입력값이 몇 번 반복되는지 저장하였다. (메모리 제한 512MB인 것을 고려)   
   check에 값을 할당하기 위해 사용될 것  
 - 이전에 check가 1이면 continue였던 것에 비해, 이번 문제에서는 check 벡터를 cnt의 값으로 초기화 하였다.  
 그 이유는 재귀함수 for문의 조건문 때문이다.  
 - 여기서는 check가 0일 때 continue이다. 이는 check가 각 숫자가 몇 번 사용되었는지를 저장하고 있기에,  
 사용할 때마다 1씩 줄어들면서 0이 될 때는 사용할 수 없다는 뜻이니 continue로 넘어가는 것이다.  
 그리고 재귀함수가 return 되었을 때는 다시 check를 1씩 더해 다음 수열을 만들 수 있도록 하였다.
 
 ```c++
 #include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10000
using namespace std;
int n, m;
vector<int> check, ans, num;
int cnt[MAX+1];
void doSequence(int index) {
    if(index == m) {
        for(int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < num.size(); ++i) {
        if(check[i] == 0) continue;
        if(cnt[num[i]] > 0) check[i]--; 
        ans[index] = num[i]; 
        doSequence(index+1);
        check[i]++;
    }
}
int main() {
    int number;
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> number;
        cnt[number]++;
        if(cnt[number] == 1) {
            num.push_back(number);
        }
    }
    sort(num.begin(), num.end());
    check.resize(n);
    for(int i = 0; i < num.size(); ++i) {
        check[i] = cnt[num[i]];
    }
    ans.resize(m);
    doSequence(0);
    return 0;
}
 ```
 
