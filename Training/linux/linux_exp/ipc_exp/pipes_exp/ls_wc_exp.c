#include "../header/errors.h"

int main ( void )
{
	int fd[2];
	int status;

	pid_t pid;

//  Creating a pipe
	if ((status = pipe(fd)) == -1) {
		err_abort(status, "pipe creation failed");
		exit(EXIT_FAILURE);
	}

	printf ("ls | wc\n");
//creating child process
	if((pid = fork()) == -1) {
		errno_abort("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid > 0) {//parent process
		if( -1 == (close(fd[0]))) {
			errno_abort("close failed");
			exit(EXIT_FAILURE);
		}
		if (-1 == dup2(fd[1], STDOUT_FILENO)) {
			errno_abort("dup2 failed");
			exit(EXIT_FAILURE);
		}	
		if (-1 == execlp("ls", "ls", NULL)) {//execute ls commnad
			errno_abort("execlp failed");
			exit(EXIT_FAILURE);
		}

	} else if (pid == 0) {//child process
		if( -1 == (close(fd[1]))) {
			errno_abort("close failed");
			exit(EXIT_FAILURE);
		}		
		if (-1 == dup2(fd[0], STDIN_FILENO)) {
			errno_abort("dup2 failed");
			exit(EXIT_FAILURE);
		}			
		if (-1 == execlp("wc", "wc", NULL)) {//execute wc command
			errno_abort("execlp failed");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
