#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#if 0
int main (int argc, char *argv[])
{
	pid_t pid;
	int sec;
	char line[100];
	char msg[100];

	while(1) {

		pid = fork();

		if (pid > 0) {
			wait();
		} else if(pid == 0) {
		
			printf ("Alarm ");
			if (fgets(line, sizeof(line), stdin) == NULL)
				exit(0);
			if (strlen(line) <= 1) continue;

			if (sscanf (line,"%d %64[^\n]",&sec, msg) < 2) {
				fprintf (stderr, "Bad command");
			} else {
				sleep(sec);
				printf ("(%d) %s\n", sec, msg);
			}
		} else {
			perror("fork failed\n");
		}
	}
	return 0;
}
#endif

#if 1
int main (int argc, char *argv[])
{
	pid_t pid;
	int sec;
	char line[100];
	char msg[100];

	printf ("Enter msg and time \n");
 	while (1) {
		if (fgets(line, sizeof(line), stdin) == NULL)
			exit(0);

		if (sscanf (line,"%d %64[^\n]",&sec, msg) < 2) {
			fprintf (stderr, "Bad command");
		}
		pid = fork();
	
		if (pid > 0) {					//child process
			if(-1 == waitpid(pid, NULL, WNOHANG)) {
				perror("waitpid error");
				exit(EXIT_FAILURE);	
			}
		} else if(pid == 0) { 		//parent process
			sleep(sec);
			printf ("(%d) %s\n", sec, msg);
		} else {
			perror("fork failed\n");
		}
	}
	return 0;
}
#endif
