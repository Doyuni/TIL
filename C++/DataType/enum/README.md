### enum
* enumerated types 열거형
* 항상 대괄호 끝에 ; 을 붙여야 한다.
```c++
#include <iostream>
#include <typeinfo>
#include <string>

// 각 무기의 id를 다 외워야 하는 불편함을 개선하고자 enum을 사용한다.
int compute_damage(int weapon_id) {
    if (weapon_id == 0) { // sword
        return 0;
    }
    if (weapon_id == 1) { // hammer
        return 1;
    }
}

enum Weapon
{
    WEAPON_SWORD,
    WEAPON_HAMMER,
    WEAPON_DAGGER, // 마지막에 , 가 있어도 된다(새로운 옵션 추가 용이를 위해)
}; // ; 주의 !!

enum Sword 
{
    //WEAPON_SWORD 다른 enum value의 이름과 같으면 안된다. -> enum class를 사용하여 해결
    // 아래와 같은 수동할당보단 기본할당이 좋다.
    WEAPON_LONG_SWORD = 0,
    WEAPON_SHORT_SWORD = -2,
    WEAPON_MIDDLE_SWORD, // -1이다.
}; // ; 주의 !!

int main() {
    using namespace std;

    Weapon sword = WEAPON_SWORD;
    Weapon hammer(WEAPON_HAMMER);
    Weapon dagger{WEAPON_DAGGER};

    // 내부적으로 정수로 저장되어 있으나 정수로는 사용 불가
    int weapon_id = WEAPON_DAGGER; // possible
    //Weapon long_sword = 3;  impossible
    Weapon long_sword = static_cast<Weapon>(3); // possible
    // cin >> long_sword;  impossible
    // 우회해서 입력을 받자.
    int weapon_number;
    cin >> weapon_number;
    if(weapon_number == WEAPON_HAMMER) {
        weapon_number =  WEAPON_HAMMER;
    }
    // enum class를 사용하여 비교가 불가능하게 하자.
    if(WEAPON_SWORD == WEAPON_LONG_SWORD) {}
    string input;
    getline(cin, input);
    // 추천하지 않음, 사람이 입력하기에 오타 가능성
    if(input == "WEAPON_HAMMER") { }

    return 0;
}
```
### enum class
```c++
#include <iostream>

using namespace std;

int main()
{
    // since C++11
    enum class Weapon
    {
        SWORD,
        HAMMER,
        DAGGER,
        BOW,
    };

    enum class Sword
    {
        SWORD,
        LONG_SWORD,
        SHORT_SWORD,
    };
    // 같은 이름 가능
    Weapon sword = Weapon::SWORD;
    Sword default_sword = Sword::SWORD;

        // 비교 불가 
    // if(sword == default_sword) { } 

    // 같은 enum class는 비교 가능
    Weapon w1 = Weapon::SWORD;
    Weapon w2 = Weapon::SWORD;
    
    if(w1 == w2) {
        cout << "Same weapon" << endl;
    }
    return 0;
}
```
