#include <stdio.h>
#if 0
int main ()
{

	int i =10;
	volatile int j = 20;

	printf ("sizeof int is %d\n", sizeof(int));

	printf("%d %d %d\n", i++, ++i , i);
	printf("%d %d %d\n", j++, ++j , j);

	return 0;
}
#endif

#if 0
int gvar = 12;

int main (void)
{
	int a = 13;

	while(gvar == 12) 
		;
	
	printf ("exit\n");
	return 0;
}
#endif
	
#if 1
volatile int gvar = 12;

int main (void)
{
	int a = 13;

	while(gvar == 12) {
		;
	}

	printf ("exit\n");
	return 0;
}
#endif	
