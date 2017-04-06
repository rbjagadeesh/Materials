#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include "../thread/errors.h"

#if 0
void seg_handler()
{
	printf ("segmentation fault\n");
	exit(0);
}

int main (void )
{
	int *p = NULL;

	if(SIG_ERR == signal(SIGSEGV, seg_handler)) {
		errno_abort("signal failed\n");
		exit(0);
	}
	printf("*p = %d\n", *p);

	return 0;
}
#endif
//sigchld experiment
#if 1
void sigchld_handler()
{
	pid_t pid;

	pid = fork();

	if (pid > 0) {
		printf ("I am in signal_child\n");
	} else if (pid == 0) {
		printf ("I am in signal_parent\n");
	}
	exit(1);
}

int main (void )
{
	pid_t pid;

	pid = fork();


	if (pid > 0) {
		printf ("I am in child\n");

	if(SIG_ERR == signal(SIGCHLD, sigchld_handler)) {
		errno_abort("signal failed\n");
		exit(1);
	}
	} else if (pid == 0) {
		printf ("I am in parent\n");
	}

	return 0;
}
#endif
