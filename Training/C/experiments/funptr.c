#include <stdio.h>

#if 0
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main()
{
	int a;
	int (*fun) (int, int);

	fun = add;

	a = fun(12 , 24);

	printf ("a = %d\n", a);

	fun = sub;

	a = fun(12 , 24);

	printf ("a = %d\n", a);
	return 0;
}
int add(int b, int c)
{

	return (b + c);
}
int sub(int b, int c)
{

	return (b - c);
}

#endif
#if 1
int calc(char *, int, int);
int (*funptr)(char *, int, int);

int main( void )
{
	int a;
	int b;
	char *opera;

	int (*fp)(char *opera, int a, int b); //function pointer
	fp = calc;
	
	a = 10;
	b = 20;
	opera = "add";
	fp(opera, a, b); 	//invoking calc function

	return 0;
}
int calc(char *oper, int n1, int n2)
{
	int a =  atoi(n1);
	int b =  atoi(n2);

	if(strcmp(oper,"add") == 0) {
		printf ("addition value is %d\n", (a + b));
	} else if (strcmp(oper,"sub") == 0) {
		printf ("submission value is %d\n", (a - b));
	} else if (strcmp(oper,"mul") == 0) {
		printf ("multiple value is %d\n", (a * b));
	} else if (strcmp(oper,"div") == 0) {
		printf ("divison value is %d\n", (a / b));
	} else {
		printf ("Invalid input\n");
	}
	return 0;
}

#endif
