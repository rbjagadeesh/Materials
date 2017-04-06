
#include <stdio.h>
#include <assert.h>

#define CHECK(X, Y) \
	do { printf("Performing Assertion\n"); assert((X - Y) != 0); \
	printf("Assertion passed\n"); } while (0)

void foo (int x, int y)
{

	CHECK(x, y);
    printf ("%d: %d\n", __LINE__, (x+y)/(x-y));

}

int main ()
{

	foo (4, 3);
    foo (4, 4);
    return 0;

}
