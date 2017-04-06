#include <stdio.h>
int fact (int );
int main(void)

{

	int n = 5;

	printf ("fact =%d\n",fact(n));

	return 0;
}

int fact (int n)
{
	int subvalue;
	int sol;
	if (n <= 1)
		return 1;

	else {
		subvalue =fact( n - 1);
		sol = subvalue * n;
	}
	return sol;
}

