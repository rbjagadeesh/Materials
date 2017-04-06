#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int a = 0;

void *thread_start(void *arg)
{
	while(a != 5){
	}

	printf("a = %d\n", a);	
}

int main ( void )
{
	pthread_t thread;

	if (0 != pthread_create( &thread, NULL, thread_start, NULL)){
		perror("failed");
	}

	sleep(2);
	a = 5;
	pthread_exit(NULL);
	return 0;
}
