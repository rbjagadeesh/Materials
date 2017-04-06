#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
//close lock statements and check working of fast mutex lock
#if 1
int value = 10;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int status;

void *thread_start( void *arg)
{
	int *i = (int *)arg;

	if (0 != (status = pthread_mutex_lock(&mutex)))
		pthread_exit(NULL);

	if(*i == 0) {
		value = 20;
		printf ("I am in thread[%d]\n", *i);
	}

	if (0 != (status = pthread_mutex_unlock(&mutex)))
		pthread_exit(NULL);

	printf ("value = %d\n", value);

}
void *thread_start1( void *arg)
{
	int *i = (int *)arg;
	if (0 != (status = pthread_mutex_lock(&mutex)))
		pthread_exit(NULL);

	if(*i == 1) {
		value = 30;
		printf ("I am in thread[%d]\n", *i);
	}

	printf ("value = %d\n", value);

	if (0 != (status = pthread_mutex_unlock(&mutex)))
		pthread_exit(NULL);
}

void *thread_start2( void *arg)
{
	int *i = (int *)arg;
	if (0 != (status = pthread_mutex_lock(&mutex)))
		pthread_exit(NULL);

	if(*i == 2) {
		value = 40;
		printf ("I am in thread[%d]\n", *i);
	}
	printf ("value = %d\n", value);

	if (0 != (status = pthread_mutex_unlock(&mutex)))
		pthread_exit(NULL);
}

int main ( void )
{
	int i = 0;
	pthread_t thread[3];

	if (0 != (status = pthread_create(&thread[0], NULL, &thread_start, &i))) {
		exit(1);
	}
	pthread_join(thread[0], NULL);
	i = 1;
	if (0 != (status = pthread_create(&thread[1], NULL, &thread_start1, &i))) {
		exit(1);
	}
	pthread_join(thread[1], NULL);
	i = 2;
	if (0 != (status = pthread_create(&thread[2], NULL, &thread_start2, &i))) {
		exit(1);
	}
	pthread_join(thread[2], NULL);

	value = 12;
	printf ("I am in thread group leader\n");
	printf ("value = %d\n", value);

}
#endif
