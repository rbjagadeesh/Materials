#include <stdio.h>
#include <stdlib.h>
#define MAX 256
int str_cpy(char *sbuf, char *dbuf);

int main()
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];

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
		dbuf[i] = sbuf[i];
	}

	dbuf[i] = '\0';

	printf ("copied string in dbuf %s\n", dbuf);

	return 0;
}	
