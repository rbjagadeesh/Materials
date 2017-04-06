#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#if 0
int g_var = 45;

int main ( void )
{
	int l_var = 15;
	pid_t pid;
	int *h_var = malloc(sizeof(int));

	*h_var = 25;

	printf("data = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);

	pid = fork();

	if (pid == 0) {
		g_var = 10;
		l_var = 20;
		*h_var = 30;
	printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else if (pid > 0 ) {
		wait(NULL);
	printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else {
		printf ("fork failed");
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

	fd = open ("just.txt", O_WRONLY);
	
	if (fd == -1 ) {
		perror ("open failed");
		exit(3);
	}

	pid = fork();
	
	if (pid > 0) {
		printf ("child fd = %d\n",fd);
		buf = "global edge";
		write(fd, buf, 15);
		close(fd);
	} else if (pid == 0) {
		printf ("parent fd = %d\n",fd);
		__fpurge();	
		buf = "software limited";
		write(fd, buf, 20);
		close (fd);
	} else {
		perror ("fork failed");
		exit(3);
	}
	return 0;
}
#endif
#if 1
int main( void ) 
{
	int fd;
	int fd3;

	pid_t pid;
	char *buf;

	fd = open ("just.txt", O_WRONLY);
	fd3 = open("/dev/myChar",O_RDWR);

	if (fd == -1 ) {
		perror ("open failed");
		exit(3);
	}
	if (fd3 == -1 ) {
		perror ("open failed");
		exit(3);
	}

	pid = fork();
	
	if (pid > 0) {
//		printf ("child fd = %d\n",fd1);
		buf = "global edge";
		write(fd, buf, 11);
		ioctl(fd3, getpid(), fd);		
//		close(fd);
	} else if (pid == 0) {
//		printf ("parent fd = %d\n",fd2);
		buf = "software limited";
		write(fd, buf, 20);
		ioctl(fd3, getpid(), fd);		
//		close (fd);
	} else {
		perror ("fork failed");
		exit(3);
	}
	close (fd);
	return 0;
}
#endif
