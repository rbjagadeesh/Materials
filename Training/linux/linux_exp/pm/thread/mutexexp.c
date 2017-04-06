#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

void thread_start (char *);
void enqueue(char *);

struct thread_info {
	char line[64];
	int seconds;
	int time;
	struct thread_info *link;
}*temp, *temp1;

time_t tm;
int status;
struct timespec ptr;

typedef struct my_struct_tag {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	pthread_cond_t cond1;
	struct thread_info *start;
}mystr;

mystr data = {
	.mutex = PTHREAD_MUTEX_INITIALIZER, 
	.cond = PTHREAD_COND_INITIALIZER, 
	.cond1 = PTHREAD_COND_INITIALIZER, 
	.start = NULL
};

int main ( void )
{
	char line1[128];
	pthread_t thread;

	if (0 != (status = pthread_create(&thread, NULL, (void *) thread_start, temp->line))) {
		err_abort(status,"thread creation failed\n");
		exit(0);
	}

	while (1) {

		printf("Alarm> ");

		if (fgets (line1, sizeof (line1), stdin) == NULL) {
            exit(0);                                                            
        }
                                                                       
        if (strlen (line1) <= 1)                                                 
            continue;  
  	
		enqueue(line1);
	}
	return 0;
}

void thread_start (char *line)
{
	while(1) {

		if (0 != (status = pthread_mutex_lock(&data.mutex))) {
			err_abort(status, "lock failed");
			exit(0);
		}

		if (data.start == NULL) {
			if (0 != (status = pthread_cond_wait(&data.cond, &data.mutex))) {
				err_abort(status, "cond_wait failed");
				exit(0);
			}
		} else {
				
			while(data.start != NULL) {	
				ptr.tv_sec = data.start->seconds;
				if (0 != (status = pthread_cond_timedwait(&data.cond1, &data.mutex, &ptr))){
					err_abort(status, "pthread_cond_timedwait failed");
					exit(0);
				}
				if (status == ETIMEDOUT){
					printf("(%d) %s\n", data.start->time, data.start->line);
					temp1 = data.start;
					data.start = data.start->link;
					free(temp1);
				}
			/*	if(status == EINTR){
					continue;
				}
			*/}
			if (0 != (status = pthread_mutex_unlock(&data.mutex))) {
				err_abort(status, "unlock failed");
				exit(0);
			}
		}
	}
}

void enqueue(char *line1)
{

	temp = (struct thread_info *) malloc (sizeof(struct thread_info));

	if (sscanf (line1, "%d  %64[^\n]", &temp->seconds, temp->line) < 2) {
		fprintf (stderr, "Bad command\n");
		free(temp);
		return;
	}
	temp->time = temp->seconds;	
	
	temp->seconds = temp->seconds + time(&tm);
	//ptr = (struct timespec *) &temp->seconds;

	if (0 != (status = pthread_mutex_lock(&data.mutex))){
		err_abort(status, "init failed");
		exit(0);
	}

	if (data.start == NULL) {
		data.start = temp;
		if(0 != (status = pthread_cond_signal(&data.cond))) {
			err_abort(status, "init failed");
			exit(0);
		}
	} else {

		if(temp->seconds < data.start->seconds) {
			temp->link = data.start;
			data.start = temp;
			if(0 != (status = pthread_cond_signal(&data.cond1))) {
				err_abort(status, "init failed");
				exit(0);
			}
		} else {
			temp1 = data.start;
			while(temp1->link != NULL) {
				printf ("%d\t", temp1->seconds); 
				temp1 = temp1->link;
			}
			temp1->link = temp;
			temp->link = NULL;
		}

	}

	if (0 != (status = pthread_mutex_unlock(&data.mutex))) {
		err_abort(status, "unlock failed");
		exit(0);
	}
}
