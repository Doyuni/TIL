## String
* char 배열은 마지막에 null 문자('\0')가 있다.
* 주의할 점은 null 문자가 나오기 전까지만 출력한다.
```c++
char my_string[] = "string"; // 문자열 길이 7

my_string[3] = '\0';
cout << my_string << endl; // str
```
### strcpy
* 한 문자열을 다른 문자열로 복사해준다.
```c++
void user_strcpy(char* src, char* dest) {
    while(*src) {
        *dest = *src;
        *src++, *dest++;  
    }
    *dest = '\0';
}
```
### strcat
* 한 문자열 뒤에 다른 문자열을 더한다.
```c++
void user_strcat(char* src, char* dest) {
    while(*dest) {
        *dest++;
    }
    while(*src) {
        *dest = *src;
        *dest++, *src++;
    }
    *dest = '\0';
}
```
### strcmp
* 두 문자열을 비교한다.
1. 문자열이 같다면 0을 리턴한다.
2. 기준 문자열(src)보다 작으면 1, 크면 -1을 리턴한다. 
```c++
int user_strcmp(char* src, char* dest) {
    while(*src) {
        if(*src > *dest) {
            return 1;
        } else if(*src < *dest) {
            return -1;
        }
        *src++, *dest++;
    }
    if(*dest == '\0') return 0;
    else return -1;
}
```
