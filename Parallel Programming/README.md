### CUDA 설치
* 설치
```
OS  : Windows 10
Tool: Visual Studio 2015  
      CUDA 8.0
```
* 설치 순서: Visual Studio 2015 -> CUDA (Visual 버전에 맞게 설치되기 때문)
* 환경 변수 (자동으로 등록되어 확인만 해준다.)  
제어판 -> 시스템 -> 고급 시스템 설정 -> 환경 변수 -> 시스템 변수 CUDA_PATH 설정 확인

* Visual Studio 설정  
1. 프로젝트 생성 -> 템플릿 부분에 NVIDIA CUDA 8.0 선택하여 프로젝트 생성
2. kernel.cu 파일 확인 후 예제 실행 -> 출력 확인
3. 출력값이 확인되면 .cu 파일에 코드 작성

* OpenCL
  Open Computing Language는 다양한 플랫폼을 통해 실행되는 프로그램을 위한 프레임워크로 CPU, GPU, DSP 그리고 FPGA를 구성한다.
  C99기반의 언어를 명시하며 플랫폼을 조절하고 compute devices에서 프로그램을 실행시키는 위의 devices와 APIs(Application Programming Interfaces)를 프로그래밍 하는데 사용된다. 
  task 기반과 data 기반의 병렬화를 사용하여 병렬 프로그래밍을 위한 표준 인터페이스를 제공한다.
  다양한 devices에서 쓰이지만 하나의 코드가 각 device에 맞게 적절하게 실행되는 것을 보장하지는 않는다.
  다른 OpenCL device는 다른 특징을 갖고 있기 때문이다.
  
    

* OpenMP

* OpenCV for_each
