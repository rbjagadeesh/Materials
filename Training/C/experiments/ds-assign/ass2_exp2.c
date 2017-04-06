#include <stdio.h>
#include <stdlib.h>
#define MAX 256
int str_ncpy(char *sbuf, char *dbuf, int n);
int inputsingle(char *);

int ass2_exp2()
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];
	int n;

	inputsingle(sbuf);

	printf (" Enter no of charactres to copy ");
	scanf ("%d", &n);

	str_ncpy(sbuf, dbuf, n);

	return 0;
}
int str_ncpy(char *sbuf, char *dbuf, int n)
{
	int i = 0;

	for(i = 0; i < n; i++){
		dbuf[i] = sbuf[i];		//copying into dbuf
	}

	dbuf[i] = '\0';

	printf ("copied string in dbuf %s\n", dbuf);

	return 0;
}	
