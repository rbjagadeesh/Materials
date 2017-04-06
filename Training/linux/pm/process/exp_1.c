#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#if 1
int g_var = 45;

int main ( void )
{
	int l_var = 15;
	pid_t pid;
	int *h_var = malloc(sizeof(int));

	*h_var = 25;

	printf("data = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);

	if(-1 == (pid = fork())) {
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {				//parent process

		g_var = 10;
		l_var = 20;
		*h_var = 30;
//		wait(NULL);
		printf ("\nI am parent");
		printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else if (pid > 0 ) {		//child process

		getchar();
		sleep(1);
		printf ("\nI am child");
		printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	}
		
	return 0;
}
#endif
#if 0
int main( void ) 
{
	int fd;
	pid_t pid;
	char *buf;

	if(-1 == (fd = open ("just.txt", O_WRONLY))) {   //open file
		perror ("open failed");
		exit(EXIT_FAILURE);
	}

	if(-1 == (pid = fork())) {			//creating child
		perror ("fork failed");
		exit(EXIT_FAILURE);
	}
	
	if (pid > 0) {						//parent  process
		printf ("parent fd = %d\n",fd);
		buf = "global edge ";
		write(fd, buf, 12);		//writting into file from buf
		close(fd);
		wait(NULL);
	
	} else if (pid == 0) {				//child process
		sleep(1);
		printf ("child fd = %d\n",fd);
		__fpurge(stdin);						//clearing stdin buf
		buf = "software limited";
		write(fd, buf, 16);				//writting into file from buf
		close (fd);

		printf ("ouput of $cat command on just.txt : \n");
		if(-1 == system("cat just.txt")) {
			perror ("system failed");
			exit(EXIT_FAILURE);
		}	
	}
	printf("\n");	
	return 0;
}
#endif
