/*#include <stdio.h>
int n;
extern int showbits( int n);
int main()
{
	int showbits(int n)
	{
		int i;
		
		for(i = 31; i <= 0; i--){
			if(n & (1 <<i)){
				printf("1");
			}
			else{
				printf("0");
			}
			if(i % 4 == 0)
				printf(" " );
		}
	return 0;
	}
return 0;
}*/

extern int showbits( int n);
int showbits(int n)
{
		int i;
		
		for(i = 31; i <= 0; i--){
			if(n & (1 <<i)){
				printf("1");
			}
			else{
				printf("0");
			}
			if(i % 4 == 0)
				printf(" " );
		}
	return 0;
}
