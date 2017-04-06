#include <stdio.h>

//where variables get stored with static storage specifier
#if 1
int main (void)
{

	static int var_a;
	static int var_b = 10;
	int var_c;

	printf ("a = %d b = %d c = %d\n", var_a, var_b, var_c);

	return 0;
}
#endif

#if 0
int fun(static int);

int main(void)
{

	static int i = 0;

	fun(i);

	return 0;
}

int fun(static int i)
{

	printf ("j = %d\n", i);

	return 0;
}
#endif
#if 0
//int fun(auto int);
int fun(register int);

int main(void)
{

	register int i = 10;

	fun(i);

	return 0;
}

int fun(int j)
{

	printf ("j = %d\n", j);
	printf ("j = %p\n", &j);

	return 0;
}
#endif

#if 0
int fun(int);
int main(void)
{

	int i = 10;

	fun(i);

	return 0;
}

int fun(int j)
{

	printf ("j = %d\n", j);
	printf ("j = %p\n", &j);

	return 0;
}
#endif
