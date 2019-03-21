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