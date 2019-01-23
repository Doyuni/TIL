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
3. javah
 C/C++ 함수가 선언되어 있는 헤더 파일을 jni 디렉토리에 자동으로 생성해주는 역할
  * File > Settings > Tools > External Tools > + 
  ```
  Name: javah
  Description: NDK Tool - javah
  Program: Android Studio JDK > Android Studio가 설치된 폴더\jre\bin\javah.exe
            Oracle JDK > Java\JDK가 설치된 폴더(jdk)\bin\javah.exe
  Arguments: -v -jni -d $ModuleFileDir$/src/main/jni $FileClass$
  Working directory: $SourcepathEntry$
  ```
4. MainActivity > 마우스 우클릭 > External Tools > javah
 java code package 이름과 MainActivity의 조합으로 header 파일 이름 결정
