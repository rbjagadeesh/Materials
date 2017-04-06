#include <stdio.h>
#if 1 //variable defination declaration...
int main ()
{

	int a;

	a = 10;

	printf ("Hello\n");

//	printf ("%s\n", argv[1]);
	int b;

	b = 20;

	printf ("%d\n", a + b);

	return 0;
}
#endif
#if 0

int main()
{

	float a = 123.456;

	printf ("a = %f\n", a);
	printf ("a = %3f\n", a);
	printf ("a = %16.0f\n", a);
	printf ("a = %16.4f\n", a);
	printf ("a = %-16.4f\n", a);
	printf ("a = %.2f\n", a);

	return 0;
}
#endif

#if 0 // volatile variable can modify by either external event or by program itself

int main()
{
	volatile int a = 10;
	printf ("a = %d\n", a);

	a = 20;	

	printf ("a = %d\n", a);

	return 0;
}
#endif

//escape_sequence
#if 0
int main()
{
	printf ("hello\tworld\n");
	printf ("\bworld\r");

	return 0;
}
#endif

#if 0
int main()
{
   printf("\new_c_question\by");
//   printf("\rgeeksforgeeks"); 
   getchar();
   return 0;
}
#endif

#if 0
int main() 
{ 
  printf(" \"GEEKS %% FOR %% GEEKS\""); 
  getchar(); 
  return 0; 
}
#endif

#if 0
int main()
{
	int a =10;
	char b = 5 ;
	double c = 15.0;

	printf ("size = %d\n", sizeof(c /= a + b));
	printf ("c = %lf\n", c);

	return 0;
}
#endif
#if 0	//cecking increment operator postfix prefix

int main()
{
	int i = 1;
	int j;

//	j = i++;
//	printf ("i = %d\n", i++);
//	j = i++ + i++;
//	j = ++i + ++i;	//j = 6
//	j = ++i , ++i;	//j = 2
//	j = ++i + i++;	//j = 5
	j = i++ + ++i;	//j = 4

	printf ("i = %d\n", i);
	printf ("j = %d\n", j);

	return 0;
}
#endif
#if 0 //call by reference objdump

void fun(int *x, int *y)
{
	
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

int main( void )
{
	int a = 5;
	int b = 6;

	fun(&a, &b);

	printf ("%d\t %d\n", a, b);

	return 0;
}
#endif

#if 0
int main(void)
{

	int a = 1024;
	void *ptr = &a;

//	printf ("*ptr = %d\n", *ptr);
	printf ("*(int *)ptr = %d\n", *(int *)ptr);
	printf ("ptr = %p\n", ptr);

	ptr++;

	printf ("*(int *)ptr = %d\n", (int)*(char *)ptr);
	printf ("ptr = %d\n", sizeof(ptr));
	printf ("ptr = %p\n", ptr);

	return 0;
}
#endif

#if 0
int main(void)
{
	void *ptr = 0x8049000;

	printf ("*(int *)ptr = %d\n", *(int *)ptr);
	printf ("ptr = %p\n", ptr);

	ptr++;
	printf ("ptr = %p\n", ptr);

	printf ("*(int *)ptr = %d\n", *(int *)ptr);
	return 0;
}
#endif
#if 0
int main(void)
{

	printf ("%d\n", sizeof(void));
	printf ("%d\n", sizeof(main));
	printf ("%d\n", sizeof(main()));

	return 0;
}
#endif
