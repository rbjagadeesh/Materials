#include<mathops.h>

int main(void)
{
	int c, d, e, f;

	c = sum(4, 2);
	d = dif(4, 2);
	e = mul(4, 2);
	f = divi(4, 2);

	write(1,"add=",4);
	myprintf (c);
	
	write(1,"dif=",4);
	myprintf (d);

	write(1,"mul=",4);
	myprintf (e);

	write(1,"div=",4);
	myprintf (f);

//	printf ("hello");

	return 0;
}

