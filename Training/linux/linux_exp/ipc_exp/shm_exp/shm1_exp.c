#include "../header/errors.h"
#include <sys/mman.h>

#define filename "/myshm"
#define MAX 4096

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}

int main ( void )
{
	int fd;
	char *addr;
	char *buf;
	struct stat sb;
	
	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	if( MAP_FAILED == (addr = mmap(NULL, MAX, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)))
		failure("mmap failed");

//	memcpy(buf, addr, MAX);
		
	printf("%d\n", sb.st_dev);

	printf("%s\n", addr);

	shm_unlink(filename);

	exit(EXIT_SUCCESS);
}
