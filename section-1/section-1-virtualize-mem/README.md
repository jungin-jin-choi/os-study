```
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: mem <value>\n");
        exit(1);
    }
    int *p;
    p = malloc(sizeof(int));                                      //a1
    assert(p != NULL);
    printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p); //a2
    *p = atoi(argv[1]); // assign value to addr stored in p.      //a3
    while (1) {
        Spin(1);                                                  //a4
            *p = *p + 1;
            printf("(%d) value of p: %d\n", getpid(), *p);
        }
    return 0;
}
```

unistd.h - POSIX OS API 관련
stdio - input/output operation
stdlib.h - mem allocation function
common.h - user defined

```
int *p; 
p = malloc(sizeof(int)); 
assert(p != NULL);
```
integer pointer인 p를 선언하고, integer 사이즈만큼의 메모리를 할당한 뒤 그 메모리의 주소를 p에 할당. 즉 한마디로, integer에 메모리를 동적으로 할당하는 (heap에서) 문법임
```
printf("(%d) addr pointed to by p: %p\n", (int) getpid(), p); //a2 *p = atoi(argv[1]);
```
출력하는 부분에서는, 프로세스 id와, p(즉 주소값)을 출력하는 부분.
atoi로 문자열 argument를 int로 변환한 뒤, 그걸 p의 '값'에 넣고 있음. 즉 p가 가리키는 주소에 값으로 int를 넣는 문법
이후에는 무한루프 돌면서 1초씩 딜레이 주고, p가 가리키는 주소에 값을 1씩 증가시키고 있음.
