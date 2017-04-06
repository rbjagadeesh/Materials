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
	int *addr;
	int i = 0;
	
	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	ftruncate (fd, MAX);

	if( MAP_FAILED == (addr = mmap(NULL, MAX, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)))
		failure("mmap failed");

	while(1) {

		while(addr[0] != 5) ;

		printf("%d\n", addr[0]);
		i++;
		if(i == 20) 
			break;
	}
	shm_unlink(filename);

	exit(EXIT_SUCCESS);
}
