#include <stdio.h>
#define my_sizeof(a) (int) (((typeof(a) *)0) + 1)
#if 1
struct st {
		int a;
		int b;
		int c;
		char e;
};
int main(void)
{
	struct st sz;
	int i;

	printf("The size of variable is : %d\n",my_sizeof(i));
	printf ("st : %d\n", my_sizeof(sz));
	printf ("%d\n", my_sizeof(6));
	printf ("%d\n", my_sizeof(float));
	printf ("%d\n", my_sizeof(i));
	printf ("%d\n", my_sizeof(long double));

	return 0;
}
#endif
#if 0
int main (void)
{	
	int a;
	char b;
	
	printf("%d\n", ((typeof(a)*)0));
	printf("%d\n", ((typeof(b)*)0)+ 1);
	printf("%d\n", ((typeof(6)*)0)+ 1);

	return 0;
}

#endif

#if 0
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
int main(void)
{
    double x;
	int a;
    printf("%d\n", my_sizeof(x));
    printf("%d\n", my_sizeof(a));
    getchar();
    return 0;
}
#endif
