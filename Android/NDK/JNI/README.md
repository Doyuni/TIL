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
 app\src\main\cpp에 <package name of java code>_<Activity name>.h가 만들어짐  
 
 cpp 디렉토리에 New > File > cpp file 생성 
 #### main.cpp
 ```c++
 #include <jni.h>
 #include "방금 만들어진 헤더파일 이름"
 #include <opencv2/opencv.hpp>
using namespace cv;

extern "C"{

    JNIEXPORT void JNICALL
   Java_<package name of java code>_<Activity name>_<method name>(
            JNIEnv *env, jobject  instance, arguments){
         //TO DO
      }
}
```
5. Android.mk, Application.mk (File Type: Text)
* NDK build를 사용하여 공유 라이브러리를 build하기 위해 필요하다.
#### Android.mk
```txt
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

#opencv library
OPENCVROOT:= Android OpenCV가 설치된 경로 (단, native 디렉토리가 보이는 경로이다.)

OPENCV_CAMERA_MODULES:=on
OPENCV_INSTALL_MODULES:=on
OPENCV_LIB_TYPE:=SHARED
include ${OPENCVROOT}\native\jni\OpenCV.mk

LOCAL_MODULE    := native-lib
LOCAL_SRC_FILES := main.cpp
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)
```
#### Application.mk
```txt
APP_OPTIM := debug
APP_ABI := arm64-v8a armeabi-v7a x86 x86_64

APP_PLATFORM := android-28

APP_STL := c++_static
APP_CPPFLAGS := -frtti -fexceptions
NDK_TOOLCHAIN_VERSION := clang

APP_BUILD_SCRIPT := Android.mk
```
6. Gradle Scripts > build.gradle(Module: app)
 * buildTypes block 아래에 다음을 추가
 ```
 externalNativeBuild {
        ndkBuild {
            path 'src/main/jni/Android.mk'
        }
    }
 ```
