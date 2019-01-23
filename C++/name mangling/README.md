## name mangling
  * mangle: 망치다.
  
Compiler가 임의로 method or variable의 이름을 변경하는 것을 말한다.

why? > Overloading in C++
  * Overloading: same name, different function of method
  ```c++
  int add(int a, int b) { return a+b; }
  double add(double a, double b) { return a+b; }
  float add(float a, float b, float c) { return a+b+c; }
  ```
 같은 이름의 method를 compiler는 name mangling을 통해 구분한다.
 
 위의 method들을 예를 들면, int add -> addii처럼 만든다.
 
 ![mangle](https://en.wikipedia.org/wiki/Name_mangling#How_different_compilers_mangle_the_same_functions)
 
 C의 경우는 Overloading을 지원하지 않기에 mangled name이 필요없다. 하나의 binary에 function만 존재  
  (실제로 compiler는 이름을 바꿔 놓는다. -> object file(.o) or .lib 파일을 hex editor로 열어서 확인 가능)
 
 ### extern "C"
 extern "C" 이후에 오는 모든 내용을 name mangling 하지 않는다.
 
 **mangle.cpp**
 ```c++
#ifndef __MANGLING_H__ 
#define __MANGLING_H__
#include "abc.h" 

#ifdef _cplusplus 
extern "C" {
#endif 
//#include "abc.h" extern "C" 가 중복되어 error occur
int sum(int a, int b); //  not mangling: sum

#ifdef __cplusplus 
} 
#endif 

int subtract(int a, int b); // mangling: subtractii

#endif
```
