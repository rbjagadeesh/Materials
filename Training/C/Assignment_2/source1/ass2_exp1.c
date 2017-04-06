#include <stdio.h>
#include <stdlib.h>

int str_cpy(char *sbuf, char *dbuf);
int inputsingle(char *);

int ass2_exp1()
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];

	inputsingle(sbuf);

	str_cpy(sbuf, dbuf);

	return 0;
}
int str_cpy(char *sbuf, char *dbuf)
{
	int i = 0;
	int l = 0;

	while(sbuf[i] != '\0'){
		l++;
		i++;
	}

	for(i = 0; l != 0; i++, l--){
		dbuf[i] = sbuf[i];			//copying into dbuf
	}

	dbuf[i] = '\0';

	printf ("copied string in dbuf %s\n", dbuf);

	return 0;
}	
