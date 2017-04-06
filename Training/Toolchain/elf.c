#include <stdio.h>

int main ( void ) 
{

	int a = 10;
	int b = 20;

	printf ("a + b = %d\n", fun(a, b));

	return 0;
}

int fun(int a, int b)
{
	return (a + b);
}
