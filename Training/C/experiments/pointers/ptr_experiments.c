#include <stdio.h>
#if 0
{

	printf ("Hello");
	return 0;
}
{

	const int a = 10;
	int *ptr = NULL;

	ptr = &a;
//	a = a + 1;
	*ptr = 11;
	printf ("%d", *ptr);
	printf ("%d", a);
	return 0;
}
#endif
#if 0
int main(void)
{
    int i = 10;   
    int j = 20;
    const int *ptr = &i;    /* ptr is pointer to constant */
  
    printf("ptr: %d\n", *ptr); 
    *ptr = 100;        /* error: object pointed cannot be modified
                     using the pointer ptr */
  
    ptr = &j;          /* valid */
    printf("ptr: %d\n", *ptr);
  
    return 0;
}
#endif
#if 1
int main()
{
	int a = 10;
	int *p;

	p = &a;

	printf ("%d\n", *p);

	*p = *p + 10;

	printf ("%d\n", *p);

	int y = *p + 1;
	printf ("%d\n", y);

	++*p;

	printf ("%d\n", *p);

	(*p)++;

	printf ("%d\n", *p);


	return 0;
}
#endif
