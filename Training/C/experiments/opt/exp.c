#include <stdio.h>

int main( void )
{
	int a = 10;
	int b = 20;
	int c = 30;
	int sum;
	float div;
	int d;

	d = a;
	sum = a + b;
	div = c / d;

	while( 1 ) {
		if (sum == c) {
			printf("No optimisation\n");
		}
	}
	return 0;
}

	
