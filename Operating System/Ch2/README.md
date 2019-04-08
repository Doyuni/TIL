## Ch2
### OS services
- UI
- Program execution�� ���� ȯ���� ��������� �Ѵ�. ���α׷��� �޸𸮿� �ø��� ������ �� �ְԲ� �ڿ��� �Ҵ������ �Ѵ�.
- I/O ��ġ���� �����ϵ��� �����ؾ� �Ѵ�.
- ���� �ý��� ����
- Networking ����� �⺻������ ž�簡 �Ǿ�� �ϰ�, process�� ������ �ǵ��� ��������� �Ѵ�.
- ���� ������ �ؾ��Ѵ�.
- �ڿ� �Ҵ��� �󸶳� �������� ������ �����ؾ� �Ѵ�.
- Accounting: ����ڰ� � ������ �ڿ��� �󸶳� ����ϰ� �ִ����� ���� ������ �˰� �־�� �Ѵ�. �׷��� � ���� ������ �츱�� �Ǵ� ����

### OS ����
user�� system calls�� ���� kener level(low level)���� ������ �� �ִ� ���񽺸� ����� �� �ְ� �ϰ� ���� �ϵ��� ������ �� �־�� �Ѵ�.
### System calls (�߿�)
- OS�� �����ϴ� �پ��� ���񽺵��� ������ �� �ִ� ���α׷��� �������̽�
- function�� ����
- API
  - Win32, POSIX, Java API
- kenel ������ ����� �����ؼ� �� ������ ���� �ʰ� �������ִ� function�� �� �� �ְ� system call�� �����Ѵ�.
- System-call interface
  - User(������)���忡�� ��κ��� OS interface�� abstraction(���� ���� �Ǵ� ���·� ����Ǿ �����Ǵ�)���� �������ֱ⿡ User�� �ý��� ���� ����� Ȯ���ϸ� �ȴ�. �� OS ���忡�� abstraction�� �ϰ� �̸� ������ ����(System call)�� User���� �������ش�.
- System call parameter passing
  - register�� ���� �����س��� ���� (��ǻ�� ���忡�� ����)
  - �޸𸮸� ����ȭ�Ͽ� parameter�� �ְ� passing (parameter�� ���� ��� ������ �޸𸮸� ����Ѵ�.)
  - stack�� �����Ͽ� parameter�� push�ϰ� pop�Ͽ� ���
- OS ���� system call API�� �ٸ���.
- C���� ���ǹ� �ݺ����� �����ϸ� ���� �� system call�̶�� �� �� �ִ�.
  - OS�� �˾Ƶ��� �� �ִ� System call�� �̿��� compile�� �Ѵ�. �׷��� �ٸ� OS���� �����ϵ� binary file�� ������ �� ����.
  - ������ ǥ�� C ���̺귯�� ���п� ���� �ڵ带 ����ص� �����Ϸ��� �̸� OS�� �°� �������Ͽ� �ڵ常 ���ٸ� �ٸ� ȯ�濡���� �������Ͽ� ������ �� �ִ�. High level ���� ���Ƶ� compiler�� assembler�� low level�� �����ϸ� OS�� �´� ���� �ٲ��. OS�� ���� compiler�� �ٸ� !
- �޸𸮿� �ܼ��� �÷� ����ϴ� 1+1�� system calls�� ������� �ʴ� ���̴�.
  - OS service�� ����ϴ� �͵��� system call�� �ʿ�
#### OS Design
- OS�� Policy(�߿�)�� Mechanism���� �������ִ�.
  - ��å�� ����� �������� ������� ����
 _Assembly lang_: HW�� �ٷ�� ���� ����ϴ� ���
- UNIX ���� system program�� system call�� ������ �����ߴ�.

���ȭ�� �������� ��������.
#### System Programs
- ���߰� ������ ���� ���� ȯ���� �������ִ� ��
- OS�� ���� �����ڸ� User application program(���� ã��), System program(Ž����, ������ OS�� ����� �� �ֳ� �ϴ� �͵�)�� ���� �� �ִ�.
- �ý����� ������ �� �ֵ��� �����ִ� ���α׷�, loader, ��ȭ��, �۾������� ��
#### OS structure
- Simple - MS-DOS
  - device drivers�� �����ϴ°� �׻� ����ȭ�Ǿ ��Ÿ���� �ʰ� �������α׷��� BIOS device drivers�� �� ���� ������ �� �ְ� ��θ� ������ٴ°� Ư���� �κ��̴�.
- Non Simple - UNIX
  - kernel�� �����ϰ� �ְ� �� ���� �۵��ϴ� system program�� �����ϰ� �ִ�.
  -kernel�� HW�� ������ �� �ִ� interface�� ����� �����ϰ� �ִ�.
  - ����ȭ�� ������ ���ݾ� ������ �����ߴ�.
  - ���� ��Ȯȭ�� ���� ������ ���ϰ� �ִ�.
    - �������� �ϴ� ���� �����ϰ� system call interface�� �ξ� �Ժη� ������ �� ���Բ� �������.
- Layered Approach
  - ����: ������ ���������ϵ���, �ٸ� ������ ���������� �۵��� �� �ִ�. ���� �ִ� ���� �ϳ��� �����ϸ� �ǹǷ� ������ �����ϴ�.
  - ����: �������� �����ϱ� �����. �ϳ��� ������ �߸��Ǹ� �� ������ ���� ������ �Ұ����ϴ�. 
- Microkernel 
  - kernel�� ������ �� �� ���� �ϵ��� ���ܵд�.
    - interprocess communication
    - memory management
    - CPU scheduling
      - ���� ���� process�� �������� �� � ���� ���ϰ� ������ �Ǵ�
  - ����: ������, �������� ������ HW�� �ű� �� �ִ�. (�̽ļ��� ����.) flexibility�� �����Ͽ� user�� ���Ѵ�� ������ �� �ִ�.
  - ����: ����� ���� ����. ����ȭ�� �ȵ� ���ɼ��� �־� ������ ������ �� �ִ�. application developer�� ������尡 �����.(å���� ��������, �ʿ��� ����̽�, ���� �ý��� ���� �����ؾ� �Ѵ�.)
- Monopoly kernel ? -microkernel�� �ݴ�
- Modules
  - kernel�� �ϴ� ���������, �ʿ��� ���� �ε��� �� �ְ� ����.
  - core kernel�� �������� �ʿ��� ���� �ε�� �� �ְ� �Ѵ�.
  - kernel modules�� �ٿ��� ���� �� �� �ִ� object-oriented
  - boot sequence�� �ϴ� ���� core �κ��� �޸𸮿� �÷��ִ� ���� ���� �ε�ȴ� ?..  
- Hybrid Systems - Mac OS X
#### OS debugging
- ��� ���� ������ ������� Ȯ���� �ؾ� �Ѵ�.
  - OS ������ Ư�� application�� ������ ������ ��
    - core dump: � ���μ��� �޸𸮿��� ������ ��������� ���� ����
  - OS ��ü�� ��ɿ� ���ؼ� ������ ������ ��
    - crash dump: � kernel �޸𸮿��� ������ ��������� ���� ����
- Performance profiling�� ���־� Tuning�� ��ȸ�� �����Ѵ�. 
  - Windows Task manager
#### SYSGEN
- OS�� ó�� ������ �� SYSGEN�� �����Ͽ� CPU�� �����̰� �޸� ũ�Ⱑ ��� �Ǹ� � RAM���� ���� ������ �����Ͽ� HW�� �����.
- OS�� CPU���� ������ ������ ���ε�, �� CPU�� �˾Ƶ��� �� �ִ� ���·� ������ ������ ���� �߿��ϴ�. �׷��� ������ � CPU���� OS�� �˾ƾ� �Ѵ�. �׷��⿡ OS�� ���ο� CPU�� ������ ��, �� ����� ����� �������� �� �� ���� �ִ�.