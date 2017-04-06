#include <stdio.h>
#include <stdlib.h>

int main ( void )
{

	int *ptr;

	ptr = (int *) malloc (sizeof (int));

	printf ("address of memory allocated by malloc is %p\n", ptr);

	return 0;
}
