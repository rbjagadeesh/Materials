#include <stdio.h>
int main(void)
{
	struct endian {
		char b[4];
		int n;
	}en;
	
	int i;

	printf ("Enter Number ");
	for (i = 0; i < 4; i++) {
		scanf ("%d", &en.b[i]);
	}	
	printf ("Enter another number ");
	scanf ("%d", &en.n);
	
	if (en.b[0] != en.n) {
		printf ("processer is Big Endian\n");
	}
	else {
		printf ("proceser is little Endian\n");
	}
	
	return 0;
}
