#include <stdio.h>
#include <stdlib.h>
#define MAX 20

#define getaddress(tsk2, type, add) \
		tsk2 = (type *) 0; \
		offset = (int)((char *) &(tsk2->tasks) - (char *)tsk2);\
		tsk2 = (type *) ((int)add - offset);

struct link {
	struct link *next;
	struct link *prev;
}*head = NULL;

struct task {
	long state;
	int pid;
	int flags;
	int prio;
	unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	char comm[MAX];
	unsigned int rt_prio;
}*tsk, *tsk1, *tsk2;
//tsk for previous node
//tsk1 for current node
//tsk2 for starting address of current node to access strucure members 

int main( void )
{
	char str[MAX];
	int n;
	int offset;

	printf ("How many nodes you want to create ");
	if(NULL == fgets (str, MAX, stdin)) {
		perror("fegts failed");
		exit(0);
	}

	for(n = atoi(str); n != 0; n--) {
		if(head == NULL) {
			head = ( struct link *) malloc (sizeof(struct link));
			tsk = ( struct task *) malloc (sizeof(struct task));
			head->next = &tsk->tasks;
			tsk->tasks.next = NULL;
			tsk->tasks.prev = NULL;

			getaddress(tsk2, struct task, &(tsk->tasks));
			tsk2->state = 1;
			printf ("status %ld\n", tsk2->state);
			printf ("task statring address %p\n", tsk2);
			printf ("tasks address 	   %p\n", &tsk->tasks);
			printf ("size of structure %d\n\n", sizeof(struct task));
		} else {
			tsk1 = ( struct task *) malloc (sizeof(struct task));
			getaddress(tsk2, struct task, &(tsk1->tasks));
			tsk2->state = 1;
			printf ("status %ld\n", tsk2->state);

			tsk->tasks.next = &tsk1->tasks;
			tsk1->tasks.prev = &tsk->tasks;
			printf ("task statring address %p\n", tsk2);
			printf ("tasks address     %p\n\n", &tsk1->tasks);
			tsk = tsk1;
		}
	}
	exit(EXIT_SUCCESS);
}	
