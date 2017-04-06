#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include "../thread/errors.h"

void seg_handler()
{
	printf ("segmentation fault\n");
	exit(0);
}

int main (void )
{

	int *p = NULL;

	if(SIG_ERR == signal(SIGSEGV, seg_handler)) {
		errno_abort("signal failed\n");
		exit(0);
	}
	printf("*p = %d\n", *p);

	return 0;
}
