#include "../thread/errors.h"

int sec;
char msg[100];

void sig_handler(pid_t pid)
{
	sleep(sec);
	printf ("(%d) %s\n", sec, msg);

}

int main ( void )
{
	pid_t pid;
	char line[100];

	if(SIG_ERR == signal(SIGCHLD, sig_handler)) {
		errno_abort("signal failed\n");
		exit(0);
	}

 	while (1) {
		printf ("Alarm ");
		if (fgets(line, sizeof(line), stdin) == NULL)
			exit(0);

		if (sscanf (line,"%d %64[^\n]",&sec, msg) < 2) {
			fprintf (stderr, "Bad command\n");
			continue;
		}
		pid = fork();
	
		if (pid > 0) {
			if(-1 == waitpid(pid, NULL, WNOHANG)) {
				errno_abort("waitpid error");
				exit(EXIT_FAILURE);	
			}
		} else if(pid == 0) {
			kill(pid, SIGCHLD);
		} else {
			errno_abort("fork failed\n");
		}
	}
	return 0;
}
