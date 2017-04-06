#include <stdio.h>
#include <stdlib.h>
#define MAX 256
int str_ncpy(char *sbuf, char *dbuf, int n);

int main()
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];
	int n;

	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(sbuf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

	printf ("source string sbuf is %s\n", sbuf);

	printf (" Enter no of charactres to copy ");
	scanf ("%d", &n);

	str_ncpy(sbuf, dbuf, n);

return 0;
}
int str_ncpy(char *sbuf, char *dbuf, int n)
{
	int i = 0;
	
	for(i = 0; i < n; i++){
		dbuf[i] = sbuf[i];
	}

	dbuf[i] = '\0';

	printf ("copied string in dbuf %s\n", dbuf);

	return 0;
}	
