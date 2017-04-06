#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main ( void )
{
	pid_t pid;
	char *buf = NULL;
	int num;

	if(-1 == (pid = fork())) {
		perror("fork failed");
		exit(1);
	}

	if (pid > 0) {
		wait(NULL);

	} else if(pid == 0) {
/*		if (NULL == fgets (buf, 3, stdin)) {	
			printf ("%d\n", strlen(buf));
			perror ("fgets failed");
			exit(1);
		}
*/
		if (-1 == (num = execlp("ls", "ls", NULL))) {
			printf("hee");
		}
	}
	return 0;
}
