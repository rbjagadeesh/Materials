#include "../header/errors.h"
#include <time.h>
#define filename "/myshm"
#define filename1 "/mysem"
#define MAX 4096

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}

int main ( void )
{
	sem_t *sem;
	time_t tim;
	void *addr;
	int fd;
	int i;
	int a[10];
	
	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	if (-1 == ftruncate(fd, MAX))		//set the size of file
		failure("ftruncate failed");

	if(MAP_FAILED ==(addr = mmap(NULL, MAX, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0))) //mapping shm to memory
		failure("mmap failed");

	if(SEM_FAILED==(sem = sem_open(filename1, O_CREAT | O_RDWR,0666,1)))	//opening semaphore
		failure("sem_open failed");

	if(-1 == sem_wait(sem))							//acquiring lock
		failure("sem_wait failed");

	for(i = 1; i <= 10; i++) {
		a[i] = (time(&tim) % i);
		printf ("a[%d] = %d\n", i, a[i]);
	}

	if(NULL == memcpy(addr, a, MAX))				//copying memory
		failure("memcpy failed");

	if(-1 == sem_close(sem))
		failure("sem_close failed");

	close(fd);

	exit(EXIT_SUCCESS);
}	
