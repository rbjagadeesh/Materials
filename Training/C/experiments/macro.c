#include <stdio.h>
#if 0
#define INC(num) num = -(~num)
#define DEC(num) num = ~(-num)

#define E_MASK 0x55555555

main (void)
{
	int num = 11;

	printf ("num = %d\n", INC(num));
	printf ("num = %d\n", DEC(num));
	printf ("num = %d\n", DEC(num));
	printf ("num = %d\n", num & E_MASK);

	return 0;
}
#endif

int main (void)
{

	printf ("%d\n", MAX);

	return 0;
}
