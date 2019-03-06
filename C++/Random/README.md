### Pseudo Random Number Generator
```c++
unsigned int PRNG() {
    // 시작하는 숫자 시드 넘버
    static unsigned int seed = 5523; // seed number

    // seed와 관련성이 없는 숫자(예측하기 힘든 숫자)
    seed = 8253729 * seed + 2396403;

    return seed % 32768;
}
int main() {
    cout << "PRNG" << endl;
    for(int i = 1; i <= 100; ++i) {
        cout << PRNG() << "\t";
        if(i % 5 == 0) cout << endl;
    }
    return 0;
}
```
* 난수를 실제로 만들 수는 없고 난수처럼 보이는 숫자들이다.

### srand(), rand() function
```c++
#include <cstdlib> // std::rand(), std::srand()
int main() {
    cout << "rand()" << endl;
    // seed 설정
    std::srand(5523); // 디버깅할 때 시드를 고정시켜놓는다.
    for(int i = 1; i <= 100; ++i) {
        cout << std::rand() << "\t";
        if(i % 5 == 0) cout << endl;
    }
    return 0;
}
```
### Random Number Generator from min to max number(범위 지정)
```c++
#include <cstdlib> // std::rand(), std::srand()

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max-min+1)*(std::rand() * fraction)); 
}
int main() {
     cout << "getRandomNumber" << endl;
    // 지정된 범위 내의 난수 생성
    for(int i = 1; i <= 100; ++i) {
        cout << getRandomNumber(0, 10) << "\t";
        if(i % 5 == 0) cout << endl;
    }
    cout << "rand() % 4 + 5" << endl;
    // 0 + 5 ~ 3 + 5 (5~8) 
    // 큰 범위 내에서 실행되면 특정 범위에서만 난수가 생성될 수 있음
    for(int i = 1; i <= 100; ++i) {
        cout << rand() % 4 + 5 << "\t";
        if(i % 5 == 0) cout << endl;
    }
    
    return 0;
}
```
