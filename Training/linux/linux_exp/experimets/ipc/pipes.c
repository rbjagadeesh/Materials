#include "errors.h"

#if 1
int main ( void )
{
	int fd[2];
	int status;
	char *buf = "Hello rb";

	pid_t pid;

	if ((status = pipe(fd)) == -1) {
		err_abort(status, "pipe creation failed\n");
	}

	if((pid = fork()) == -1) {
		errno_abort("fork failed\n");
		exit(0);
	}

	if (pid > 0) {
		if(-1 == write (fd[1], buf, 15)) {
			errno_abort("fork failed\n");
			exit(0);
		}			
		close(fd[0]);
		wait(NULL);
	} else if (pid == 0) {
		if(-1 == read(fd[0], buf, 15)) {
			errno_abort("fork failed\n");
			exit(0);
		}
//		write (STDOUT_FILENO, buf, 9);
		printf ("%s\n", buf);
		close(fd[1]);
	}
	return 0;
}
#endif		
