#include "errors.h"

#if 1
int main ( void )
{
	int fd[2];
	int status;

	pid_t pid;

//  Creating a pipe
	if ((status = pipe(fd)) == -1) {
		err_abort(status, "pipe creation failed");
		exit(0);
	}

	printf ("ls | wc\n");
//creating child process
	if((pid = fork()) == -1) {
		errno_abort("fork failed");
		exit(1);
	}

	if (pid > 0) {//parent process
		if( -1 == (close(fd[0]))) {
			errno_abort("close failed");
			exit(1);
		}
		if (-1 == dup2(fd[1], STDOUT_FILENO)) {
			errno_abort("dup2 failed");
			exit(1);
		}	
		if (-1 == execlp("ls", "ls", NULL)) {//execute ls commnad
			errno_abort("execlp failed");
			exit(1);
		}
	

	} else if (pid == 0) {//child process
		if( -1 == (close(fd[1]))) {
			errno_abort("close failed");
			exit(1);
		}		
		if (-1 == dup2(fd[0], STDIN_FILENO)) {
			errno_abort("dup2 failed");
			exit(1);
		}			
		if (-1 == execlp("wc", "wc", NULL)) {//execute wc command
			errno_abort("execlp failed");
			exit(1);
		}
	}

	return 0;
}
#endif
