#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
char * insertchar(char *sbuf, char ch, int pos);
int inputsingle(char *);
extern strlength(char *);

int ass2_exp15()
{
	char *ptr;
	char sbuf[20];
	char ch;
	int pos;

	inputsingle(sbuf);

	printf ("Enter character ");
	ch = getchar();

	printf ("Enter position ");
	scanf ("%d", &pos);
	
	insertchar(sbuf, ch, pos);

	printf ("modified string %s\n", sbuf);

return 0;
}

char * insertchar(char *sbuf, char ch, int pos)
{
	int l;
	
	l = strlen(sbuf); 

	sbuf[l - 1] = '\0';
	l = strlen(sbuf); 

	printf ("l val %d \n",l);
	while(l >= (pos - 1)) {
		sbuf[l + 1] = sbuf[l];
		l--;
	}
	sbuf[pos - 1] = ch;

	return sbuf;
}
