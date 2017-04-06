#include <stdio.h>
#include <stdlib.h>
#if 0
enum months *fun(enum months *);

int main (void)
{
	int i = 0;

	enum months {jan = 1, feb, mar, apr, may, jun = 'a', jul, aug, sep, oct = 111, nov, dec};

	enum months *mnt = (enum months *)malloc(4);

	mnt = jan;

	//	for (i =0; i< 12; i++) 
	printf ("%d\n", jan);
	printf ("%d\n", sizeof(mnt));

	printf ("%d\n", jun);
	printf ("%d\n", jul);

	fun(mnt);

	return 0;
}
enum months *fun(enum months *mnt)
{

	printf ("%d\n", oct);
	printf ("%d\n", dec);

	return mnt;
}
#endif

#if 0
int fun(int);

int main (void)
{
	int i = 0;

	enum months {jan = 1, feb, mar, apr, may, jun = 'a', jul, aug, sep, oct = 111, nov, dec};

	enum months mnt;

	//	for (i =0; i< 12; i++) 
	printf ("%d\n", jan);
//	printf ("%d\n", mnt.mar);
	printf ("%d\n", sizeof(mnt));

	printf ("%d\n", jun);
	printf ("%d\n", jul);

	printf("%d\n", fun(dec));

	return 0;
}
int fun(int x)
{
	printf ("%d\n", x);

//	printf ("%d\n", oct);
//	printf ("%d\n", dec);

	return x;
}
#endif

#if 1
enum months {jan = 1, feb, mar, apr, may, jun = 'a', jul, aug, sep, oct = 111, nov = 12, dec};
int fun(int);

int main (void)
{

	printf ("%d\n", jul);
	printf("%d\n", fun(dec));

	return 0;
}
int fun(int x)
{
	printf ("%d\n", x);

	printf ("%d\n", oct);
	printf ("%d\n", dec);

	return x;
}
#endif
