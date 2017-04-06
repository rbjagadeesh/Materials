#include <stdio.h>

int main( void )
{
	int a[3][4] ={1,2,3,4,5,6,7,8,9,10,11,12};
	int (*ptr)[3] = &a;
/*		
	printf ("%p\n", a);
	printf ("%p\n", (*(a + 1) + 0));

	printf ("%d\n", (*ptr)[1][2]);
	printf ("%d\n", *(*(*ptr + 1) + 2));
*/

	printf ("%d\n", *(*(ptr + 2) + 3));
//	printf ("%d\n", (*ptr)[1][2]);
//	printf ("%d\n", (*ptr)[1][2]);
//	printf ("%d\n", (*ptr)[1][2]);

	return 0;
}
