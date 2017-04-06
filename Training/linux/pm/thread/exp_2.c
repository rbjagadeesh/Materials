#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include "errors.h"

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}
//process creating a process
#if 0
int main( void )
{
	pid_t pid;

	if(-1 == (pid = fork())) 
		errno_abort("fork failed");

	if( pid > 0 ) {
		printf(" I am in parent \n ");
	}

	else if( pid == 0 ){
		printf(" I am in child \n ");
	}

	return 0;
}
#endif
//process creating a thread
#if 0
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
#endif
//thread  creating a process                        
#if 0
void *thr( ){
	pid_t pid;

	if(-1 == (pid = fork())) 
		errno_abort("fork failed");

	if( pid > 0 ) {

		printf(" I am in thread \n");
	} else if (pid == 0) {

		printf("I am in child process created by thread\n");
	}
}
int main(void)
{ 
	int status;
	pthread_t thread;  

	if (status = pthread_create(&thread, NULL, &thr, NULL))
		errno_abort("Thread creation failed\n");

	pthread_exit(NULL);
	return 0;
} 
#endif

#if  1
//thread  creating a thread       
void *thr1()
{

	printf("Thread created by a thread\n");
}
                                                                    
void *thr( )
{
	int sta;
	pthread_t thread1;

	printf(" I am in thread \n ");

	if(sta = pthread_create( &thread1 , NULL , &thr1 ,NULL))
		errno_abort("Thread creation Failed \n");

}    
int main(void)
{ 
	int status;
	pthread_t thread;  

	if (status = pthread_create(&thread, NULL, &thr, NULL))
		errno_abort("Thread creation failed\n");

	pthread_exit(NULL);
	return 0;
} 
#endif 
