#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
int inputsingle(char *);

int ass2_exp11()
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];
	int l = 0;
	int i = 0;

	inputsingle(sbuf);

	l = strlen(sbuf);

	while(sbuf[i] != '\0'){			//reverse string
		dbuf[l - 1] = sbuf[i];
		l--;
		i++;
	}
	dbuf[i] = '\0';
	printf ("reverse of string %s\n", dbuf);

	return 0;
}
