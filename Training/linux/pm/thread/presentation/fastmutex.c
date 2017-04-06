#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
//#include "errors.h"

#if 0
int value = 10;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int status;

void *thread_start( void *arg)
{
	int *i = (int *)arg;

	if (0 != (status = pthread_mutex_lock(&mutex)))
//		err_abort(status, "init failed");

	if(*i == 0) {
		value = 20;
		printf ("I am in thread[%d]\n", *i);
	}

	if(*i == 1) {
		value = 30;
		printf ("I am in thread[%d]\n", *i);
	}

	if(*i == 2) {
		value = 40;
		printf ("I am in thread[%d]\n", *i);
	}
	printf ("value = %d\n", value);
	
	if (0 != (status = pthread_mutex_unlock(&mutex)))
//		err_abort(status, "unlock failed");
	
}

int main ( void )
{
	int i = 0;
	pthread_t thread[3];

	while(i < 3) {

		if (0 != (status = pthread_create(&thread[i], NULL, &thread_start, &i))) {
			err_abort(status,"thread creation failed\n");
			exit(1);
		}
		pthread_join(thread[i], NULL);
		i++;
	}

	value = 12;
	printf ("I am in thread group leader\n");
	printf ("value = %d\n", value);

	pthread_exit(NULL);
}
#endif

//fast mutex

#if 0
int value = 10;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int status;

void *thread_start( void *arg)
{
	int *i = (int *)arg;

	if (0 != (status = pthread_mutex_lock(&mutex)))
//		err_abort(status, "init failed");

	if(*i == 0) {
		value = 20;
		printf ("I am in thread[%d]\n", *i);
	}

	if (0 != (status = pthread_mutex_unlock(&mutex)))
//		err_abort(status, "unlock failed");

	if (0 != (status = pthread_mutex_lock(&mutex)))
//		err_abort(status, "init failed");

	if(*i == 1) {
		value = 30;
		printf ("I am in thread[%d]\n", *i);
//	if (0 != (status = pthread_mutex_unlock(&mutex)))
//		err_abort(status, "unlock failed");
	}

	if(*i == 2) {
		value = 40;
		printf ("I am in thread[%d]\n", *i);
	}
	printf ("value = %d\n", value);

	pthread_exit(NULL);
}
int main ( void )
{
	int i = 0;
	pthread_t thread[3];

	while(i < 3) {

		if (0 != (status = pthread_create(&thread[i], NULL, &thread_start, &i))) {
//			err_abort(status,"thread creation failed\n");
			exit(1);
		}
		pthread_join(thread[i], NULL);
		i++;
	}

	value = 12;
	printf ("I am in thread group leader\n");
	printf ("value = %d\n", value);

}
#endif

//recursive mutex
#if 1
int value = 10;

//pthread_mutex_t recmutex ;
int status;
pthread_mutex_t recmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void *thread_start( void *arg)
{
	int *i = (int *)arg;

	if (0 != (status = pthread_mutex_lock(&recmutex)))
		err_abort(status, "init failed");

	if(*i == 0) {
		value = 20;
		printf ("I am in thread[%d]\n", *i);

	}
	if (0 != (status = pthread_mutex_unlock(&recmutex)))
		err_abort(status, "unlock failed");

	if (0 != (status = pthread_mutex_lock(&recmutex)))
		err_abort(status, "init failed");
	if(*i == 1) {
		value = 30;
		printf ("I am in thread[%d]\n", *i);
	if (0 != (status = pthread_mutex_unlock(&recmutex)))
		err_abort(status, "unlock failed");
	}

	if(*i == 2) {
		value = 40;
		printf ("I am in thread[%d]\n", *i);
	}
	printf ("value = %d\n", value);
}
int main ( void )
{
	int i = 0;
	pthread_t thread[3];
//	recmutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

	while(i < 3) {

		if (0 != (status = pthread_create(&thread[i], NULL, &thread_start, &i))) {
			err_abort(status,"thread creation failed\n");
			exit(1);
		}
		pthread_join(thread[i], NULL);
		i++;
	}

	value = 12;
	printf ("I am in thread group leader\n");
	printf ("value = %d\n", value);

	pthread_exit(NULL);
}
#endif
