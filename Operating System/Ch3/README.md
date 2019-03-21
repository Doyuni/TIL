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