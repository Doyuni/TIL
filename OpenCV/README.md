# OpenCV + Visual Studio 2017 & Visual Studio Code
 * Visual Studio Code for Ubuntu

## 1. System information
```
OS: Windows 10 (64bit)
Tool: Visual Studio 2017
OpenCV v4.0.0
```

## 2. Environment setting  
 ### Windows 10

제어판 -> 시스템 -> 고급 시스템 설정 -> 고급 탭의 환경변수  

  **System Variable**  
  + 새로 만들기  
    + Variable name: **OPENCV_BUILD**  
    + Variable : **opencv설치경로\build**
  + Path  
    + 편집 -> **%OPENCV_BUILD%\x64\vc15\bin**
    
### Visual Studio 2017   
 Project 설정(Property)   
   
  Configuration: All, Platform: x64  
 
   + Configuration Properties
   
     + Debugging -> Environment: **PATH=C:\opencv\build\x64\vc15\lib;%PATH%**
   + C/C++
   
     + General -> Additional Include Directories: **$(OPENCV_BUILD)\include**  
   + Linker 
   
     + General -> Additional Library Directories: **$(OPENCV_BUILD)\x64\vc15\lib**  
     + Input -> Additional Dependencies: **opencv_world401.lib;opencv_world401d.lib**  
     Windows 10 (64bit) or
         * Debug: opencv_world400d.lib / Release: opencv_world400.lib
         
## 1. System information
```
OS: Ubuntu 16.04
Tool: Visual Studio Code
OpenCV v4.0.1
```

## 2. Environment setting   

### 1). 기존 패키지들 업데이트 및 업그레이드
```console
Doyuni@groot:~$ sudo apt-get update
Doyuni@groot:~$ sudo apt-get upgrade

```
### 2). cmake 및 패키지 설치
 * build-essential package: include C/C++ compiler, library and make
 * cmake: for compiling openCV
```console
Doyuni@groot:~$ sudo apt-get install build-essential cmake
```
 * pkg-config: 컴파일 및 링크시 필요한 library를 메타파일(확장자가 .pc 인 파일)로부터 가져오는데 사용
```console
Doyuni@groot:~$ sudo apt-get install pkg-config
```
 * 특정 포맷의 이미지 파일 특정 코덱의 비디오 파일을 읽고 쓰기위해 필요한 패키지
 * libqt4-dev or libgtk4-dev: OpenCV에서 자체적으로 윈도우를 생성하여 이미지나 비디오를 보여준다.
  * highgui module 사용, 이런 GUI를 위해 gtk or qt 사용
 * 그외 OpenGL 지원, OpenCV 최적화를 위해 사용되는 libraries
```console
Doyuni@groot:~$ sudo apt-get install libjpeg-dev libtiff5-dev libjasper-dev libpng12-dev
Doyuni@groot:~$ sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libxvidcore-dev libx264-dev libxine2-dev
Doyuni@groot:~$ sudo apt-get install libv4l-dev v4l-utils
Doyuni@groot:~$ sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
Doyuni@groot:~$ sudo apt-get install libqt4-dev
Doyuni@groot:~$ sudo apt-get install mesa-utils libgl1-mesa-dri libqt4-opengl-dev
Doyuni@groot:~$ sudo apt-get install libatlas-base-dev gfortran libeigen3-dev
```
### 3). OpenCV 설치 및 설정
 * OpenCV 설치할 디렉토리 생성 및 설치
```console
Doyuni@groot:~$ mkdir OpenCV
Doyuni@groot:~$ cd OpenCV
Doyuni@groot:~/OpenCV$ wget -O opencv.zip https://github.com/opencv/opencv/archive/4.0.1.zip
Doyuni@groot:~/OpenCV$ unzip opencv.zip
Doyuni@groot:~/OpenCV$ wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.0.1.zip
Doyuni@groot:~/OpenCV$ unzip opencv_contrib.zip
Doyuni@groot:~/OpenCV$ cd opencv-4.0.1
Doyuni@groot:~/OpenCV/opencv-4.0.1$ mkdir build
Doyuni@groot:~/OpenCV/opencv-4.0.1$ cd build
Doyuni@groot:~/OpenCV/opencv-4.0.1/build$ mkdir build
```
 * OpenCV compile setting with cmake
```console
Doyuni@groot:~/OpenCV/opencv-4.0.1/build$ cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D WITH_TBB=OFF \
-D WITH_IPP=OFF \
-D WITH_1394=OFF \
-D BUILD_WITH_DEBUG_INFO=OFF \
-D BUILD_DOCS=OFF \
-D INSTALL_C_EXAMPLES=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D BUILD_EXAMPLES=OFF \
-D BUILD_TESTS=OFF \
-D BUILD_PERF_TESTS=OFF \
-D WITH_QT=ON \
-D WITH_GTK=OFF \
-D WITH_OPENGL=ON \
-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.0.1/modules \
-D WITH_V4L=ON  \
-D WITH_FFMPEG=ON \
-D WITH_XINE=ON \
-D BUILD_NEW_PYTHON_SUPPORT=ON \
-D OPENCV_GENERATE_PKGCONFIG=ON ../
```
* Configuring done / Generating done 등이 error 메시지가 없으면 성공이다.

* 사용중인 CPU core 수를 확인하여 그 수만큼 컴파일 시작 및 설치
```console
Doyuni@groot:~/OpenCV/opencv-4.0.1/build$ cat /proc/cpuinfo | grep processor | wc -l
8
Doyuni@groot:~/OpenCV/opencv-4.0.1/build$ time make -j8
Doyuni@groot:~/OpenCV/opencv-4.0.1/build$ sudo make install
```
* /etc/ld.so.conf.d/ 디렉토리에 /usr/local/lib 설정파일이 있는지 확인한다.
```console
Doyuni@groot:~/OpenCV/opencv-4.0.1/build$ cat /etc/ld.so.conf.d/*
/usr/lib/x86_64-linux-gnu/libfakeroot
# libc default configuration
/usr/local/lib
# Multiarch support
/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu
/usr/lib/x86_64-linux-gnu/mesa-egl
/usr/lib/x86_64-linux-gnu/mesa
```

### 4) OpenCV code Test
 Visual Studio Code  
 [설정 참고](https://github.com/Doyuni/TIL/tree/master/Visual%20Studio%20Code)
 
 #### main.cpp
 ```c++
 #include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main()
{
    string filepath("Lena.jpg"); // load the image
    Mat origin_img = imread(filepath, IMREAD_COLOR);
    if (origin_img.empty())
    {
        cout << "이미지를 찾을 수 없습니다." << endl;
        return -1;
    }
    imshow("Lena", origin_img);
    waitKey();
    return 0;
}
 ```
 * main.cpp 있는 디렉토리에 CMakeLists.txt 파일 생성
 #### CMakeLists.txt
 ```txt
 project(코드가 있는 디렉토리 이름)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 2.8)
find_package( OpenCV REQUIRED )
 
file(GLOB SOURCES  *.cpp)
 
add_executable(${PROJECT_NAME} ${SOURCES}  )
target_link_libraries( 코드가 있는 디렉토리 이름 ${OpenCV_LIBS} )
```
* task 파일 설정
#### tasks.json
```javascript
{
    "version": "2.0.0",
    "runner": "terminal",
    "type": "shell",
    "echoCommand": true,
    "presentation" : { "reveal": "always" },
    "tasks": [
          //C++ 컴파일
          {
            "label": "compile for C++",
            "command": "cd ${fileDirname} && cmake . && make",
            "group": "build",

            //컴파일시 에러를 편집기에 반영
            //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher

            "problemMatcher": {
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    // The regular expression. 
                   //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        // 바이너리 실행(Ubuntu)
        {
            "label": "execute",

            "command": "cd ${fileDirname} && ./${workspaceFolderBasename} ",

            "group": "test"
        }
    ]
}
```
* 위의 예제 코드를 compile 하고 execute하면 윈도우 창에 Lena 사진이 보여진다.
