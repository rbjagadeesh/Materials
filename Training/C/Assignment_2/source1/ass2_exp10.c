#include <stdio.h>
#include <stdlib.h>
int strlength(char *);
int inputsingle(char *);

int ass2_exp10()
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];
	int i = 0;
	int l = 0;

	inputsingle(sbuf);
	l = strlength(sbuf);

	sbuf[l - 1] = '\0';
	l = strlength(sbuf);

	for (;sbuf[i] != '\0'; l--, i++){
		dbuf[i] = sbuf[l - 1];				//reverse string
	}

	dbuf[i] = '\0';
	printf ("reverse of string %s\n", dbuf);

	for(i = 0; dbuf[i] != '\0'; i++){
		if(sbuf[i] != dbuf[i]) {				//comapring string with reversed string
			printf ("string is not palindrome ");
			exit(1);
		}
	}

	printf ("string is a palindrome \n");

	return 0;
}	
