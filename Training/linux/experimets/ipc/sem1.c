#include "../../ipc/errors.h"
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
	void *addr;
	int fd;
	char *buf = "h r u";
//	struct stat sb;
	
	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	if(MAP_FAILED ==(addr = mmap(NULL, MAX, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)))
		failure("mmap failed");

	if(SEM_FAILED==(sem = sem_open(filename1, O_CREAT | O_RDWR,0666,1)))
		failure("sem_open failed");

	if(-1 == sem_post(sem))
		failure("sem_post failed");

	if(-1 == sem_wait(sem))
		failure("sem_wait failed");

	printf ("%s\n %p\n", (char *)addr, addr);

	if(NULL == memcpy(addr, buf, MAX))
		failure("memcpy failed");

	printf ("%s\n %p\n", (char *)addr, addr);

	if(-1 == sem_post(sem))
		failure("sem_wait failed");

	if(-1 == sem_close(sem))
		failure("sem_close failed");

	close(fd);

	exit(EXIT_SUCCESS);
}	
