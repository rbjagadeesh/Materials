#include "../header/errors.h"
#include <sys/wait.h>

int main ( void )
{
	int fd[2];
	int status;
	char *buf = "Hello rb";
	char *buf1 = NULL;

	pid_t pid;

	if ((status = pipe(fd)) == -1) {				//creating pipe
		err_abort(status, "pipe creation failed");
	}

	if((pid = fork()) == -1) {						//creating child process
		errno_abort("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid > 0) {
		close(fd[0]);					//closing read end pipe descriptor
		if(-1 == write (fd[1], buf, 15)) {		//writing into pipe which is pointing to write end 
			errno_abort("write failed");
			exit(EXIT_FAILURE);
		}			
		wait(NULL);
	} else if (pid == 0) {				//child process
		close(fd[1]);				//closing write end pipe descriptor
		if(-1 == read(fd[0], buf1, 15)) {	//reading from pipe which is pointing read end	
			errno_abort("read failed");
			exit(EXIT_FAILURE);
		}
		printf ("%s\n", buf1);
	}
	exit(EXIT_SUCCESS);
}
