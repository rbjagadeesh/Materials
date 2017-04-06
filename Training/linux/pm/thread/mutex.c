#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

void thread_start();
int status;

typedef struct my_struct_tag {
	pthread_mutex_t mutex;
	int value;
}mystr;

mystr *data = NULL;

int main ( void )
{
	pthread_t thread;

	if (NULL == (data = (mystr *)malloc (sizeof(mystr)))) 
		err_abort(status, "malloc failed");

	data->value = 12;
	printf ("data = %d\n", data->value);

	if (0 != (status = pthread_mutex_init(&data->mutex, NULL)))
		err_abort(status, "init failed");

	data->value = 48;
	printf ("data = %d\n", data->value);

	if (0 != (status = pthread_create(&thread, NULL, thread_start, NULL))) {
		err_abort(status,"thread creation failed\n");
		exit(1);
	}

	return 0;
}
void thread_start()
{
	data->value = 24;
	printf ("data = %d\n", data->value);

	if (0 != (status = pthread_mutex_lock(&data->mutex)))
		err_abort(status, "init failed");

	data->value = 36;
	printf ("data = %d\n", data->value);

	sleep(3);

	if (0 != (status = pthread_mutex_unlock(&data->mutex)))
		err_abort(status, "unlock failed");

//	if (0 != (status = pthread_mutex_destroy(&data->mutex)))
//		err_abort(status, "destroy failed");
}
