#include <stdio.h>

#if 1
int main(void)
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
    const int *ptr = NULL;
	
	ptr = &i;    /* ptr is pointer to constant */
  
    printf("ptr: %d\n", *ptr); 
//    *ptr = 100;        /* error: object pointed cannot be modified using the pointer ptr */
  
    ptr = &j;          /* valid */
    printf("ptr: %d\n", *ptr);
  
    return 0;
}
#endif
#if 0
int main( void )
{
    int i = 100;   
    int j = 200;
    int * const ptr = &i;// ptr is constant to int * address cant change
  
    printf("ptr : %d\n", *ptr); 
    *ptr = 80;        /* error: object pointed cannot be modified
                     using the pointer ptr */
  
//	ptr = &j;          /* Invalid */
    printf("ptr : %d\n", *ptr);
  
    return 0;
}
#endif
#if 0
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

#if 0

int main( void )
{

	int *ptr = NULL;
	char *ptr1 = NULL;

	printf ("ptr = %p\n", ptr);

	ptr++;

	printf ("ptr = %p\n", ptr);

	ptr =(int *)((char *) ptr + 6);

	printf ("ptr = %p\n", ptr);

	printf ("ptr1 = %p\n", ptr1);

	ptr1++;

	printf ("ptr1 = %p\n", ptr1);

	return 0;
}
#endif
