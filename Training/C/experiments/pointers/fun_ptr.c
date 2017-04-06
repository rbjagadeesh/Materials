#include <stdio.h>

#if 0
int fun1(int i) ;
int main (void)
{
	int i = 0;
	int k;

	int (*fun)(int i);			//funtion pointer declaration

	fun = fun1;     //assign fun1 address to funtion pointer
	
	k = fun(i);		//invoking function with fun pointer

	printf ("k = %d\n", k);
	printf ("i = %d\n", i);

	return 0;
}
int fun1(int i) 
{
	int j = 3;
	i = i + 7;
	return j++;
}
#endif

//replace switch statement 

#if 0
int add (int , int);
int sub (int , int);
int div (int , int);

int main (void)
{
	int i;
	int a = 4;
	int b = 6;

	int (*fptr[3])(int , int) = {add, sub, div};

	printf ("enter choice ");
	scanf ("%d", &i);

	i = fptr[i](a, b);

	printf ("%d\n", i);	 

//	printf ("%d\n", fptr[0](a, b));	 
//	printf ("%d\n", fptr[1](a, b));	 
//	printf ("%d\n", fptr[2](a, b));	 


	return 0;
}
int add (int a, int b)
{
	return (a + b);
}
int sub (int a, int b)
{
	return (a - b);
}
int div (int a, int b)
{
	return (a / b);
}
#endif

//call back function

#if 1
int add (int , int);
int sub (int , int);
int div (int , int);

int main (void)
{
	int i;
	int a = 4;
	int b = 6;

	int (*fptr[3])(int , int) = {add, sub, div};

	printf ("enter choice ");
	scanf ("%d", &i);

	i = fptr[i](a, b);

	printf ("%d\n", i);	 

//	printf ("%d\n", fptr[0](a, b));	 
//	printf ("%d\n", fptr[1](a, b));	 
//	printf ("%d\n", fptr[2](a, b));	 

	return 0;
}
int add (int a, int b)
{
	return (a + b);
}
int sub (int a, int b)
{
	return (a - b);
}
int div (int c, int b)
{
	static int a = 0;
	a = c;
	while(b) {
		a = add(a,4);	//here i dont want to invoke add fun
		b--;
	}
	return a;
}
#endif
