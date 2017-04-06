#include <stdio.h>
int fun(int x, int y);

int main (void)
{
	int a= 4, b =5;

	a = fun (a, b);

	printf ("%d %d\n", a, b);

	return 0;
}

int fun(int x, int y)
{

	return (x + y);

}
