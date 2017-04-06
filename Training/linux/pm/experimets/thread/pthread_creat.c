#include "errors.h"
#include <pthread.h>

struct thread_info {
	pthread_t thread_id;
	int thread_num;
	char *argv_string;
};

void *thread_start(void *arg);

void *thread_start(void *arg)
{

	printf ("thread starts\n");
}

int main ( void )
{
	struct thread_info *tinfo;
	pthread_t thread;
	pthread_attr_t attr;
	void *arg;
	int thr;

	printf ("pid of thread %d\n", getpid());

//	int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
/*
	if ('\0' != pthread_create( thread, NULL, )) {
		perror("thread has not created\n");
		exit(0);
	}
*/
	tinfo = calloc(1, sizeof(struct thread_info));
          
	if (tinfo == NULL) {
    	perror("calloc failed\n");
		exit(0);
	}	

	if (0 == (thr =pthread_create(&(tinfo->thread_id), NULL, &thread_start, NULL))){
		printf ("hello thread\n");
		printf ("pid of thread %d\n", getpid());
//		printf ("pid of thread %d\n", thread);
	} else {
		perror("thread has not created\n");
		exit(0);
	}
	return 0;
} 
