#include <stdio.h>
#include <stdlib.h>


# if 1

#pragma pack(push, 1)

struct a {
	char a;
	int b;
	char d;
	double c;
} t;

#pragma pack(pop)

struct f {
	char a1;
	int b1;
	char d1;
	double c1;
} z;

int main(void)
{
	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(struct f));
	return 0;
}

# endif

# if 0

#pragma pack(1)

struct a {
	char a;
	int b;
	char d;
	double c;
} t;

struct f {
	char a1;
	int b1;
	char d1;
	double c1;
} z;


int main(void)
{
	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(struct f));
	return 0;
}

# endif

#if 0

struct a {
	char a ;
	int b; 
	char c;
	double d ;

} __attribute__((__packed__));

struct f {
	char a1;
	int b1;
	char c1;
	double d1;
} ;


int main(void)
{
	struct a t;
	struct f z;
	printf("%d\n", sizeof(struct a));
	printf("%d\n\n", sizeof(struct f));

	printf("a %p\n", &(t.a));
	printf("b %p\n", &(t.b));
	printf("c %p\n", &(t.c));		
	printf("d %p\n", &(t.d));
	printf("a1 %p\n", &(z.a1));
	printf("b1 %p\n", &(z.b1));
	printf("c1 %p\n", &(z.c1));
	printf("d1 %p\n", &(z.d1));
	printf("double %d\n", sizeof(double));	
	return 0;
}

#endif


#if 0//Command line pack

struct f {
	char a1;
	int b1;
	char c1;
	double d1;
} ;


int main(void)
{
	struct f z;
	
	printf("%d\n\n", sizeof(struct f));

	printf("a1 %p\n", &(z.a1));
	printf("b1 %p\n", &(z.b1));
	printf("c1 %p\n", &(z.c1));
	printf("d1 %p\n", &(z.d1));

	return 0;
}

#endif
