#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sched.h>
#include <signal.h>

int value = 10;

int main( void ) 
{
	int fd1;
	int fd2;
	pid_t pid;
	char *buf;

	pid = clone(CLONE_VFORK | CLONE_VM | SIGCHLD, 0);
	
	if (pid > 0) {
		value = 20;
		printf ("parent fd = %d\n", getpid());
		printf ("value = %d\n",value);
		
		wait(NULL);

	} else if (pid == 0) {
		value = 30;
		printf ("child pid = %d\n", getpid());
		printf ("value = %d\n",value);
			
	} else {
		perror ("fork failed");
		exit(3);
	}
	return 0;
}
