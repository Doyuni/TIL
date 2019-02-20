# Meats On The Grill

* 단순하게 생각하는 방법이 필요하다.
* 고기를 같은 덩이끼리 나누어 생각하지 말고 불판 전체를 뒤집으면 해결된다.

```c++
#include <iostream>
using namespace std;
char pan[11][11];
int main() {
    int test_case;
    cin >> test_case;
    while(test_case--) {
        int height, width;
        cin >> height >> width;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                cin >> pan[i][j];
            }
        } // 전체 판을 좌우 대칭으로 뒤집기
        for(int i = 0; i < height; ++i) {
            for(int j = width-1; j >= 0; --j) {
                cout << pan[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
```
