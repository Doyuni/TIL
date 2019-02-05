# 리모컨
Using _Brute force_

* 이동할 채널에 도달하는 방법은 다음과 같다.
1. **+** or **-** 버튼을 눌러 도달
2. 숫자 버튼을 눌러 도달
3. 숫자 버튼을 눌러 이동할 채널에 가까운 채널로 이동 후, (**+** or **-**) 버튼을 눌러 도달

이동할 채널을 문자열로 받아 가장 큰 자릿수부터 고장여부를 확인하며 가장 가까운 숫자에 접근하였다.  
하지만, 최솟값 접근에 반례가 많아 이 방법은 힘들다.  

#### 접근법
* 차이의 최솟값을 현재 채널인 100과의 차이로 초기화한다. (차이는 양수임을 주의)

* 일의 자리부터 그 숫자의 버튼 고장 여부를 확인하며 목표 채널을 확인한다.
  * 고장난 버튼이면 다음 숫자 탐색
  * 각 자릿수 모두 고장난 버튼이 아니라면 목표채널과의 차이를 구하고 현재 최솟값과 비교한다.

* 이동할 채널의 최댓값은 500000이고 탐색해야 할 채널의 최댓값은 888888이다. 

_**input**_
```
500000
9
0 1 2 3 4 5 6 7 8
```
999999-500000 = 499999  
500000- 99999 = 400001  
차이가 최소인 채널만 탐색하면 되므로, 999999를 탐색할 필요가 없다.  

_**input**_
```
500000
8
0 1 2 3 4 5 6 7
```
888888 - 500000 = 388888  
500000 -  99999 = 400001  
차이가 최소인 채널은 888888이므로 탐색해야 할 채널의 최댓값은 888888이다.

## C++
```c++
#include <iostream>
using namespace std;
int broken[10];
int main() {
    int goal, m;
    int broken_number;
    cin >> goal >> m;
    while(m--) {
        cin >> broken_number;
        broken[broken_number] = 1;
    } // 현재 채널과의 차이 
    int min = abs(goal - 100); 
    for(int i = 0; i <= 888888; i++) { 
        int len = 0;
        int num = i;
        int flag = false;
        while(1) { 
            if(broken[num%10]) break;
            else { 
                num /= 10;
                len++;
                if(num == 0) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) {
            int result = abs(goal-i);
            if(result + len < min) {
                min = result + len;
            }
        }
    }
    cout << min << endl;
    return 0;
}
```

