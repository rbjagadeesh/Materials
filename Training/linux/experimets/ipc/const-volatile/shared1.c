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

void errno_abort(const char *);

int main(void)
{
	int shmd;	//used for opening the session for shared memory
	off_t length = SIZE;	
	void * map;
	int *ptr;

	//creating (or) opening the shared memory

	if(-1 == (shmd = shm_open("/shared", O_RDWR | O_CREAT, 00666) ) ){
		errno_abort("shared memory is not opened \n");
	}
	
	//allocating the size for shared memory

	if (-1 == ftruncate(shmd, length)){
		errno_abort("allocation of size for shared memory failed \n");
	}

	//mapping files into memory
	
	if(MAP_FAILED == (map = mmap(NULL, LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0) ) ){
		errno_abort("mapping failed ....! \n");
	}
	
	//accesing the data from stdin
//	printf("Enter the data to write into shared memory : \n");

/*	if(NULL == fgets(map, MAX, stdin)){
		perror("accessing the data from stdin failed ....! \n");
	}
*/	
	ptr = map;
	getchar();
	ptr[0] = 10;
	ptr[1] = 12;
	ptr [0] = 5;

	if(-1 == close(shmd)){
		errno_abort("closing shared memory session failed \n");
	}
	
	return 0;
}
void errno_abort(const char *str)
{
	printf("%s failed\n", str);
	exit(1);
}
