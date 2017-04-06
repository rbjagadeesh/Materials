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

	if(-1 == (pid = vfork())) {
		perror("fork failed");
		exit(1);
	}

	if (pid > 0) {
		wait(NULL);
	} else if(pid == 0) {

		printf ("Enter command to execute ");
		if (NULL == (buf = (char *)malloc (5))) {	
			perror ("malloc failed");
			exit(1);
		}

		if (NULL == fgets (buf, 3, stdin)) {	
			perror ("fgets failed");
			exit(1);
		}

		if (-1 == (num = execlp(buf, buf, NULL))) {
			perror ("execlp failed");
			exit(1);
		}
	}
	return 0;
}
