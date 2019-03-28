## Processes
#### Process Concept
- 동적인 상태일 때, 동작하고 있는 상태인 프로그램을 말한다. task라고도 한다. 프로그램은 어떤 순서에 맞게 동작해야 한다.
- 5가지의 정보가 기본적으로 저장된다.
  *  text section
  *  program counter: 다음 수행해야 하는 instruction 정보를 담고 있다.
  *  Stack: 지역 변수, 일시적 data
  *  Data section
  *  Heap: 동적 메모리 할당
#### Process in memory
- text 프로그램 코드
- data 전역 변수들
- heap과 stack은 동적으로 바뀔 수 있다.
- 왜 stack은 아래로 heap은 위로 ?
  - 메모리 범위를 벗어나지 않도록 하기 위하여
#### Process State
- new: 새로 생성된 상태
- running: 실행중인 상태 
- waiting: event가 생길 때까지 기다리는 상태
- ready: 언제든 실행할 준비가 된 상태
- terminated: 실행 종료된 상태
#### Process life cycle (diagram 참조)
- new가 admit으로 ready queue에 들어간다.
#### Process Control Block (PCB)
- process가 어떻게 관리되는지에 대한 부분 ( OS관점에서 process 선택시 보는 것)
- OS가 무슨 process를 실행하지 판단할 때 list of open files를 본다.
- interrupt 시 context switchng이 발생하는데 이때 지금하는 일, 다음에 해야 하는 일에 대한 정보를 PCB가 갖고있다.
- 각 process마다 PCB를 지니고 있어(process 생성 시 같이 생성됨) multitasking 시에 각 process의 PCB들이 저장되고 다시 적재된다.
- idle = context switching latency
- PCB를 fetch하고 load하는 것도 OS와 processor가 함께 한다.
- 어디까지 수행되었는지, 메모리 할당은 얼마나 받았는지 
- Process라는 것 자체가 1개 이상의 Thread로 만들어 질 수 있다.
  - process state랑 id는 같지만 그 아래는 다 다르다. multiplex
#### Process Scheduling
* 어떤 시간대에 어떤 process가 실행될지 결정한다. (지금이 기준이다.)
* Process scheduler는 CPU에서 다음에 실행될 수 있는 프로세스들 중 선택을 한다.
* 각 queue에는 PCB가 들어가 있다.
* Job queue - 모든 프로세스의 집합
* Ready queue
* Device queue
  * 각 I/O device별로 device를 관리한다.
#### Schedulers
* Short-term scheduler(CPU scheduler or process scheduler)
  * 굉장히 자주 돌며 누가 실행되어야 하는지(CPU를 사용하는지) 확인해주는 스케쥴러
  * 시간을 엄청 많이 나누어 그 순간마다 여러 프로세스를 실행시키는 즉, 멀티테스킹을 하게 해주는 스케쥴러이다.
  * ready queue에서 빼내어 실행시킨다.
* Long-term scheduler
  * ready queue에 넣을 수 있는 프로세스를 확인하고 넣어준다.
  * 일을 안하면 ready queue에 프로세스를 잘 안넣어주게 되는데 이렇게 되면 short-term scheduler는 있는 것만으로 실행되게 하므로, 멀티테스킹이 힘들어진다. 그래서 long term은 멀티프로그래밍의 정도를 제어한다고 볼 수 있다.
  * I/O bound 와 CPU bound process를 확인하여 전반적인 시스템 유틸리티가 높아지도록 밸런스를 조정해주어야 한다.
* Medium-term scheduler
  * 한정적인 메모리에서 실행될 process와 아직 실행하지 않아도 되는 process를 실행시키기 위해 아직 실행하지 않아도 되는 process를 메모리에서 제거하고 disk에 두고 그 자리에 실행될 process를 넣어준다.  
  이를 **swapping**이라 하며 medium term scheduler가 담당한다.
  * Performance(속도)가 느려지지만 여러 프로세스를 실행시키기 위해서는 꼭 필요한 작업이다.
#### Multitasking in Mobile System
* foreground service : UI에 나타나는 프로세스
* background service : 카카오톡, Music
  * 아주 짧은 task들만 가능하다.
#### Context Switch (중요 !)
* interrupt가 들어오는 순간 발생한다.
* PCB에 data를 저장, 새로운 PCB에서 data를 load한다.  
* Context switch time은 overhead
* 상태를 저장할 수 있는 공간이 제한적이라 필요하다.
* 조금 더 많은 registers를 제공하면 time을 줄일 수도 있다.
#### Life cycle of Process
* Creation
  * OS 부팅 과정에서 첫 process(init)가 생성된다. OS가 동작하기 위한 process들을 생성해준다. 생성된 process들은 또 다른 process들을 생성해주는 형태로 진행된다. - Process Tree 
  * 각 process에는 각기 다른 id를 갖고 있다.
  * 자원 관리 - OS 정책에 따라 달라진다.
  * 실행 관리 - 부모 자식 동시에 실행, 자식이 끝나면 부모 실행(page 3.15 참고)
  * Linux에서는 Process를 생성한다는 것을 fork()라고 한다.
    * Parent 복사본 or 독립적인 프로그램 2가지 유형으로 생성된다.
    * fork()는 하나의 process를 두 개로 분리시키는 작업이다.
    * fork()를 하면 부모 process와 똑같이 만들어진다.
      * 주소와 id만 다르다. 
    * exec()계열 함수를 사용하면 fork()한 process의 contents를 변경해준다.
    * exec()할 때 메모리를 더 필요로 하면 OS에게 요청을 해준다.
    * Thread가 3개, 그 중 하나가 fork()를 호출한다면 3개의 thread를 생성하는가 아니면 process를 생성하는가 ? OS에 따라 다르다.
    * Linux에서는 process 단위로 fork()를 한다.
  * 그렇다면 parent와 child 중 누가 먼저 실행될까 ? -> 모른다.
    * scheduler 마음이다. (wati를 걸지 않았기 때문에 경쟁적으로 실행된다.) ready queue에 둘 다 넣어지고 이는 scheduler가 선택한다.
    * wait가 걸리면 child가 끝날 때까지 parent가 기다린다.
  * parent가 wait()하고 child가 exec()를 하도록 구분해주어야 한다.
    * fork()의 return 값이 0이면 child, 0이 아니면 parent이다. parent인 경우 return 값이 방금 생성시킨 child의 id이다.
* Termination
  * 프로그램이 종료될 때 exit()이라는 시스템 콜이 호출이 된다. 
  * Resource를 deallocate !
  * wait()는 단순히 기다리는게 아닌 resource allocate & deallocate를 담당하는 프로세스에게 init을 시키기 위함이다.
  * abort(), child에게 resource를 allocate를 했는데 문제가 발생할 때 사용
  * cascading termination
    * 부모 프로세스가 종료되면 모든 자식 프로세스를 abort()한다. (OS가 부모 프로세스가 종료되는걸 발견하자마자 자식 프로세스들은 abort())
    * orphan process
      부모 프로세스가 없는 경우로, init()에 가져다 붙인다.  부모 혼자 wait() 호출 없이 종료된 경우  
      부모 프로세스가 자식 프로세스보다 먼저 종료된 경우
    * zombie process
      종료될 때까지도 wait()를 호출하는 parent가 없는 경우로, parent가 메모리 회수 작업을 해줘야 하는데 해주지 않는 경우  
      부모 프로세스가 있고 자식 프로세스는 종료되었는데 wait()를 통해 메모리 회수를 해주지 않는 경우를 말한다.
    * 메모리 관리 측면에서 두 프로세스를 신경써야 한다.
    * OS가 background에서 프로세스를 관리하는 것 또한 프로세스이기에 두 프로세스를 찾아서 대처를 해야하는 방안이 있어야 한다.
    * wait를 한다고 꼭 해결되는 것은 아니다. cascading termination이 아니라면? 고아 프로세스가 생길 수 있음.
#### Interprocess Communication (IPC)
* Independent
  * 굳이 다른 프로세스와의 대화는 필요없고 프로세스 내에 해야 할 모든 일이 있는 경우
* Cooperation
  * 서로 프로세스간 대화를 해야하고 정보를 주고 받고 협력을 해야 하는 경우
  * 정보공유, 계산속도 향상, 모듈, 편리성을 위해서 한다.
  * 모듈성을 지니기 때문에 분리가 가능하고(ex 크롬 창 하나를 닫는다고 나머지가 종료되지는 않는다.) 서로 상호작용을 하기 때문에 영향을 조금이라도 끼칠 수 있다.
* Two model (프로세스들이 통신을 하기 위한)
  * shared memory  
  메모리 공간 어딘가에 공유하고자 하는 메모리를 만들고 둘 다 읽고 쓰도록 접근할 수 있도록 한다. 이는 OS가 할당해준다.
  * message passing  
  특정 프로세스들에게 전달하고자 하는 정보를 메시지 형식으로 만들고 이 메시지를 주고받는 형식이다. 소켓으로 가능하다.
  * 장단점
* message passing이 data를 좀더 explicit(명확하게) 준다.(어떠 data를 누구에게 줄 지 명확) 하지만, 서로 주고 받기 위해 메시지 형식으로 만들고 전달해야 하기 때문에 느리다. overhead가 발생  
메시지 큐에 메시지를 넣어 보내줘야 하는데 이를 위해 user space에서 kernel space로 옮겨주는 것이 필요(data copying, cross protection domain)  
* shared memory는 data에 빠른 접근이 가능하다. A라는 프로세스가 공유 메모리에 있는 data에 접근해서 연산을 하려고 할 때, B라는 프로세스가 접근해서 가져가려 할 때 문제가 생긴다. (동기화 문제)
* 동기화 관점에서 볼 때 shared memory가 불리하다.
#### Producer-Consumer Problem  
buffer(임시 저장소)  
* unbounded-buffer는 무제한 크기의 버퍼
* bounded-buffer는 고정된 크기의 버퍼
* consumer입장에서는 data를 underflow하지 않다면 읽는, producer입장에서는 data를 overflow하지 않다면 데이터를 넣는 작업을 한다.
**shared memory solution**
* OS는 메모리만 할당, 프로세스들이 독립적으로 communication을 관리한다.
* 완벽은 아니지만 synchronization을 어느정도 제공한다.
**message passing**  
* 메시지의 크기가 동적인경우
  * 정적으로 정한 크기보다 작을 때, 크기보다 클 때 유용하다.  작으면 메모리 낭비를 막을 수 있고, 클 때는 굳이 나누지 않고 한번에 보낼 수 있다.
* 메시지의 크기가 정적인경우
  * 크기가 정해져 있기에 메시지 파싱이 쉽고 빠르다.
* 분산환경에서 유용하게 쓰인다.
* communication link를 만들어야 한다.
* Direct Communication (주소를 명시)
  * Q라는 process가 P라는 process에게 받고싶으면 receive(받고 싶다는) 메시지를 보내고 보내고 싶으면 send(보낸다)메시지를 보낸다.
  * 한 쌍에 하나의 link가 생긴다. 보통 양방향
  * Symmetric links
* Indirect(mailbox인 message queue를 사용)
  * Mailbox가 존재하여 이곳에 message를 넣으면 누군가 가져가는 방식 (1:1 pair link가 아니고 explict하게 명시하지 않음.)
  * message sharing의 문제가 생긴다.
    * mailbox에 있는 message를 누가 먼저 가져갈까 ?  
    OS가 정해준다. 최대 2명만 mailbox를 공유하도록, 오직 한 명만 메시지를 가져가도록 등...
#### Synchronization
* message passing에서도 동기화 문제가 생길 수 있다.
* block sending
  메시지를 보내고 정상적으로 받는 시간까지 기다린다.(block 상태)
* blocking receive  
  메시지를 받을 때까지 기다린다.(block상태)
* non-blocking  
  메시지를 보내고 끝, 메시지 오면 그때 받는 경우를 말한다.
* rendezvous 둘 다(send, receive) blocking하는 방식
#### Buffering
* rendezvous 방식이면 임시저장공간이 필요 없다. (zero capacity 또는 no buffer)
* non-blocking에서는 bounded capacity를 사용한다.
* unbounded capacity 서버가 기다릴 필요 없이 계속 받아들인다.
  이론적으로 overflow가 없고 실제로 존재하지 않음(메모리가 한정되어 있으니까). 모델링에만 쓰임
#### Remote Procedure Calls(RPC)
* Procedure call을 원격으로 보낸다. ex 이런 (함수)계산을 해줘
* stubs, 사전에 동의가 되어 있는 상태에서 서로의 PC 사이에 communication을 위해 통역을 해주는 역할을 한다.(marshalling이라 한다.) endian(big-endian little-endian)이 다를 때 marshalling 작업 필요
### Pipes
* process끼리 통신할 수 있는 가장 단순한 방법
#### Ordinary pipes
* 통로를 하나 열어주고 한 쪽으로 data를 주고 다른 쪽에서 data를 받는다.
#### Named pipes
* mkfifo를 통해 파이프 이름을 지정? 할 수 있다.