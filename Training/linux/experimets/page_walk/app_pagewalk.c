#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int g_var = 10;

int main (void)
{
	int fd;
	int status;
	void *a;

	fd = open("/dev/myChar",O_RDWR);	//opening myChar device

	if(fd < 0){
		perror("Unable to open the Device");
		exit(1);
	}

	printf ("variable value = %d\n", g_var);

	a = &g_var;

	printf ("a     = %p\n", a);

	ioctl (fd, getpid(), a);	

	printf ("variable value = %d\n", g_var);
	printf ("*a value = %d\n", *(int *)a);

	status = close(fd);		//closing file descriptor

	if(status < 0){
		perror("Unable to close the session");
		exit(1);
	}

	return 0;
}
