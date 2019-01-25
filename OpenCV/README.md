## OpenCV + Visual Studio 2017

#### 1. System information
```
OS: Windows 10 (64bit)
Tool: Visual Studio 2017
OpenCV v4.0.0
```

#### 2. Environment setting  
+ Windows 10  

제어판 -> 시스템 -> 고급 시스템 설정 -> 고급 탭의 환경변수  

  **System Variable**  
  + 새로 만들기  
    + Variable name: **OPENCV_BUILD**  
    + Variable : **opencv설치경로\build**
  + Path  
    + 편집 -> **%OPENCV_BUILD%\x64\vc15\bin**
+ Visual Studio 2017  

  Project 설정(Property)
  
   Configuration: All, Platform: x64  
 
   + Configuration Properties
   
     + Debugging -> Environment: **PATH=C:\opencv\build\x64\vc15\lib;%PATH%**
   + C/C++
   
     + General -> Additional Include Directories: **$(OPENCV_BUILD)\include**  
   + Linker 
   
     + General -> Additional Library Directories: **$(OPENCV_BUILD)\x64\vc15\lib**  
     + Input -> Additional Dependencies: **opencv_world401.lib;opencv_world401d.lib**  
     
         * Debug: opencv_world400d.lib / Release: opencv_world400.lib
