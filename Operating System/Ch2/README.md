## Ch2
### OS services
- UI
- Program execution에 대한 환경을 제공해줘야 한다. 프로그램을 메모리에 올리고 동작할 수 있게끔 자원을 할당해줘야 한다.
- I/O 장치들이 동작하도록 제공해야 한다.
- 파일 시스템 관리
- Networking 기능이 기본적으로 탑재가 되어야 하고, process간 소통이 되도록 제공해줘야 한다.
- 에러 감지를 해야한다.
- 자원 할당을 얼마나 누구에게 해줄지 관리해야 한다.
- Accounting: 사용자가 어떤 종류의 자원을 얼마나 사용하고 있는지에 대한 정보를 알고 있어야 한다. 그래야 어떤 것을 죽일지 살릴지 판단 가능

### OS 구조
user가 system calls을 통해 kener level(low level)에서 접근할 수 있는 서비스를 사용할 수 있게 하고 또한 하드웨어에 접근할 수 있어야 한다.
### System calls (중요)
- OS가 제공하는 다양한 서비스들을 접근할 수 있는 프로그래밍 인터페이스
- function의 집합
- API
  - Win32, POSIX, Java API
- kenel 영역에 맘대로 접근해서 막 쓰도록 하지 않고 제공해주는 function만 쓸 수 있게 system call이 존재한다.
- System-call interface
  - User(개발자)입장에서 대부분의 OS interface는 abstraction(굳이 몰라도 되는 형태로 압축되어서 제공되는)으로 숨겨져있기에 User는 시스템 콜의 결과만 확인하면 된다. 즉 OS 입장에서 abstraction을 하고 이를 포장한 형태(System call)로 User에게 제공해준다.
- System call parameter passing
  - register에 값을 저장해놓고 실행 (컴퓨터 입장에서 간단)
  - 메모리를 구조화하여 parameter를 넣고 passing (parameter가 많을 경우 때문에 메모리를 사용한다.)
  - stack을 구상하여 parameter를 push하고 pop하여 사용
- OS 별로 system call API가 다르다.
- C에서 조건문 반복문을 제외하면 거의 다 system call이라고 볼 수 있다.
  - OS가 알아들을 수 있는 System call을 이용해 compile을 한다. 그래서 다른 OS에서 컴파일된 binary file을 실행할 수 없다.
  - 하지만 표준 C 라이브러리 덕분에 같은 코드를 사용해도 컴파일러가 이를 OS에 맞게 컴파일하여 코드만 같다면 다른 환경에서도 컴파일하여 실행할 수 있다. High level 언어는 같아도 compiler와 assembler가 low level로 변역하면 OS에 맞는 언어로 바뀐다. OS에 따라 compiler도 다름 !
- 메모리에 단순히 올려 사용하는 1+1이 system calls를 사용하지 않는 예이다.
  - OS service를 사용하는 것들은 system call이 필요
#### OS Design
- OS는 Policy(중요)와 Mechanism으로 가득차있다.
  - 정책을 만드는 과정에서 방법론을 제시
 _Assembly lang_: HW를 다루기 위해 사용하는 언어
- UNIX 부터 system program과 system call을 나누기 시작했다.

모듈화가 무엇인지 질문하자.
#### System Programs
- 개발과 실행을 위한 편한 환경을 제공해주는 것
- OS를 굳이 나누자면 User application program(지뢰 찾기), System program(탐색기, 없으면 OS를 사용할 수 있나 하는 것들)로 나눌 수 있다.
- 시스템이 동작할 수 있도록 도와주는 프로그램, loader, 방화벽, 작업관리자 등
#### OS structure
- Simple - MS-DOS
  - device drivers에 접근하는게 항상 계층화되어서 나타나지 않고 응용프로그램이 BIOS device drivers에 한 번에 접근할 수 있게 통로를 만들었다는게 특별한 부분이다.
- Non Simple - UNIX
  - kernel을 정의하고 있고 이 위에 작동하는 system program을 정의하고 있다.
  -kernel이 HW에 접근할 수 있는 interface를 만들어 정의하고 있다.
  - 계층화된 구조를 조금씩 가지기 시작했다.
  - 좀더 명확화된 계층 구조를 지니고 있다.
    - 계층마다 하는 일을 구분하고 system call interface를 두어 함부로 접근할 수 없게끔 만들었다.
- Layered Approach
  - 장점: 접근을 예측가능하도록, 다른 계층과 독립적으로 작동할 수 있다. 문제 있는 계층 하나만 수정하면 되므로 수정이 용이하다.
  - 단점: 계층별로 접근하기 힘들다. 하나의 계층이 잘못되면 이 계층을 통해 접근이 불가능하다. 
- Microkernel 
  - kernel이 없으면 할 수 없는 일들을 남겨둔다.
    - interprocess communication
    - memory management
    - CPU scheduling
      - 여러 개의 process가 접근했을 때 어떤 것을 취하고 버릴지 판단
  - 장점: 가볍고, 여러가지 종류의 HW를 옮길 수 있다. (이식성이 좋다.) flexibility가 존재하여 user가 편한대로 수정할 수 있다.
  - 단점: 기능이 많이 없다. 최적화가 안될 가능성이 있어 성능이 떨어질 수 있다. application developer의 오버헤드가 생긴다.(책임이 가해지고, 필요한 디바이스, 파일 시스템 등을 개발해야 한다.)
- Monopoly kernel ? -microkernel과 반대
- Modules
  - kernel에 일단 집어넣지만, 필요할 때만 로드할 수 있게 하자.
  - core kernel을 기준으로 필요할 때만 로드될 수 있게 한다.
  - kernel modules을 붙였다 땠다 할 수 있는 object-oriented
  - boot sequence가 하는 일인 core 부분을 메모리에 올려주는 일을 통해 로드된다 ?..  
- Hybrid Systems - Mac OS X
#### OS debugging
- 어디서 무슨 문제가 생겼는지 확인을 해야 한다.
  - OS 위에서 특정 application에 문제가 생겼을 때
    - core dump: 어떤 프로세스 메모리에서 문제가 생겼는지에 대한 정보
  - OS 자체의 기능에 대해서 문제가 생겼을 때
    - crash dump: 어떤 kernel 메모리에서 문제가 생겼는지에 대한 정보
- Performance profiling을 해주어 Tuning의 기회를 제공한다. 
  - Windows Task manager
#### SYSGEN
- OS가 처음 시작할 때 SYSGEN이 시작하여 CPU가 무엇이고 메모리 크기가 어떻게 되며 어떤 RAM인지 등의 정보를 수집하여 HW에 맞춘다.
- OS는 CPU에게 명령을 보내는 것인데, 이 CPU가 알아들을 수 있는 형태로 명령을 보내는 것이 중요하다. 그렇기 때문에 어떤 CPU인지 OS가 알아야 한다. 그렇기에 OS가 새로운 CPU가 나왔을 때, 그 기능을 제대로 수행하지 못 할 수도 있다.
