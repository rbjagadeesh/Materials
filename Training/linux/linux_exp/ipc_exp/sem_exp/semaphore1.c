#include "../header/errors.h"
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
	int a[10];
	int i;
	int *p = a;

	if(-1 == (fd = shm_open(filename, O_CREAT | O_RDWR, 0666)))
		failure("shm_open failed");

	if(MAP_FAILED ==(addr = mmap(NULL, MAX, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)))
		failure("mmap failed");
	
	p = (int *) addr;
	printf ("p = %p\naddr of shared memroy = %p\n", p, addr);

	if(SEM_FAILED==(sem = sem_open(filename1, O_CREAT | O_RDWR,0666,1)))
		failure("sem_open failed");

	if(-1 == sem_post(sem))					//releasing locked semaphore
		failure("sem_post failed");

	if(-1 == sem_wait(sem))					//acuireing lock
		failure("sem_wait failed");

	p++;
	for (i = 1; i <= 10; p++, i++) 
		printf ("*p = %d\n", *p);			//printing shared mem content
	
	printf ("\n");
	for (i = 1; i <= 10; i++, p++) {
		*p = 0;
		printf ("*p = %d\n", *p);
	}

	if(-1 == sem_post(sem))
		failure("sem_wait failed");

	if(-1 == sem_close(sem))
		failure("sem_close failed");

	close(fd);

	if(-1 == shm_unlink(filename))
		failure("shm_unlink failed");

	if(-1 == sem_unlink(filename1))
		failure("sem_unlink failed");

	exit(EXIT_SUCCESS);
}	
