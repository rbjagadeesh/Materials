#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(void)
{
	char *ptr;
	char sbuf[20];
	int i = 0;
	int j = 0;

	printf ("enter string ");

/*	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(sbuf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}*/
	scanf ("%s", sbuf);
	printf ("source string sbuf is %s \n", sbuf);
	
	while(sbuf[i] != '\0'){
		if(sbuf[i] == sbuf[i + 1]) {
			for (j = i; sbuf[j] != '\0'; j++) {
				sbuf[j] = sbuf[j + 1];
			}
		sbuf[j] = '\0';
		i--;
		}
	i++;
	}
//	sbuf[i] = '\0';
	printf ("squeeze string %s\n", sbuf);

	return 0;
}
