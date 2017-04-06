#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(void)
{
	char *ptr;
	char sbuf[20];
	char dbuf[20];
	int i = 0;
	int l = 0;

	printf ("enter string ");

/*	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(sbuf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}
*/	scanf ("%s", sbuf);
	l = strlen(sbuf);
	printf ("source string sbuf is %s and %d\n", sbuf, l);
	
	while(sbuf[i] != '\0'){
		dbuf[l - 1] = sbuf[i];
		l--;
		i++;
	}
	dbuf[i] = '\0';
	printf ("reverse of string %s\n", dbuf);

	for(i = 0; sbuf[i] != '\0'; i++){
		if(sbuf[i] != dbuf[i]) {
			printf ("string is not palindrome ");
			exit(1);
		}
	}
	
	printf ("string is a palindrome \n");

	return 0;
}	
