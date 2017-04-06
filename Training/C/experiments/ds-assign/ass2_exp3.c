#include <stdio.h>
#include <stdlib.h>
#define MAX 256
char  * chr_add_instr(char *buf, char c);
int inputsingle(char *);

int ass2_exp3()
{
	char *ptr;
	char buf[20];
	char c;

	inputsingle(buf);

	printf ("Enter character ");
	scanf ("%c", &c);

	chr_add_instr(buf, c);

	return 0;
}
char * chr_add_instr(char *buf, char c)
{
	int i;

	for(i = 0; buf[i] != '\0'; i++){
		if(buf[i] == c) {							//compare charcater
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
