## 암호 만들기
[문제](https://www.acmicpc.net/problem/1759)
* 암호가 될 조건이 까다롭기에, 모든 조건을 만족했을 경우 암호를 출력하도록 한다.  

**암호 조건** 
1. 최소 1개의 모음과 최소 2개의 자음으로 구성
2. 알파벳 순서로 배열되어 있어야 한다.   
* **재귀함수**를 이용하여 암호가 될 경우의 수를 구한다.  

**재귀함수**  
createCipher(만들어야 할 암호의 길이, 입력 알파벳 배열, 알파벳 배열의 인덱스, 현재까지 만들어진 암호)  
1. 암호가 될 수 있는지 판단한다.
  - 만들어야 할 암호의 길이와 현재까지 만들어진 암호의 길이가 같을 경우
  - 같다면 조건1을 만족하는지 판단 후 출력 여부를 결정한다.
2. 암호가 절대 될 수 없는 경우를 판단한다.  
  - 더 이상 사용할 알파벳이 없는 경우  
이 조건문의 **순서**가 중요한데 문제의 예시 경우 "acsw"와 같이 'w'로 끝났을 경우 암호가 될 수 있지만,  
이 조건문이 맨 처음에 있다면 더이상 사용할 알파벳이 없다고 판단하여  
암호를 출력하지 않기 때문이다.
3. 함수를 호출해야 하는 경우
  - index 순번의 알파벳을 사용할 때
  - index 순번의 알파벳을 사용하지 않을 때

```c++
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool check(string password) { // 최소 자음 2개, 모음 1개를 포함해야 한다.
    int ja = 0, mo = 0;
    for(auto iter = password.begin(); iter != password.end(); ++iter) {
        char ch = *iter;
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            mo++;
        } else {
            ja++;
        }
    }
    if(ja >= 2 && mo >= 1) return true;
    return false;
}
void createCipher(int pw_len, vector<char> &alphabet, int index, string password) {
    if(password.length() == pw_len) {
        if(check(password)) {
            cout << password << endl;
            return;
        }
    }
    if(index >= alphabet.size()) return;
    createCipher(pw_len, alphabet, index+1, password+alphabet[index]); // alphabet을 사용한 경우
    createCipher(pw_len, alphabet, index+1, password); // alphabet을 사용하지 않은 경우
}
int main() {
    int l, c;
    cin >> l >> c;
    vector<char> v(c);
    string pw = "";
    for(int i = 0 ; i < c; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end()); // 정렬된 상태로 출력하기 
    createCipher(l, v, 0, pw);
    return 0;
}
```
