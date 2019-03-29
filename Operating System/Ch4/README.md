## Ch4 : Threads
### Basics
* process 안에 최소 1개의 thread가 존재한다.
* process 1번에 thread 1, 2가 있다. 이때 수행 단위는 thread
* 각 thread별로 ID, PC, 레지스터, 스택(지역 변수가 들어가는)
* code section, data section(전역 변수)와 OS가 가진 resource들을 공유한다.
* 여러 가지 일들을 동시 다발적으로 할 때 일을 나눠서 할당하고자 할 때 쓰인다.
* 프로세스를 쓰지 않는 이유는 ? fork()를 하여 프로세스가 생성되는데 이는 복제를 하는 것이라 하나만 생성하는 thread보다 무거울 수 밖에 없다.
* code, data, files은 공유 / 스택과 레지스터는 개별로 관리한다.
* context swtiching이 일어날 때 PCB에 pc register 값과 각 register를 저장해놓는다. (process to process)
* PCB간 통째로 교환이 이루어지는게 process간 context switching이라면 PCB의 일부(thread)만 교환이 이루어지는게 thread간 context switching이다.
* thread간 context switching이 일어날 때 같은 프로세스에 있더라도 register를 독립적으로 사용하기에 이 값을 저장하고 가져와야 한다.
#### 멀티 쓰레드 프로그램
* 하나의 프로그램을 2개 이상의 객체가 수행하는 것
* multithread server 구조
  * 동시 다발적으로 일어나는 일들을 thread로 구현이 가능하다.
  * server data 분리
* 장점
  * 지속 가능한 반응성
  * 자원 공유가 프로세스보다 효율적이다.
    * 프로세스간 공유는 메시지 패싱, shared memory는 외적인 공간을 써서 하지만 thread는 내부적으로 가능하다.
  * 경제성
    * 프로세스간 context switching 보다 가볍고 효율적 (PCB를 통째로 가져오고 빼는 작업이 생략될 수 있음)
  * 규모
#### Multicore programming
* data splitting
  * 동기화 문제를 방지하고자 적절히 나눠줘야 한다.
**Parallelism**    
  * multi core system에서 가능한 term이다.
  * 지금 바로 동시에 수행한다.
  * 그 시간에 하나의 task가 아닌 여러 tasks를 동시에 수행한다.
**Concurrency**
  * 일정 시간에 tasks를 수행한다.
  * 하나의 core에서 말할 수 있다.
  * ex 2ms간 무슨 일을 했어 ? t1, t2, t3 했어
* Data parallelism
  * data 자체를 병렬화
* Task parallelism
  * thread 역할을 분산
* thread 개수가 증가할 수록 HW의 support가 필요하다.
  * core 하나에 여러 개의 thread를 지원하기 시작
  * 빠른 교환으로 하나의 core에 여러 개의 thread가 적재될 수 있다.
* thread, process serial하게 수행하는 구간, parallel하게 수행하는 구간이 따로 있다.
  * thread 간에 data를 교환하는 작업이 serial하기에 완벽한 parallel이 아니기 때문에 core를 하나 더 들린다고 성능이 2배로 늘어나는 것은 아니다. 
* User thread
  * 보통 코드에서 만든 thread로 (응용된 thread) 이 thread를 kernel thread와의 relationship이 존재해야 user thread가 정상적으로 동작이 가능하다.
  * OS 입장에서는 자원이 한정적이기 때문에 kernel thread를 따로 만들어 관리하여 User thread와 연결될 때 User thread를 수행할 수 있도록 한다. 그래서 User thread를 엄청나게 만들어도 문제가 일어나지 않도록 한다.
* Kernel thread
  * kernel 자체에서 제공, HW와 연결, User thread의 악용을 방지하기 위해, HW의 자원을 활용하기 위해 존재 
### Models
#### Many-to-One
* User thread가 여러 개지만 하나의 kernel thread만 존재하여 이것에 접근하기 위해 경쟁하는 구도이다. 
* 하나의 User thread가 kernel thread와 관계를 설정하고, 그 thread가 독점하는 문제가 생길 수 있다. multicore system이 있다고 하더라도 커널 thread가 하나이기에 병렬로 수행 불가능
* kernel design이 상당히 쉽다.
#### One-to-One
* User thread 하나당 kernel thread 하나
* OS의 자원이 충분하다면 충분히 활용이 가능한 모델이다.
* concurrrency 측면에서 상당히 좋다.
* 각 User thread가 kernel thread를 여러 개를 원한다면 문제가 생길 수 있기에 User thread에 제한을 둬야 한다.
* blocking이 일어나지 않는다.
#### Many-to-Many
* kernel에서 조금 부담스러운 (User thread 만 개, kernl thread 500개) 환경에서 blocking 가능성은 적지만 Many-to-One처럼 어떤 User thread가 kernel thread와 관계를 설정할지 정해줘야 한다. 
* LWP가 각 kernel thread가 어떤 User thread와 연결할지 정해준다.
#### Two-level
* Many to Many와 비슷하지만 응용 thread가 정말 중요하다고 생각되면 blocking 되지 않도록 하나의 kernel thread와 연결시켜 줄 수 있는 모델이다.
#### Thread는 어떻게 만들어질까 ?
* thread libraries가 있어 여기서 thread를 생성하고 없앤다.
* Pthread가 가장 대중적인 방식으로, API specification(어떤 것을 제공해줘야 하는지 명시됨)이다.
* 표면적으로 보이는 function의 이름만 통일되어 있고 내부적으로 thread가 구현되는건 OS마다 다르다.
* pthread_create에서 thread를 만들고 thread가 끝나면 pthread_join(process의 wait과 유사)으로 오게끔 동작한다. 프로세스에 thread가 있기 때문에 thread의 자원은 프로세스로 다시 돌아가는게 일반적이다.
* CPU가 실행시켜주는 thread는 kernel level thread이다.