## Processes
#### Process Concept
- ������ ������ ��, �����ϰ� �ִ� ������ ���α׷��� ���Ѵ�. task��� �Ѵ�. ���α׷��� � ������ �°� �����ؾ� �Ѵ�.
- 5������ ������ �⺻������ ����ȴ�.
  *  text section
  *  program counter: ���� �����ؾ� �ϴ� instruction ������ ��� �ִ�.
  *  Stack: ���� ����, �Ͻ��� data
  *  Data section
  *  Heap: ���� �޸� �Ҵ�
#### Process in memory
- text ���α׷� �ڵ�
- data ���� ������
- heap�� stack�� �������� �ٲ� �� �ִ�.
- �� stack�� �Ʒ��� heap�� ���� ?
  - �޸� ������ ����� �ʵ��� �ϱ� ���Ͽ�
#### Process State
- new: ���� ������ ����
- running: �������� ���� 
- waiting: event�� ���� ������ ��ٸ��� ����
- ready: ������ ������ �غ� �� ����
- terminated: ���� ����� ����
#### Process life cycle (diagram ����)
- new�� admit���� ready queue�� ����.
#### Process Control Block (PCB)
- process�� ��� �����Ǵ����� ���� �κ� ( OS�������� process ���ý� ���� ��)
- OS�� ���� process�� �������� �Ǵ��� �� list of open files�� ����.
- interrupt �� context switchng�� �߻��ϴµ� �̶� �����ϴ� ��, ������ �ؾ� �ϴ� �Ͽ� ���� ������ PCB�� �����ִ�.
- �� process���� PCB�� ���ϰ� �־�(process ���� �� ���� ������) multitasking �ÿ� �� process�� PCB���� ����ǰ� �ٽ� ����ȴ�.
- idle = context switching latency
- PCB�� fetch�ϰ� load�ϴ� �͵� OS�� processor�� �Բ� �Ѵ�.
- ������ ����Ǿ�����, �޸� �Ҵ��� �󸶳� �޾Ҵ��� 
- Process��� �� ��ü�� 1�� �̻��� Thread�� ����� �� �� �ִ�.
  - process state�� id�� ������ �� �Ʒ��� �� �ٸ���. multiplex
#### Process Scheduling
* � �ð��뿡 � process�� ������� �����Ѵ�. (������ �����̴�.)
* Process scheduler�� CPU���� ������ ����� �� �ִ� ���μ����� �� ������ �Ѵ�.
* �� queue���� PCB�� �� �ִ�.
* Job queue - ��� ���μ����� ����
* Ready queue
* Device queue
  * �� I/O device���� device�� �����Ѵ�.
#### Schedulers
* Short-term scheduler(CPU scheduler or process scheduler)
  * ������ ���� ���� ���� ����Ǿ�� �ϴ���(CPU�� ����ϴ���) Ȯ�����ִ� �����췯
  * �ð��� ��û ���� ������ �� �������� ���� ���μ����� �����Ű�� ��, ��Ƽ�׽�ŷ�� �ϰ� ���ִ� �����췯�̴�.
  * ready queue���� ������ �����Ų��.
* Long-term scheduler
  * ready queue�� ���� �� �ִ� ���μ����� Ȯ���ϰ� �־��ش�.
  * ���� ���ϸ� ready queue�� ���μ����� �� �ȳ־��ְ� �Ǵµ� �̷��� �Ǹ� short-term scheduler�� �ִ� �͸����� ����ǰ� �ϹǷ�, ��Ƽ�׽�ŷ�� ���������. �׷��� long term�� ��Ƽ���α׷����� ������ �����Ѵٰ� �� �� �ִ�.
  * I/O bound �� CPU bound process�� Ȯ���Ͽ� �������� �ý��� ��ƿ��Ƽ�� ���������� �뷱���� �������־�� �Ѵ�.
* Medium-term scheduler
  * �������� �޸𸮿��� ����� process�� ���� �������� �ʾƵ� �Ǵ� process�� �����Ű�� ���� ���� �������� �ʾƵ� �Ǵ� process�� �޸𸮿��� �����ϰ� disk�� �ΰ� �� �ڸ��� ����� process�� �־��ش�.  
  �̸� **swapping**�̶� �ϸ� medium term scheduler�� ����Ѵ�.
  * Performance(�ӵ�)�� ���������� ���� ���μ����� �����Ű�� ���ؼ��� �� �ʿ��� �۾��̴�.
#### Multitasking in Mobile System
* foreground service : UI�� ��Ÿ���� ���μ���
* background service : īī����, Music
  * ���� ª�� task�鸸 �����ϴ�.
#### Context Switch (�߿� !)
* interrupt�� ������ ���� �߻��Ѵ�.
* PCB�� data�� ����, ���ο� PCB���� data�� load�Ѵ�.  
* Context switch time�� overhead
* ���¸� ������ �� �ִ� ������ �������̶� �ʿ��ϴ�.
* ���� �� ���� registers�� �����ϸ� time�� ���� ���� �ִ�.
#### Life cycle of Process
* Creation
  * OS ���� �������� ù process(init)�� �����ȴ�. OS�� �����ϱ� ���� process���� �������ش�. ������ process���� �� �ٸ� process���� �������ִ� ���·� ����ȴ�. - Process Tree 
  * �� process���� ���� �ٸ� id�� ���� �ִ�.
  * �ڿ� ���� - OS ��å�� ���� �޶�����.
  * ���� ���� - �θ� �ڽ� ���ÿ� ����, �ڽ��� ������ �θ� ����(page 3.15 ����)
  * Linux������ Process�� �����Ѵٴ� ���� fork()��� �Ѵ�.
    * Parent ���纻 or �������� ���α׷� 2���� �������� �����ȴ�.
    * fork()�� �ϳ��� process�� �� ���� �и���Ű�� �۾��̴�.
    * fork()�� �ϸ� �θ� process�� �Ȱ��� ���������.
      * �ּҿ� id�� �ٸ���. 
    * exec()�迭 �Լ��� ����ϸ� fork()�� process�� contents�� �������ش�.
    * exec()�� �� �޸𸮸� �� �ʿ�� �ϸ� OS���� ��û�� ���ش�.
    * Thread�� 3��, �� �� �ϳ��� fork()�� ȣ���Ѵٸ� 3���� thread�� �����ϴ°� �ƴϸ� process�� �����ϴ°� ? OS�� ���� �ٸ���.
    * Linux������ process ������ fork()�� �Ѵ�.
  * �׷��ٸ� parent�� child �� ���� ���� ����ɱ� ? -> �𸥴�.
    * scheduler �����̴�. (wati�� ���� �ʾұ� ������ ���������� ����ȴ�.) ready queue�� �� �� �־����� �̴� scheduler�� �����Ѵ�.
    * wait�� �ɸ��� child�� ���� ������ parent�� ��ٸ���.
  * parent�� wait()�ϰ� child�� exec()�� �ϵ��� �������־�� �Ѵ�.
    * fork()�� return ���� 0�̸� child, 0�� �ƴϸ� parent�̴�. parent�� ��� return ���� ��� ������Ų child�� id�̴�.
* Termination
  * ���α׷��� ����� �� exit()�̶�� �ý��� ���� ȣ���� �ȴ�. 
  * Resource�� deallocate !
  * wait()�� �ܼ��� ��ٸ��°� �ƴ� resource allocate & deallocate�� ����ϴ� ���μ������� init�� ��Ű�� �����̴�.
  * abort(), child���� resource�� allocate�� �ߴµ� ������ �߻��� �� ���
  * cascading termination
    * �θ� ���μ����� ����Ǹ� ��� �ڽ� ���μ����� abort()�Ѵ�. (OS�� �θ� ���μ����� ����Ǵ°� �߰����ڸ��� �ڽ� ���μ������� abort())
    * orphan process
      �θ� ���μ����� ���� ����, init()�� ������ ���δ�.  �θ� ȥ�� wait() ȣ�� ���� ����� ���  
      �θ� ���μ����� �ڽ� ���μ������� ���� ����� ���
    * zombie process
      ����� �������� wait()�� ȣ���ϴ� parent�� ���� ����, parent�� �޸� ȸ�� �۾��� ����� �ϴµ� ������ �ʴ� ���  
      �θ� ���μ����� �ְ� �ڽ� ���μ����� ����Ǿ��µ� wait()�� ���� �޸� ȸ���� ������ �ʴ� ��츦 ���Ѵ�.
    * �޸� ���� ���鿡�� �� ���μ����� �Ű��� �Ѵ�.
    * OS�� background���� ���μ����� �����ϴ� �� ���� ���μ����̱⿡ �� ���μ����� ã�Ƽ� ��ó�� �ؾ��ϴ� ����� �־�� �Ѵ�.
    * wait�� �Ѵٰ� �� �ذ�Ǵ� ���� �ƴϴ�. cascading termination�� �ƴ϶��? ��� ���μ����� ���� �� ����.
#### Interprocess Communication (IPC)
* Independent
  * ���� �ٸ� ���μ������� ��ȭ�� �ʿ���� ���μ��� ���� �ؾ� �� ��� ���� �ִ� ���
* Cooperation
  * ���� ���μ����� ��ȭ�� �ؾ��ϰ� ������ �ְ� �ް� ������ �ؾ� �ϴ� ���
  * ��������, ���ӵ� ���, ���, ������ ���ؼ� �Ѵ�.
  * ��⼺�� ���ϱ� ������ �и��� �����ϰ�(ex ũ�� â �ϳ��� �ݴ´ٰ� �������� ��������� �ʴ´�.) ���� ��ȣ�ۿ��� �ϱ� ������ ������ �����̶� ��ĥ �� �ִ�.
* Two model (���μ������� ����� �ϱ� ����)
  * shared memory  
  �޸� ���� ��򰡿� �����ϰ��� �ϴ� �޸𸮸� ����� �� �� �а� ������ ������ �� �ֵ��� �Ѵ�. �̴� OS�� �Ҵ����ش�.
  * message passing  
  Ư�� ���μ����鿡�� �����ϰ��� �ϴ� ������ �޽��� �������� ����� �� �޽����� �ְ�޴� �����̴�. �������� �����ϴ�.
  * �����
* message passing�� data�� ���� explicit(��Ȯ�ϰ�) �ش�.(� data�� �������� �� �� ��Ȯ) ������, ���� �ְ� �ޱ� ���� �޽��� �������� ����� �����ؾ� �ϱ� ������ ������. overhead�� �߻�  
�޽��� ť�� �޽����� �־� ������� �ϴµ� �̸� ���� user space���� kernel space�� �Ű��ִ� ���� �ʿ�(data copying, cross protection domain)  
* shared memory�� data�� ���� ������ �����ϴ�. A��� ���μ����� ���� �޸𸮿� �ִ� data�� �����ؼ� ������ �Ϸ��� �� ��, B��� ���μ����� �����ؼ� �������� �� �� ������ �����. (����ȭ ����)
* ����ȭ �������� �� �� shared memory�� �Ҹ��ϴ�.
#### Producer-Consumer Problem  
buffer(�ӽ� �����)  
* unbounded-buffer�� ������ ũ���� ����
* bounded-buffer�� ������ ũ���� ����
* consumer���忡���� data�� underflow���� �ʴٸ� �д�, producer���忡���� data�� overflow���� �ʴٸ� �����͸� �ִ� �۾��� �Ѵ�.
**shared memory solution**
* OS�� �޸𸮸� �Ҵ�, ���μ������� ���������� communication�� �����Ѵ�.
* �Ϻ��� �ƴ����� synchronization�� ������� �����Ѵ�.
**message passing**  
* �޽����� ũ�Ⱑ �����ΰ��
  * �������� ���� ũ�⺸�� ���� ��, ũ�⺸�� Ŭ �� �����ϴ�.  ������ �޸� ���� ���� �� �ְ�, Ŭ ���� ���� ������ �ʰ� �ѹ��� ���� �� �ִ�.
* �޽����� ũ�Ⱑ �����ΰ��
  * ũ�Ⱑ ������ �ֱ⿡ �޽��� �Ľ��� ���� ������.
* �л�ȯ�濡�� �����ϰ� ���δ�.
* communication link�� ������ �Ѵ�.
* Direct Communication (�ּҸ� ���)
  * Q��� process�� P��� process���� �ް������ receive(�ް� �ʹٴ�) �޽����� ������ ������ ������ send(������)�޽����� ������.
  * �� �ֿ� �ϳ��� link�� �����. ���� �����
  * Symmetric links
* Indirect(mailbox�� message queue�� ���)
  * Mailbox�� �����Ͽ� �̰��� message�� ������ ������ �������� ��� (1:1 pair link�� �ƴϰ� explict�ϰ� ������� ����.)
  * message sharing�� ������ �����.
    * mailbox�� �ִ� message�� ���� ���� �������� ?  
    OS�� �����ش�. �ִ� 2�� mailbox�� �����ϵ���, ���� �� �� �޽����� ���������� ��...
#### Synchronization
* message passing������ ����ȭ ������ ���� �� �ִ�.
* block sending
  �޽����� ������ ���������� �޴� �ð����� ��ٸ���.(block ����)
* blocking receive  
  �޽����� ���� ������ ��ٸ���.(block����)
* non-blocking  
  �޽����� ������ ��, �޽��� ���� �׶� �޴� ��츦 ���Ѵ�.
* rendezvous �� ��(send, receive) blocking�ϴ� ���
#### Buffering
* rendezvous ����̸� �ӽ���������� �ʿ� ����. (zero capacity �Ǵ� no buffer)
* non-blocking������ bounded capacity�� ����Ѵ�.
* unbounded capacity ������ ��ٸ� �ʿ� ���� ��� �޾Ƶ��δ�.
  �̷������� overflow�� ���� ������ �������� ����(�޸𸮰� �����Ǿ� �����ϱ�). �𵨸����� ����
#### Remote Procedure Calls(RPC)
* Procedure call�� �������� ������. ex �̷� (�Լ�)����� ����
* stubs, ������ ���ǰ� �Ǿ� �ִ� ���¿��� ������ PC ���̿� communication�� ���� �뿪�� ���ִ� ������ �Ѵ�.(marshalling�̶� �Ѵ�.) endian(big-endian little-endian)�� �ٸ� �� marshalling �۾� �ʿ�
### Pipes
* process���� ����� �� �ִ� ���� �ܼ��� ���
#### Ordinary pipes
* ��θ� �ϳ� �����ְ� �� ������ data�� �ְ� �ٸ� �ʿ��� data�� �޴´�.
#### Named pipes
* mkfifo�� ���� ������ �̸��� ����? �� �� �ִ�.