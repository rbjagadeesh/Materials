#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

int value = 10;

void *thread_start(void *arg)
{
	int *j = (int *)arg;
	
	if(*j == 0) {
		value = 20;
		printf ("value = %d\n", value);
		printf ("I am in thread[%d]\n", *j);
	}
	if(*j == 1) {
		value = 30;
		printf ("value = %d\n", value);
		printf ("I am in thread[%d]\n", *j);
	}
	if(*j == 2) {
		value = 40;
		printf ("value = %d\n", value);
		printf ("I am in thread[%d]\n", *j);
	}

}

int main ( void )
{
	int i = 0;
	int status;
	pthread_t thread[3];

	while(i < 3) {
		if (0 != (status = pthread_create(&thread[i], NULL, &thread_start, &i))) {
			err_abort(status,"thread creation failed\n");
			exit(1);
		}
		i++;
	}

	value = 50;

	printf ("value = %d\n", value);

	pthread_exit(NULL);
}
