#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#if 0
int b = 10;
int main( void )
{
	int a;
	int *ptr;
	pid_t pid;

	printf ("before fork \n");
	ptr = malloc(10);
	
	printf ("heap mem enter data\n");
	scanf ("%d", ptr);

	pid = fork();

	printf ("pid after fork = %d \n", pid);

	if (pid > 0) {
		
		sleep(5);
		printf ("pid1 = %d \n",getpid());
		printf ("parent \n\n");
		printf ("address of b %p and value is %d \n\n", &b, b);

	} else if (pid == 0) {	
		
		printf ("pid2 = %d \n",getpid());
		printf ("child \n\n");
		b =100;

	scanf ("%d", ptr);
		printf ("address of b %p and value is %d \n\n", &b, b);

//		printf ("address of b %p \n\n", &b);
	}

	printf ("last statement \n");

	return 0;
}
#endif

#if 0
int main( void )
{
	int a;
	pid_t pid;

	printf ("before fork \n");

	pid = fork();

	printf ("pid after fork = %d \n", pid);

	if (pid > 0) {
		
//		sleep(2);
		printf ("pid1 = %d \n",getpid());
		printf ("parent \n\n");
		printf ("address of b %p and value is %d \n\n", &b, b);
		return;

	} else if (pid == 0) {	
		
		printf ("pid2 = %d \n",getpid());
		printf ("child \n\n");
		b =100;
		printf ("address of b %p and value is %d \n\n", &b, b);

//		exit(0);
		printf ("address of a %p and value is %d \n\n", &a, a);
	}

	printf ("last statement \n");

	return 0;
}
#endif

#if 0

int main ( void )
{

	pid_t pid;
	
//	pid = fork();

	printf ("procees id %d\n",getpid());
	printf ("parent procees id %d\n",getppid());

	return 0;
}
#endif
#if 1
int g_var = 45;

int main ( void )
{
	int l_var = 15;
	pid_t pid;
	int *h_var = malloc(sizeof(int));

	*h_var = 25;

	printf("data = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);

	pid = vfork();

	if (pid == 0) {
		g_var = 10;
		l_var = 20;
		*h_var = 30;
	printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else if (pid > 0 ) {
		wait();
	printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else {
		printf ("fork failed");
	}
	return 0;
}
#endif
