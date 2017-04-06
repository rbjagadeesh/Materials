//#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE (4096 * 10)
#define LENGTH (4 * 2)
#define MAX 80

void errno_abort(const char *str);
int main(void)
{
	int shm;	//used for opening the session for shared memory
	off_t length;	
	char buf[MAX];	
	void * map;
	const volatile int *ptr;

	//creating (or) opening the shared memory

	if(-1 == (shm = shm_open("/shared", O_RDWR | O_CREAT, 00666) ) ){
		errno_abort("shared memory is not opened \n");
	}

	if(MAP_FAILED == (map = mmap(NULL, LENGTH, PROT_READ , MAP_SHARED, shm, 0x00000000) ) ){
        errno_abort("mapping failed ....! \n");                                 
    }   

	
	//accessing contents of shared memory 
	ptr = map;
	while (*ptr != 5);
	printf ("%d\n", ptr[1]);
	
//	printf("Read data from memory : %s \n", (char *)map);
	
	//unmap thefiles from shared memory

	if(-1 == munmap(NULL, SIZE) ){
		errno_abort("Unmapping failed....! \n");
	}

	//unlink the shared memory

	if(-1 == shm_unlink("/shared")){
		errno_abort("unlink failed \n");
	}      

	//closing the session for shared memory
	
	if(-1 == close(shm)){
		errno_abort("closing shared memory session failed \n");
	}

	return 0;
}
void errno_abort(const char *str)
{
	printf("%s failed\n", str);
	exit(1);
}
