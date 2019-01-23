## Preprocessor (전처리기)

Type  
### #define  
  macro라고 불리며, 값을 정의(치환)한다.
### #ifdef
  if define, 만약 정의되어 있다면
### #ifndef
  if not define, 만약 정의되어 있지 않다면  
### #endif
  #define을 제외한 나머지는 #endif와 짝을 이루어야 한다.  
 
Usage
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

#endif (1)
```
