#include <stdio.h>
#if 0
int main (void)
{
	typedef char a[3] ;
	a b;

	printf("%d\n", sizeof(b));
}
#endif
#if 1
#include <stdio.h>
int main()
{	int k;
    int x = 5;
    int * const ptr = &x;
    ++(*ptr);
	&ptr = &ptr + 1;
	printf ("%p\n", &ptr);
    printf("%d", x);
   
    return 0;
}
#endif
