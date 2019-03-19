# Ch1 Introduction

### 운영체제란?
* 컴퓨터(HW)를 샀을 때 사용자는 응용프로그램을 설치하게 된다. 응용프로그램이 HW가 어떤 종류인지 신경을 쓰지 않아도 가운데에서 해주는 즉 HW와 User 간의 interaction을 제공한다.
* 목적
  * 사용자들이 동작하고자 하는 프로그램들이 쉽게 동작할 수 있고 쉽게 접근할 수 있게 한다.(클릭만으로 실행)
  * 컴퓨터의 활용도를 높여준다.
  * 하드웨어를 효율적으로 사용할 수 있게 해준다.
    * OS가 없다면 모든 응용프로그램들이 HW에 맞게 동작하도록 설계가 되어있으면, resource 분배가 제대로 이루어지지 않아 문제가 생길 수 있다.
### Computer System Structure
* User
* Application programs
* OS
* Hardware
  * I/O devices(마우스, 키보드, 스피커, 프린터, 모니터, 디스크 등)
    * 컴퓨터 입장에서 디스크가 삽입되었다가 빠지므로
### OS는 무엇을 하는가?
* User와 Application(System)의 관점에 따라 목적이 다르다.
* User 입장
  * 편리한가, 빠른가
* Application(System)
  * 제때 자원을 할당해주는가
  * 제어를 제때 해주는가(에러를 막는)
### OS의 정의
* OS는 policy에 맞게 설계되어 있다.
* OS의 보편적인 정의는 없다.
* 좁게 보면 kernel(core 부분: 컴퓨터의 시작부터 끝까지 작동한다.)을 말한다.
  * 그외 기타 부분은 작은 부분의 OS를 말한다.
    * System program, application program
### 컴퓨터는 어떻게 작동하는가?
* 부팅 프로세스
  * 프로세스가 동작하기위해서는 메모리 상에 있어야 하는데 HW는 메모리가 아니다. OS를 동작하기 위해서는 메모리 상에 있어야 한다. 메모리는 전원이 꺼지면 휘발성이라 사라진다. 이 부분을 해결해주는 프로세스가 부팅 프로세스다. ROM에 저장을 해놓고 HW에서 주소를 가져와(firmware) 커널코드를 메모리에 올려놓고 OS가 작동하게 된다. (좀 더 검색해보자.)
### Computer System Organization
* Bus connection
  * 하나의 선으로 한 장치가 여러 장치들에 접근할 수 있는 체제
  * 각 장치들은 memory를 가지려고 하는데 이를 OS가 관리해준다.
### Computer System Operation
* I/O device와 CPU는 프로세스를 따로 가지고 있고 동시에 실행가능하도록 설계되어 있다.
* 각 디바이스는 컨트롤러가 있으며 local buffer를 가지고 있는데 CPU가 data를 main memory에서 또는 로부터 local buffer에 보내거나 가져온다.
* CPU는 할 일들을 맡겨놓고 자신의 일을 하게 된다.
* 디바이스 컨트롤러는 interrupt를 통해서 CPU에게 이를 알린다.
  * CPU에게 interrupt는 작동 중에 다른 장치의 요청이 끝났음을 알릴 때를 말한다.
* CPU는 interrupt가 보통 1byte 단위로 오는데 이는 상당히 많고 어디에서 오는지 모른다. 그래서 interrupt vector를 통해 interrupt의 정보를 관리한다.
* interrupt driven OS system
  * 작업을 맡기고 작업이 끝났음을 보고 받는 정도
### Interrupt Handling
* **polling** 방식: 작업이 끝났는지 계속 확인한다. interrupt를 보고 받지 않고 자신이 정한 시간에 확인하는 방식
  * 계속 신경을 써주어야 하고 작업의 딜레이가 발생할 수 있지만, 자신의 시간을 보장받을 수 있다.
* **vectored interrupt system** 방식
  * 진행 상황 끝났음을 바로 알 수 있다.
* System에 따라 적합한 방식을 선택할 수 있어야 한다.
### Interrupt Timeline
#### context switching
  * 지금까지 한 작업을 저장해놓고 interrupt를 처리하고 다시 저장했던 작업을 찾아서 가져오는 작업, 이 시간을 context switching delay(latency)라고 한다.
* 유저 입장에서 처리하다가 디바이스에서 ?
* multitasking의 핵심도 결국 context switching이다.
#### I/O Structure
* 컴퓨터 외부의 장치를 통틀어 말할 때 peripheral 이라 한다.
* local buffer를 통해 레지스터에 정보를 등록하고 이 정보를 디바이스 컨트롤러가 보고 제어한다.
#### Storage Structure
* 튜링 머신: Alan Turing이 개발한 머신이다
  * 연산, 연산을 읽고 쓸 수 있는 장치, 이를 저장하는 tape가 존재
* Main memory
  * 흔리 RAM이라 하며 CPU와 가장 가까운 형태
  * 대부분 휘발성, 전원이 꺼지면 날라가는 메모리
* Secondary Storage
  * data를 상시 저장할 수 있는 비휘발성 메모리
  * 하드디스크(크고 싸다, CD처럼 생긴 것이 있음), SSD(전기적으로 data를 저장하고 읽을 수 있음)
#### Storage Hierarchy
* process가 접근하는데 걸리는 시간, 비용, 휘발성에 따라 계층구조가 형성된다.
* 어떤 것을 어디에 저장해둘 것인지 policy가 필요하다.
  * OS는 이를 중요시한다.
1. registers
   1. process랑 붙어 있음, 접근이 가장 빠르다.
2. cache
   1. register보단 cpu에서 멀리 떨어져 있지만 접근이 상당히 빠르다.
3. RAM
   1. 위의 저장 디바이스는 너무 비싸다.
   2. 상시적으로 접근하고 싶은 것을 여기에 넣는다.
   3. 여전히 휘발성
4. Solid-State Disk(SSD)
5. Hard disk

#### Caching
- cache에 정보가 있다면 바로 정보를 사용한다.
- 정보가 없다면 cache에 data를 복사하고 사용한다.
- 하지만 가격적인 측면에서 비싸기에 작을 수 밖에 없다.
#### Direct Memory Access Structure
- 10bytes를 전달하는데 10번의 interrupt를 걸어준다. 그렇다면 파일 하나 옮기는데 interrupt가 상당히 많을 것이다. 이를 위해 존재 ? 
- CPU가 관리할 수 없는 현상이 일어날 수 있다.
- CPU의 완전한 micro kernel 부분을 잃고 효율성을 가지는 것
- 폰 노이만 구조의 문제점을 부드럽게 해결하는 장치
#### 폰 노이만 구조
- 컴퓨터를 효율적으로 설계하기 위해 만듦
- 입력 장치에서 data가 입력되면 제어부, 연산/논리부는 메모리부와 data를 주고받으며 연산을 하고 그 결과를 출력 장치로 보낸다.
- harvard 구조와 경쟁
- harvard 구조와 다르게 복잡성은 줄고 단순하다.
- 단 나누어지지 않고 하나로 되어 있어 폰 노이만 bottle neck(병목 현상)으로 느려질 수 있다.
#### 컴퓨터 시스템 구조
- multiprocessors: 하나의 컴퓨터 안에 CPU를 여러 개 놓는다.
  - 컴퓨터를 하나 더 사는 것보단 싸다
  - 프로세스 하나가 잘못 되어도 문제가 없다
- Asymmetric
  - master process가 생성이 되고 일의 분담 역할을 맡는다.
  - 일의 분담을 공평하게 잘한다.
  - master에 문제가 생기면 큰 문제가 된다.
- Symmetric
  - 해야 할 일들이 어딘가에 담기고 이중에서 골라서 수행한다.
  - 어떤 프로세스는 어려운 일만, 어떤 프로세스는 쉬운 일만 가져갈 수 있기에 공평하지 않을 수 있다. 
  - 프로세스 하나에 문제가 생겨도 큰 문제가 되지 않는다.
- 무엇을 사용해야 할까 ?
  - Asymmetric에서 master가 죽으면 일처리가 되지 않는다.
  - ?? 어떤 선택을 할래??
#### Symmetric Multiprocessing Archittecture
- 공통된 variable을 갖는다.
  - cache coherency(나중에 나옴)의 문제가 생긴다.
#### A Dual-core Design
- multicore
  - 가격적으로 이득(하나에 여러 개가 들어 있어서)
#### Clustered System
- 멀티프로세스의 구축과 비슷하다.
- Asymmetric clustering
  - 은행을 생각하면 된다. 서버가 1개가 있다고 치자, 공격을 받아 서버가 죽었다. 거래가 불가능 -> 은행은 서버를 1개를 더 둔다. 이 서버는 동작하는 서버에게 문제가 없는지만 확인하다 문제가 생기면 자신이 작동하는 방식이다. (hot-standby mode)
- Symmetric clustering
  - 여러 개의 컴퓨터들이 각자 여러 개의 일을 한다.
  - throughput 측면에서는 이득이다. (일을 안하는 것이 없으므로)
- 여러 개의 컴퓨터가 서로 interconnected고 공통의 storage 공간이 있다. 그래서 cache coherency문제가 생길 수 있다.
----------
다양한 컴퓨터 시스템에 맞추어 OS가 어떻게 취해야 할지 알아야 한다.
### Operating System Structure
- 여러 개의 작업을 처리하고 싶기 때문에 필요하다.
- 여러 개의 작업은 Multiprogramming, Timesharing 등이 있다.
- Multiprogramming(Batch Processing)
  - 하나의 작업이 끝날 때까지 다음 작업은 수행되지 않고 순차적으로 실행된다.
  - 스케쥴링이 job 단위로 이루어진다. 
    - 이 작업을 먼저, 다른 작업은 나중에 이런식.
  - context switching을 적게 하므로 낭비하는 시간이 적다.
- Timesharing(multitasking)
  - process가 하나인데 동시에 일을 처리할 수 없다.
    - logical extension이다. 실질적으로 멀티태스킹은 아니기에
  - 다만, 아주 짧은 시간 동안 여러 일을 왔다갔다 처리하기에 동시에 처리하고 있음을 느끼게 되는 것이다.
  - interactive computing 
  - context switching을 자주하여 낭비하는 시간이 많다.
  - CPU기반의 스케쥴링
  - swapping: 10개의 process를 동시에 돌리기 위해 메모리에 올려야 하는데 너무 커서 메모리에 올릴 수 없는 경우, 디스크와 메모리 사이를 왔다갔다 하면서 올렸다 뺐다 하는 작업을 말한다. 컴퓨터가 빨라야 한다.

System의 장단점을 파악하고 설계하려는 목적에 맞게 멀티 프로그래밍과 시분할 중 선택해야 한다. 어떤 것이 무조건 좋고 어떤 것이 무조건 나쁜건 없다.
#### OS operation
- interrupt 기반으로 동작한다.
- Hardware interrupt
  - 마우스 입력 등
- OS 입장에서 interrupt 기반으로 Dual mode operation을 한다.
  - Dual mode(User mode & kernel mode)
  - kernel를 보호하는 측면에서 privileged일 때만, system call을 했을 때만 접근할 수 있게 되어 있다.
**System call**  
- User process가 시스템 콜을 하면 kernel mode로 들어가고 처리 후 kernel mode로 나온다.
- kernel mode에서 문제가 생긴다면 ?
  - 안전 장치가 있는 편이다.(특정 시간이 지나면 저절로 나오게 한다.)
#### Process Management
- Program은 disk에 저장되어 있는 passive entity
- Process는 Program의 동적인(active) 형태이다. 즉, 해야 하는 일들
- Process가 끝나면 자원을 가져와야 한다.
**program counter**  
- 다음 수행해야 할 instruction이 무엇인지 명시를 해준다.
- 특히, 멀티 테스킹에서 필요하다. 작업이 어디서 잠깐 중단되었는지 알아야 재개가 가능하다.
- Multi-thread   
  - thread들이 동시에 진행되기에 program counter가 여러 개 필요하다.
#### Process Management Activities(프로세스 관점에서 OS가 할 일)
- 프로세스 생성, 정지, 재개, 죽음
- 프로세스 동기화를 위해 의사소통을 위한 채널이 필요하고 서로 자원 경쟁이 생겼을 때 진전이 없고 막혔을 때 deadlock이 생길 수 있는데 이를 처리해야 할 필요가 있다.
#### Memory 관리(메모리 관점에서 OS가 할 일)
- 프로세스를 실행하기 위해 메모리에 올라와 있어야 하는데 얼마만큼의 공간을 확보해야 하는지 OS가 관리해야 한다.
- 어떤 프로세스가 메모리 공간에 남아있고 빠져야 하는지 관리해야 한다.
- 파일 시스템 관리
#### Mass-storage 관리
- backup
#### data migration
- data를 상위 계층으로 옮기는 것을 말한다.
- 복사를 하는 개념이다보니 상위 계층으로 갈 수록 independent하게 process가 작동하기 때문에 하나의 변수에 작업을 처리한 결과들이 상이할 수 있다.(cache coherency)
#### I/O subsystem
- 입출력 구조에서 OS가 무엇을 해줘야 하는가?
- spooling
  - 프린터는 물리적 현상이 일어나기에 느리다. 빠른 -> 느린 장치
#### Protection and Security (OS는 둘 다 필요)
- Protection
  - internal process 간의 경쟁에 대한 보호
  - ex) 파일의 권한을 특정 프로세스에만 준다.
- Security
  - external attack에 대한 방어
#### Computing environment
- 모바일 환경은 multi tasking에 대해 덜 까다롭다.
- 각각의 환경에 따라 요구하는 것이 다르고 최적화가 잘 되도록 해야 한다.
- Virtualization
  - 가상화 환경 2가지
    1. 여러 개의 OS가 하나의 HW 위에 있어 자원을 얻고자 경쟁한다. (b)
    2. 하나의 OS 위에 vmware가 하나의 응용프로그램으로 OS에게 자원을 할당해달라고 요청한다. (a)
- Cloud Computing
  - 동시에 몇 명이 들어와서 몇 명이 작업할건지 알기 힘들다.
    - SaaS
      - google docs
    - PaaS
      - database 형태를 사용하게 하는
    - IaaS
      - storage로 유지
- Real Time Embedded System
  - 특정 시간 내에 작업을 수행한다는 보장이 있어야 한다. (Real Time)
  - 작은 임베디드 메모리에 OS를 전부 올릴 수는 없다.

**요구사항에 따라 OS를 다르게 설계해야 한다.**
