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
	void *addr;
	int fd;
	char *buf = "hello rb";
//	struct stat sb;
	
	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	printf ("%d\n", fd);

	ftruncate(fd, MAX);

	if(MAP_FAILED ==(addr = mmap(NULL, MAX, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)))
		failure("mmap failed");

//	if(NULL == fgets(buf, MAX, stdin)) 
//		failure("fgets failed");

	memcpy(addr, buf, MAX);

	close(fd);

	return 0;
}
