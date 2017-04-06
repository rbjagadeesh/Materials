#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>

void *fun1(void *);
void *fun2(void *);

struct tag {
	int shared_data;
	pthread_mutex_t mutex;
	pthread_cond_t cond1;
	pthread_cond_t cond2;
} abc =  {0,PTHREAD_MUTEX_INITIALIZER,PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER};

int main (void)
{
	pthread_t thread1;
	pthread_t thread2;
	int status;

	status = pthread_create (&thread1, NULL, fun1, NULL);
	if (status != 0) {
		exit (1);
	}

	status = pthread_create (&thread2, NULL, fun2, NULL);
	if (status != 0) {
		exit (1);
	}

	pthread_exit (NULL);

	return 0;
}
void *fun1 (void *t)
{
	while (1) {
		pthread_mutex_lock (&abc.mutex);

		if ((abc.shared_data % 2) == 0) {
			pthread_cond_signal ( &abc.cond2);	//generate signal if even number occur to fun2 thread which is waiting on the cond2 variable
			pthread_cond_wait (&abc.cond1, &abc.mutex);	//waiting on cond 1 variable 
		}

		sleep(1);

		printf ("odd == %d\n", abc.shared_data);
		(abc.shared_data)++;

		pthread_mutex_unlock (&abc.mutex);
	}
}

void *fun2 (void *t)
{
	while (1) {
		pthread_mutex_lock (&abc.mutex);

		if ((abc.shared_data % 2) == 1) {
			pthread_cond_signal ( &abc.cond1);
			pthread_cond_wait (&abc.cond2, &abc.mutex);
		}
		sleep(1);

		printf ("even == %d\n", abc.shared_data);
		(abc.shared_data)++;

		pthread_mutex_unlock (&abc.mutex);
	}
}
