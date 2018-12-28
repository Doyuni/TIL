What RenderScript?
-Google에서 만든 programming framework입니다.

Why we need this?
-Android app의 성능 향상
-개발자가 low level에서 제공하는 고성능 API 사용 가능
이미지 처리, computational photography 또는 컴퓨터 비전에 특히 유용
-복잡한 OpenCL 없이 스마트폰의 GPU 계산 능력 사용 가능
- 덕분에 병렬 프로그래밍 가능
-주로 data 병렬 계산을 위해

Feature
-C99 기반의 저수준 고성능 언어
-RS runtime은 멀티 코어 CPU나 GPU처럼 하나의 장치에서 병렬처리가 가능하다.
-디바이스에 직접 컴파일한다.
1. RS script가 LLVM의 바이트 코드로 컴파일된다. 
2. app이 처음 실행될 때 LLVM의 바이트 코드가 안드로이드 기기에서 네이티브 코드로 컴파일된다.
3. 네이티브 코드가 캐시가 되어서 RS 실행할 때 미리  캐시된 네이티브 코드를 가져오기에 매우 빠른 속도
*LLVM: C++ 기반의 오픈소스 compiler (JVM처럼 언어에 가상 머신을 생성하여 언어와 플랫폼에 독립적인 최적화를 실행하게 한다.)

Why we use the RS instead of OpenCV ?
-둘 다 CPU나 GPU 사용 가능 

Performance difference?
http://www.diva-portal.org/smash/get/diva2:1114955/FULLTEXT01.pdf 
Test한 언어
RenserScript intrinsics
-구글이 제공한 알고리즘
-Intrinsics은 이미지를 처리할 때 사용되는 연산을 수행하는 내장된  기능이다. 작은 양의 코드로 높은 성능을 낸다.
Relaxed RenderScript
-성능 향상을 위해 lower floating point precision을 사용한다. CPU에서 64비트 대신 32비트 precision을 사용
C++ using OpenCV
-open source computer vision library인 OpenCV는 이미지 처리를 수행하는데 최적화된 코드를 포함한다. OpenCV Android SDK v.3.2.0은 OpenCV C++ API를 호출하여 사용된다.
개발자는 RenderScript에서 요구된 precision level를 조절할 수 있다
*Relaxed RenderScript 는 IEE 754-2008를 요구하지 않는 Renderscript를 말한다.
Test results
1. color space conversion
스마트폰 카메라로 100개의 연속적인 프레임에서 테스트
RS intrinsic > C++ OpenCV > Relaxed RS
2. Blurring
작은 이미지부터 큰 이미지까지 3개의 다른 이미지에 blurring 알고리즘 적용
큰 이미지에서 구현됨
Box filter
Relaxed RS > C++ OpenCV > RS

Gaussian filter
RS intrinsic > Relaxed RS > C++ OpenCV > RS
3. Grayscaling
이미지 색깔을 회색계열로 변환해주는 기술
C++ OpenCV > RS > Relaxed RS
4. Thresholding
이미지의 판을 찍어내는 듯한 그런 기능..
C++ OpenCV > RS >Relaxed RS

Discussion
1. Color space conversion은 Real time 이미지 프로세싱이기에 높은 성능을 요구한다.




On large images, RenderScript가 Java보다 상당히 빠르다.
Java는 현재 스마트폰 세대에서  advanced image processing은 수행하기엔 어렵다고 간주된다.
하지만 매우 간단한 계산이나 작은 image를 처리할 때는 runtime performance의 차이가 근소하다.
Full floating point precision으로  RenderScript을 구현한 것은 C++보다 더 좋은 성능을 나타내지 못한다.
하지만 floating point precision에 엄격한 요구사항(*IEEE 754)이 없으면 RS가 C++보다 좋은 성능을 보인다. 또한 더 큰 이미지에 알고리즘을 적용시킬 때 low floating point arithmetic precision으로 RS를 구현한 것이 C++보다 더 좋은 성능을 낸다.
* IEEE에서 개발한 부동소수점  방식(최상위 비트 부호 그리고 지수 부분과 가수 부분으로 나뉨)























Java 성능 비용( 자동 메모리 관리 )에 안전성과 편리성을 증진하도록 고안됨.
구글은 Java에 native lang을 사용하는게 유용할 것이라 생각
1.  C나 C++라이브러리 를 재사용
2. 게임이나 물리 엔진같은 장치의 성능 향상을 최대한 사용

GPU acceleration의 사용이 하드웨어의 병렬화 수준을 높이기 떄문에 엄청난 성능 향상을 제공할 수 있다.
하지만 문제는 안드로이드 시스템의 향상된 성능으로 Java보다 다른 언어를 사용하여 얻는 성능 이점이 무엇인지 알기 어려워졌다.
이미지 프로세싱은 많은 엄청난 계산적 프로세스를 포함하고 GPU acceleration 사용을 가능하게 하는 native lang이나 framework로 변경하는게 유용하다고 생각이 들게 한다.

Java는 Oracle에서 개발한 interpreted, 객체지향 프로그래밍 언어이다.  Java는 JVM에서 실행되기 위해 바이트코드로 컴파일된다. 컴파일된 자바 코드는 각 구조마다 컴파일할 필요 없이 어떤 플랫폼에서든 실행될 수 있다.
컴파일된 바이트 코드는 JVM에서 실행될 수 있으며 JVM은 바이트 코들르 CPU가 이해할 수 있는 명령어로 해석한다.























C++
native language, JVM에서 요구되는 translation step을 skip가능 native processor instruction으로 직접 컴파일됨 c++ file → compiler → assmebler → linker → executable file

Performance
runtime performance는 C++이 높을 수 있다. C++은 자동적인 가비지 컬랙션이 부족하고 overhead와 비용이 드는 수행을 하는 힙에 메모리 접근과 할당을 하는 Java와 달리 스택을 사용해 개발자들이 자유롭게 메모리에 빠르게 접근하고 할당할 수 있기 때문이다.

