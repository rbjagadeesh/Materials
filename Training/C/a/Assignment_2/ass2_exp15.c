	printf ("Enter character ");
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
char * insertchar(char *sbuf, char ch, int pos);
extern strlength(char *);
int main(void)
{
	char *ptr;
	char sbuf[20];
	char ch;
	int pos;

	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(sbuf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}
	getchar();

	printf ("Enter character ");
	ch = getchar();

	printf ("Enter position ");
	scanf ("%d", &pos);
	
	
//	scanf ("%c", &ch);
//	ch = getchar();

	insertchar(sbuf, ch, pos);

	printf ("modified string %s", sbuf);

return 0;
}

char * insertchar(char *sbuf, char ch, int pos)
{
	int l;

	l = 5; // strlength(sbuf);
	printf ("str length %d\n", l);
	while(l > pos) {
		sbuf[l + 1] = sbuf[l];
		l--;
	}
	sbuf[pos] = ch;
	printf ("changed  string %s\n", sbuf);

	return sbuf;
}
