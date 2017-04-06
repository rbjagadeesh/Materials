#include <stdio.h>

int main ( void )
{
//	char *v[] = {"abc", "def", 'g'};
	char **p;
	char a[10] = {'a','b','c','d','e','f'};
//	*p = v;

//	printf ("%d\n", sizeof(v[3]));
//	printf ("%c\n", *++p[0]);

	*p = a; 

	printf ("%c\n", *(*p + 1));
	printf ("%c\n", *(a+5));
	printf ("%c\n", 5[a]);

	return 0;
}
