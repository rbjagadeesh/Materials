#include <stdio.h>

int showbit(int n);

int main(void)
{
	int n;
	int i = 0;
	int num;
	int n1;
	
	printf (" Enter number ");
	scanf("%d", &n);
	n1 = n;
	printf ("%d binary form ", n);

	showbit(n);

	printf ("\nEnter number that howmany times you want to iterate ");
	scanf("%d", &num);
	
	printf ("Left rotation\n");
	while(num > i){
		n = ((n <<1) | (n & (1 << ((sizeof(int) * 8) - 1))));
		i++;

	showbit(n);
	}

	i = 0;
	printf("\n");

	printf ("Right rotation\n");
	while(num > i){
		n1 = ((n1 >> 1) | ((n1 & 1) << ((sizeof(int) * 8) - 1)));
		i++;
	
	showbit(n1);
	}
	return 0;
}
