#include <stdio.h>
#include <stdlib.h>
#define MAX 256
char  * chr_add_instr(char *buf, char c);

int main()
{
	char *ptr;
	char buf[20];
	char c;

	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(buf, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

	printf ("source string sbuf is %s\n", buf);

	printf ("Enter character ");
	scanf ("%c", &c);

	chr_add_instr(buf, c);

return 0;
}
char * chr_add_instr(char *buf, char c)
{
	int i;

	for(i = 0; buf[i] != '\0'; i++){
		if(buf[i] == c) {
			printf ("character found at %d", i + 1);
			return (buf + i);
		}
		else {
			continue;
		}
	}

	printf ("character not found");

	return 0;
}	
