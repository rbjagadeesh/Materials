#include <stdio.h>

int main(void)
{
	union sample {
		int a : 5;
		int b : 10;
		int c : 5;
		int d : 21;
		int e;
	};

	union sample ex;

	ex.e = 9;

	printf ("value of a varible %d\n", ex.a);
	printf ("value of b varible %d\n", ex.b);
	printf ("value of c varible %d\n", ex.c);
	printf ("value of d varible %d\n", ex.d);
	printf ("value of e varible %d\n", ex.e);

	return 0;
}
