#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define getaddress(tsk, type, add) \
				tsk = (type *) 0; \
				offset = (int)((char *) &(tsk->tasks) - (char *)tsk);\
				tsk = (type *) ((int)add - offset)\
		
struct link {
	struct link *next;
	struct link *prev;
}head;

struct task {

	long state;
	int pid;
	int flags;
	int prio;
	unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	char comm[16];
	unsigned int rt_prio;
}*tsk, *tsk1;

int main( void )
{
	char str[20];
	int n;
	int offset;

	struct task task_a;
	head.next = &task_a.tasks;

	printf ("How many nodes you want to create ");
	fgets (str, MAX, stdin);

	n = atoi(str);
	tsk = ( struct task *) malloc (sizeof(struct task));
	getaddress(tsk, struct task, &(task_a.tasks));

	tsk->state = 1;

	printf ("long_ = %ld\n", tsk->state);
	printf ("%p\n", tsk);
	printf ("%p\n", &task_a.tasks);

	tsk1 = ( struct task *) malloc (sizeof(struct task));
	tsk->tasks.next = tsk1->tasks.next;
	tsk1->tasks.prev = tsk->tasks.prev;
	getaddress(tsk1, struct task, &(task_a.tasks));

	tsk1->state = 2;
	printf ("long_ = %ld\n", tsk1->state);
	printf ("%p\n", tsk1);
	printf ("%p\n", &task_a.tasks);

	return 0;
}	
