#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd;

	fd = open("/dev/sbd",O_RDWR);

	if(fd < 0)
		perror("Unable to open the Device");

	else
		printf("File opened successfully %d\n",fd);

	ioctl (fd, getpid(), 12);

	getchar();	

	close(fd);

	return 0;
}
