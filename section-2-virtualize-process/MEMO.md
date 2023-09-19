* Time sharing
not exactly 'concurrent'
* Context switch
stopping program and starting new one

* Machine state
어떤 시점에 process의 상태를 설명하려면? memory, register, information about I/O
memory (에 어떤 instruction, data가 있는지)
register (에 어떤 값들이 있는지) // instruction들이 reg에 있는 값들을 r/w함. ex of register - PC, stack pointer, frame pointer
information about I/O (ex. open files that can be r/w)


* OS에서 제공하는 process API
create, destroy, wait, misc, status

* process를 생성한다는 것은
(1) load code/static data from disk to memory
초기OS는 eager load(program 실행 시에 바로 memory로 땡겨옴) -> modern OS는 paging/swapping 등을 활용해서 lazy load
(2)  memory allocation
stack (local var, function param, return address 채워넣고 각종 argument 초기화(ex. args, argv))
heap(처음에는 작은 공간 할당. 이후 malloc, free 등 호출하면서 커졌다 줄었다.)
(3)  i/o related setup
UNIX에선 each process has three default file descriptors(stdin, stdout, stderr)
이렇게 세 과정 끝나고 나면 entry point인 main으로 넘어가서. OS가 CPU한테 control을 넘기고. process를 실행할 수 있는 것

* Process state
running, ready, blocked, done 등
* OS는 process list로 시스템 전체의 프로세스들을 관리한다. 각 process의 정보는 PCB(process control block. process에 대한 정보를 저장하는 structure) 형태로.

