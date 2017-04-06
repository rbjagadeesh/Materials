#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main (void)
{

	printf ("date = %s\n line = %d\n file = %s\n", __DATE__,__LINE__, __FILE__);
	printf ("date = %s\n", "sep 12 2107");
//	printf ("date = %d\n", 12 2107);
//	printf ("date = %s\n", sep __DATE__);
	return 0;
}
