#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int x = 100;
	int rc = fork();
	if(rc<0){
		// error
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0){
		// child
		x += 10;
		printf("x: %d\n", x);
	} else{
		// parent
		x += 3;
		printf("x: %d\n", x);
	}

	return 0;
}
