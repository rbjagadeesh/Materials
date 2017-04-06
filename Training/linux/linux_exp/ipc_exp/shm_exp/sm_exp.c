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
	int i;
	int a[2] = {5, 6};
	
	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	printf ("%d\n", fd);

	ftruncate(fd, MAX);

	if(MAP_FAILED ==(addr = mmap(NULL, MAX, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)))
		failure("mmap failed");

	for (i = 1; i < 100; i++) {
		if((i % 15) == 5){
			a[0] = (i % 15);
			printf ("i = %d\n", i);
		}
		else 
			a[0] = i;

		memcpy(addr, a, 8);
		sleep(1);
	}

	close(fd);

	return 0;
}
