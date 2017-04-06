#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( void ) 
{
	int fd1;
	int fd2;
	pid_t pid;
	char *buf;

	fd1 = open ("just.txt", O_WRONLY);
	fd2 = open ("just.txt", O_WRONLY);
	
	if (fd2 == -1 ) {
		perror ("open failed");
		exit(3);
	}

	pid = fork();
	
	if (pid > 0) {
		printf ("parent fd = %d\n",fd1);
		buf = "global edge";
		write(fd1, buf, 11);
		close(fd1);
		wait(NULL);
	} else if (pid == 0) {
		printf ("child fd = %d\n",fd2);
		sleep(1);
		__fpurge();	
		buf = "software limited";
		write(fd2, buf, 20);
		close (fd2);

		printf ("ouput of cat command : \n");
		if(-1 == system("cat just.txt")) {
			perror ("system failed");
			exit(EXIT_FAILURE);
		}	
	} else {
		perror ("fork failed");
		exit(3);
	}
	return 0;
}
