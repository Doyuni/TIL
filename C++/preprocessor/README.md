## Preprocessor (전처리기)
  **#** : keyword that orders compiler
_Directive Type_  
### #include
 * 헤더파일을 추가한다. ( 헤더파일에 있는 함수들을 쓸 수 있도록)
### #define  
 * macro라고 불리며, 값을 정의(치환)한다.
 * if 전처리기에 쓰일 때는 값이 없어도 된다.
 * <...> 표준헤더파일, "..." 그외 헤더파일 / 현재의 디렉토리 기준으로 헤더파일을 찾는다.
### #undef
 * #define으로 정의된 것을 무효화한다.
### #if , #else, #elif
 * 0이면 컴파일 안하고, 1이면 컴파일 한다. (ex. A값은 0이 아니기에 1이다.) 
 * 기존의 if문과 동일한 기능 elif는 else if
### #ifdef
 * if define, 만약 정의되어 있다면
 * 한 번에 하나의 정의만 가능
### #if defined
 * 한 번에 여러 개 정의 가능
### #ifndef
 * if not define, 만약 정의되어 있지 않다면  
 * 전처리기 가드로 사용된다. (중복된 헤더파일 추가를 막는다.)
### #pragma
  * 컴파일러의 기능을 확장시킬 수 있도록 하는 지시자, 해석할 수 없는 지시문은 무시한다.
### #pragma once
 * 헤더파일을 한 번만 추가(빌드)한다. ( 컴파일러가 다시 추가할 필요 없어서 컴파일시간을 줄일 수 있다.)
 * #ifndef 처럼 전처리기 가드로 사용된다.
### #pragma comment()
 * 주로 라이브러리를 링크시켜주는 기능을 한다.  
  * #pragma comment(lib, "라이브러리 이름")
### #pragma warning()
 * 특정 경고 메시지를 무시하는 기능을 한다.
### #endif
 * #if로 시작되는 전처리기는 #endif와 짝을 이루어야 한다.  
### #error
 * 컴파일을 중단시키고 작성한 에러 메시지 출력한다.
### #line
 * 특정 부분의 행을 알 수 있게 한다. (잘못된 부분 찾는데 유용)
 * 행번호는 직접 설정 가능하다.
 
_Usage_
```c++
// 정의되어 있지 않다면, 정의해준다.
#ifndef __PREPROCESSOR_H__  // (1)
#define __PREPROCESSOR_H__

// c++ 코드이면
#ifdef _cplusplus // (2)
// name mangling을 하지 않는다.
extern "C" {
#endif // (2)

int sum(int a, int b);
// c++ 코드이면 
#ifdef __cplusplus // (3)
} // extern 블록을 닫는다.
#endif // (3)

int subtract(int a, int b);

#endif // (1)
```
```c++
#include <iostream>
#include <iostream>
//iostream 헤더파일을 보면 선언된 상태이면 무시하게끔 지시문을 사용한다.
ifndef _IOSTREAM_
#define _IOSTREAM_
```
```c++
#if defined(ADD1) || defined(ADD2)
#if ADD1 || ADD2  

#line 10 // 다음 행번호를 10으로 설정
printf("line %d\n", __LINE__); // line 10
```

