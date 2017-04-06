#include <stdio.h>

int main (void)
{

	int x =0, y =1, z =0;

	z = x && (++y);

	printf ("%d\n", y);

	return 0;
}
