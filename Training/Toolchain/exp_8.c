#include <stdio.h>
#include <stdlib.h>

int i;
char *ptr;
int main ( void )
{

	ptr = malloc (5 * (sizeof (int)));

	for (i = 0; i < 5; i++) {
		scanf ("%c", (ptr+ i));
	}

	my_free();

	return 0;
}

int my_free()
{

	free (ptr);

	for (i = 0; i < 5; i++) {
		printf ("%c ", ptr[i]);
	}

	return 0;
}	
