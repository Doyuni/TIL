# Android NDK + OpenCV

### Environment
  * Windows10
  * OpenCV 4.0.1
  * Android Studio 3.3
  * SDK
    * Android 9.0 (Pie) API 28
    * LLDB
    * NDK 19
  
### Method
1. 프로젝트 생성  
  Select Empty Activity.  
  
2. OpenCV library module  
 ```
 1) File > New > Import Module
    * Source directory : 설치한 opencv 디렉토리 하위에 있는 sdk 디렉토리 경로
    * Module name > Opencv  
 2) File > Project structure > app > Dependencies > + > Module dependency > Opencv(이전에 만든 opencv 모듈)
  ```
