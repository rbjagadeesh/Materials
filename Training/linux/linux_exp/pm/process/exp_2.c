#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int g_var = 45;

int main ( void )
{
	int l_var = 15;
	pid_t pid;
	int *h_var = malloc(sizeof(int));

	*h_var = 25;

	printf("data = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);

	if(-1 == (pid = vfork())) {
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid > 0 ) {
		*h_var = 100;
		printf("\ndata = %d\n address data = %p\n", g_var, &g_var);
		printf("stack = %d\n address stack = %p\n", l_var, &l_var);
		printf("heap = %d\n address heap = %p\n", *h_var, h_var);

	} else if (pid == 0) {
		g_var = 10;
		l_var = 20;
		*h_var = 30;

		printf("\ndata = %d\naddress data = %p\nstack = %d\naddress of stack = %p\nheap = %d\naddress of heap = %p\n", g_var,&g_var,l_var,&l_var,*h_var,h_var);
	
		exit(0);
	}

	return 0;
}
