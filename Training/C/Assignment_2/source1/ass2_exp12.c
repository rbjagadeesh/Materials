#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
int inputsingle(char *);

int ass2_exp12()
{
	char *ptr;
	char sbuf[20];
	int i = 0;
	int j = 0;

	printf ("enter string ");

	inputsingle(sbuf);
	
	while(sbuf[i] != '\0') {
		if(sbuf[i] == sbuf[i + 1]) {
			for (j = i; sbuf[j] != '\0'; j++) {
				sbuf[j] = sbuf[j + 1];			//attch character to sbuf if it is not repeate
			}
			sbuf[j] = '\0';
			i--;
		}
		i++;
	}
	printf ("squeeze string %s\n", sbuf);

	return 0;
}
