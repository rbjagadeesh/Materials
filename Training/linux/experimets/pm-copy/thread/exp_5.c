#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void thread_start (char *);
int status;

int main ( void )
{
	char line[128];
	pthread_t thread;

	while (1) {

		printf("Alarm> ");
		if (fgets (line, sizeof (line), stdin) == NULL) {
			exit(0);
		}
		if (strlen (line) <= 1) 
			continue;
		if (0 != pthread_create(&thread, NULL,(void *) thread_start, line)) {
			perror ("thread creation failed\n");
			exit(0);
		}
	}
	
	return 0;
}

void thread_start (char *line)
{
	char message[64];
	int seconds;
	if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
		fprintf (stderr, "Bad command\n");
	} else {
		sleep(seconds);
		printf(" (%d) %s\n", seconds, message);
	}
	pthread_detach(pthread_self());
}
