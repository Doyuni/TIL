Renderscript :Programming framework created by Google

  purpose 
-improve the performance of Android App 
 ex) graphic, image processing, encryption, signal processing, Mathematical  routines
-allow to use high performance API which is provided in low level 
-allow to use the computing power of phone's GPU without the complexity of OpenCL.
-the parallel programming was possible since Android 4.0 thanks to RS


  feature
-a low-level, high performance lang based on C99
-three important concepts
  1. Context
	allow android app to pass and receive data from the Renderscript
  2. Compute kernel
	
3. Allocated Memory



CPU vs GPU
중앙처리장치 CPU, 그래픽처리장치 GPU
둘 다 데이터를 읽고 연산처리를 통해 답을 도출한다. (두뇌역할)
하지만 프로세서 내부 구조의 차이는 명확
내부는 크게 ALU(연산 담당), CU(control unit), cache(data 저장)으로 나뉜다.
-CPU : 직렬 처리 방식(한 번에 한 가지의 명령어만 처리→ALU 많을 필요 x)
	절반 이상은 cache memory가 차지, CPU와 RAM의 속도차이로 발생하는 병목현상 막음
	->CPU가 처리할 data를 미리 RAM에서 불러 cache memory에 임시로 저장->처리속도 상승
	인터넷 서핑, 문서 작성 등에 쓰임
 1위업계 인텔
-GPU : 병렬 처리 방식
	ALU 개수가 많다. (CPU보다  약 100~1000배 차이)
	멀티미디어, 3차원 그래픽과 사운드
	대용량 부동소수점 데이터도 병렬 고속처리를 통해 간단히 계산 가능
 1위업계 엔비디아 

->계산 밀도에 따라 성능 결과가 달라진다.
100MB 이미지 한 장 저장 vs 1MB 이미지 100장
계산 1 번       vs  계산 100번
CPU 승 	 GPU 승

  RenderScript blur vs java based fastblur
-high pixels -> The fastblur didn't even work because of out of memory
-low pixels -> renderscript is more than 8 times faster. 





The Android platform provides two methods for operating outside the traditional Android application boundaries.
1. Native Development Kit
2. RenderScript
Both mechanisms can be useful for 3D rendering and CPU-intensive computations.
  
  RS vs NDK 
-NDK is hard to set up and didn't work for every phone unlike renderscript
-NDK written in code C or C++ and interface with app through the Java Native Interface(JNI)
 Developers should be well versed in both lang.

-Renderscript is based on C99 with new APIs that are ultimately compiled to native code.
 So, there's a learning curve to using the system because the APIs are not.

Aspects of protability
 NDK: leverage existing C/C++
 







Linear programming problems can be defined like this: 
You have different products, and a limited set of resources. 
You want to divide your resources in a way that they are used in the best possible way.
For example, a factory produces different products from a few raw materials, from which there is a limited stock. How many should the factory produce of each product from the available materials, to achieve the highest profit possible?
Although there do exist polynomial algorithms to solve these kind of problems, the most commonly used one is the simplex method, which is not polynomial though, but usually solves problems as efficiently as other polynomial ones.

→ written in Java : time issue
→ rewrite it in a more low-level lang like C or C++

Two solutions
1. NDK

2.Renderscript
-platform-independent
-compiled when building application
-can use the GPU & CPU as well.
 


How to use RenderScript

when use RenderScript from Java Code  : Java
when use single-Source RenderScript : C99-derived kernel lang


1. add two lines
renderscriptTargetApi 24 
renderscriptSupportModeEnabled true

2. create two file(.rs / .rsh) in the rs(dir)

How to communicate between Java and RenderScript code ?
It is not easy to pass values between the two sides.
In RS code, can not allocate dynamic memory, so the object for return value has to be pre-allocated on the Java side.
But if create global variables in the C code, accessors to it will be generated in Java.

ex)
simplex.h

typedef struct __attribute__((packed)) Tableau {
    int rows, columns;
    float matrix[MAX_ROWS * MAX_COLS];
    bool dual_program;
} Tableau_t;
Tableau_t *tableau;

SimplexRS.java
//two classes
ScriptC_simplex script = new ScriptC_simplex(renderScript); 
ScriptField_Tableau tableau = new ScriptField_Tableau(renderScript, 1);
//After creating an instance of the former, can call func defined in RS code.
int rowCount = data.length;
int columnCount = data[0].length;
// all setters have 3 parameters 
// (index(pointer) or struct : 0, value, boolean (copyNow)  true: immediately copied to C struct)
tableau.set_rows(0, rowCount, false);
tableau.set_columns(0, columnCount, false);
tableau.set_dual_program(0, minimize, false);
tableau.set_matrix(0, data, false);
// Copy all values at once to the allocated memory of the struct.
tableau.copyAll();
script.bind_tableau(tableau);



#deadline

render script

openCV

for android 

>simple presentation on 12/31


안드로이드는 매우 다른 구조를 지닌 GPU와 CPU 사이에서 이식성 performance가 필요하다. 만약 CUDA에서 처음으로 소개된 실행모델을 사용하는 OpenCL에 안드로이드가 의존하면 하나의 커널을 만들기가 불가능할 것이

 If you want to apply some filter, blur or some operation that works on the whole image, Renderscript will do wonders. OpenCV also has its advantages. It is very difficult to process image using Renderscript (finding contours, face recognition, pattern matching, etc). Also, if you're working with float data, Renderscript works at least 10-20x faster than OpenCV (native).

RS is a framework for running computationally intensive tasks at high performance on Android, usually used for image processing on Android devices. It accelerates the computation by running on GPUs. Please note that RenderScript is device-dependent. Version problem limits the compatibility of RenderScript.
