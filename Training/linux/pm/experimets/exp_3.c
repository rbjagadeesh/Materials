#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g_var = 15;

int main ( void )
{
	int l_var = 25;
	pid_t pid;
	int *h_var = malloc(sizeof(int));

	*h_var = 35;

	printf("data = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);

	pid = vfork();

	if (pid == 0) {
//		g_var = 10;
//		l_var = 20;
//		*h_var = 30;
	printf("\nchild process\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else if (pid > 0 ) {
		wait();
	printf("\nparent process\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	} else {
		printf ("fork failed");
	}
	return 0;
}
