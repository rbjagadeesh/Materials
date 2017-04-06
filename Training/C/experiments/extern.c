#include <stdio.h>
#if 0
int a = 20;

int main (void)
{
	int a = 20;

	extern int a;

	printf ("a = %d\n", a);

	return 0;
}
int a = 30;
#endif
#if 1
int main (void)
{
	static int b = 20;
//	int a = 20;
	{
		extern int a;
//		extern int b;
//		static int b;
//		printf ("a = %d\n", a);
		printf ("b = %d\n", b);
	}
	return 0;
}
//int a = 30;
#endif
#if 0
//int a = 20;

int main (void)
{
	int a = 20;

	extern int a;

	printf ("a = %d\n", a);

	return 0;
}
int a = 30;
#endif
