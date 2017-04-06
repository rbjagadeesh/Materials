#include <stdio.h>

#define MAKE_TAG_CONSTANT(A,B,C,D) (((A) << 24) |((B) << 16) | ((C) << 8) | (D))

#define HARDWARE_MODULE_TAG MAKE_TAG_CONSTANT('H', 'W', 'M', 'T')


int main (void)
{

	printf ("tag = %x\n", HARDWARE_MODULE_TAG);
	return 0;
}
