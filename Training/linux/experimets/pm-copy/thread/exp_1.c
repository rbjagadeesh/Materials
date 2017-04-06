#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_start(void *arg)                                           
{
	printf ("pid of thread %d\n", getpid());
}
pthread_t thread;

int main (void )
{
	int thr;

	printf ("pid of thread group leader %d\n", getpid());

	if (0 == (thr = pthread_create(&thread, NULL, &thread_start, NULL))){
		printf ("hello thread\n");
	} else {
		perror("thread has not created\n");
		exit(1);
	}
	return 0;
}  
