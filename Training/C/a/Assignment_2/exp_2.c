#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int str_ncpy(char *dbuf, char *sbuf, int n);

int exp_2()
{
	char * ptr;
	char sbuf[20];
	char dbuf[20];
	int n = 10;
	
	printf ("enter source string ");
	if((ptr = ((char *)(malloc(sizeof(char)) * MAX))) == NULL){
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(sbuf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

	printf ("\nenter destination string ");
	
	if((ptr = ((char *)(malloc(sizeof(char)) * MAX))) == NULL){
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(sbuf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

//	printf ("enter no of characters to copy ");
//	fgets(n, 10, stdin);

	printf ("%s", sbuf);

	str_ncpy(dbuf, sbuf, n);

return 0;
}

int str_ncpy(char *dbuf, char *sbuf, int n)
{
	int i;
	int l;

	l = strlen(dbuf);

	for(i = 0; i < n; i++,l++){
		dbuf[l] = sbuf[i];
	}

	dbuf[l] = '\0';

	printf ("copied string  %s\n", dbuf);

	return 0;
}	
	
