#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

#if 0
void thread_start (char *);
void enqueue(char *line1);

struct thread_info {
	char line[64];
	int seconds;
	struct thread_info *link;
}*temp, *start = NULL;

struct thread_info *temp1;

int main ( void )
{
	char line1[128];
	pthread_t thread;
	int status;

	while (1) {

		printf("Alarm> ");

		if (start == NULL) {
			if (0 != (status = pthread_create(&thread, NULL, (void *) thread_start, temp->line))) {
				err_abort(status,"thread creation failed\n");
				exit(0);
			}
		}

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
		if (start == NULL) {
			sleep(1);
		} else {
			while(start != NULL) {	
				sleep(start->seconds);
				printf("(%d) %s\n", start->seconds, start->line);
				start = start->link;
			}
		}
	}
}

void enqueue(char *line1)
{
	temp = (struct thread_info *) malloc (sizeof(struct thread_info));

	if (sscanf (line1, "%d  %64[^\n]", &temp->seconds, temp->line) < 2) {
		fprintf (stderr, "Bad command\n");
	}
	temp->link = NULL;

	if (start == NULL) {
		start = temp;
	} else {
		temp1 = start;
		while(temp1->link != NULL) {
			temp1 = temp1->link;
		}
	temp1->link = temp;
	}
}
#endif 

#if 1
void thread_start (char *);
void enqueue(char *);

struct thread_info {
	char line[64];
	int seconds;
	struct thread_info *link;
}*temp, *start = NULL;

struct thread_info *temp1;
time_t tm;

int main ( void )
{
	char line1[128];
	pthread_t thread;
	int status;

	while (1) {

		printf("Alarm> ");

		if (start == NULL) {
			if (0 != (status = pthread_create(&thread, NULL, (void *) thread_start, temp->line))) {
				err_abort(status,"thread creation failed\n");
				exit(0);
			}
		}

		if (fgets (line1, sizeof (line1), stdin) == NULL) {
			exit(1);
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
		if (start == NULL) {
			sleep(1);
		} else {
			while(start != NULL) {	
				sleep(start->seconds - time(&tm));
				printf("(%d) %s\n", start->seconds, start->line);
				start = start->link;
			}
		}
	}
}

void enqueue(char *line1)
{

	temp = (struct thread_info *) malloc (sizeof(struct thread_info));

	if (sscanf (line1, "%d  %64[^\n]", &temp->seconds, temp->line) < 2) {
		fprintf (stderr, "Bad command\n");
	}
	
	temp->seconds = temp->seconds + time(&tm);
	temp->link = NULL;

	if (start == NULL) {
		start = temp;
	} else {
		temp1 = start;
		while(temp1->link != NULL) {
			temp1 = temp1->link;
		}
	temp1->link = temp;
	}
}
#endif
