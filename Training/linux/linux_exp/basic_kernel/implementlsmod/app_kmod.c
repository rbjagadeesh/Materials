#include<stdio.h>
#include<fcntl.h>

int main()
{

	int fd;
	fd = open("/dev/myChar",O_RDWR);

	if(fd < 0)
		perror("Unable to open the Device");

	else
		printf("File opened successfully %d\n",fd);

	ioctl (fd, getpid(), 12);

	printf("getpid = %d\n",getpid());

	close(fd);

	return 0;
}
