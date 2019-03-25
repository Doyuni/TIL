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
