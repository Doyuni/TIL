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
    // seed number가 고정되어 있으면 다른 숫자를 생성할 수 없기 때문이다.
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
### Random Number Generator using rand()(범위 지정)
```c++
cout << "rand() % 4 + 5" << endl;
// 0 + 5 ~ 3 + 5 (5~8) 
// 큰 범위 내에서 실행되면 특정 범위에서만 난수가 생성될 수 있음
for(int i = 1; i <= 100; ++i) {
  cout << rand() % 4 + 5 << "\t";
  if(i % 5 == 0) cout << endl;
}
```
### Random Number Generator using time()
* 시간은 항상 흐르기에 매번 다른 숫자를 생성 가능하다.
```c++
#include <ctime> // std::time()

cout << "srand(time)" << endl;
// time을 이용하여 매번 다르게 출력한다.
std::srand(static_cast<unsigned int>(std::time(0)));
for(int i = 1; i <= 100; ++i) {
    cout << std::rand() << "\t";
    if(i % 5 == 0) cout << endl;
}
// 조금 더 random number처럼 보인다.
```
### Since C++11
```c++
std::random_device rd; // 시드가 고정되지 않게 한다.
// 난수 생성 알고리즘
// 32비트
std::mt19937 mersenne(rd()); // create a mersenne twister(숫자를 꼬는거)
// 64비트
std::mt19937_64 mer(rd());

// 1이상 6이하의 숫자가 동일한 확률을 가진다.
std::uniform_int_distribution<> dice(1, 6);
//std::normal_distribution
//std::geometric_distribution
//etc...
cout << "c++11" << endl;
for (int i = 1; i <= 20; ++i)
{
    cout << dice(mersenne) << endl;
}
```
