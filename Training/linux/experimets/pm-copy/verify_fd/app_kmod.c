#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int fd;
	fd = open("/dev/myChar",O_RDWR);

	if(fd < 0)
		perror("Unable to open the Device");

	else
		printf("File opened successfully %d\n",fd);

	if (-1 == (pid = fork())) {
		perror("fork failed ");
		exit(0);
	}

	if (pid > 0) {
		
		ioctl (fd, getpid(), 12);
	} else {
		ioctl (fd, getpid(), 12);
	}

	close(fd);

	return 0;
}
