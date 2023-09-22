```
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
```

> [!NOTE] Header file 명시하기
> stdio.h - standard C library for input/output 
> stdlib.h - standard C library for memory allocation function
> common.h - user defined header file 

```
int main(int argc, char *argv[]) { 
	if (argc != 2) { 
		fprintf(stderr, "usage: cpu <string>\n"); 
		exit(1); 
	}
	...
```
 
> [!NOTE] main 함수의 input
> argc - 프로그램에 넘기는 command line argument의 수
> argv - 프로그램에 넘기는 argument의 array

여기서 argc가 2가 아닐 경우 에러를 뱉게 하고 있는데, 이는 즉 이 프로그램을 실행할 때 argument가 2개(프로그램 이름 + 문자열)여야 함을 의미한다
```
	...
    char *str = argv[1];

    while (1) {
        printf("%s\n", str);
        Spin(1);
    }
    return 0;
```

`char *str = argv[1];`
두번째 argument 즉 문자열을 가리키는 pointer를 선언함

이후에는 무한루프 돌면서, str 주소에 저장된 문자열을 출력하고 Spin(1)을 실행함.
return 0 은 프로그램이 에러없이 실행에 성공을 의미함.

```
#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong)
	; // do nothing in loop
}

#endif // __common_h__
```

> [!NOTE] #ifndef, #endif include guard
> common.h가 여러번 include되는 것을 방지해줌. 만약 header에 등록이 안 되었다면, #ifndef 부터 #endif 사이에 있는 코드들이 include됨.

`int rc = gettimeofday(&t, NULL);`
sys.time.h 라이브러리에서 제공하는 함수로, 현재 시각을 't'에 저장함. 이후 assert문은 이러한 함수의 실행이 성공적였음을 확인하는 부분. 

이후에는 루프를 돌면서, 인자로 주어진 `howlong` 의 시간이 지날때까지 루프를 실행하는 부분. 즉 시간 때우는 용도의 delay 함수

`
