#include <stdio.h>
extern int showbits(int n)
{
	int i;
	for(i = 31; i >= 0; i--){
		if(n & (1 << i)){
			printf("1");
		}
		else{
			printf("0");
		}
		if(i % 4 == 0)
			printf(" ");
	}
	printf("\n");
return 0;
}
