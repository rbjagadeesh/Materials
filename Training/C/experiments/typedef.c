#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	typedef unsigned int u_int32;
	typedef int * INT;

	INT a, d, e;
	u_int32 b = 12, c = 15, f =18;

	a = &b;
	d = &c;
	e = &f;

	printf ("%d\n", *a);
	printf ("%d\n", *d);
	printf ("%d\n", *e);

	return 0;
}
