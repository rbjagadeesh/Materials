#include <stdio.h>

int funt ();
int main(void)
{
	int i;

	for(i=0; i<=3; i++)
		funt();

	return 0;
}
int funt (void)
{
	int fn_auto_var=0;
	static int fn_static=0;

	fn_auto_var+=1;
	fn_static+=1;

	printf ("value of fn_auto_var =%d\n", fn_auto_var);
	printf ("value of fn_static =%d\n", fn_static);
	printf ("\n");

	return 0;
}
