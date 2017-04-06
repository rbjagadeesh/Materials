#include <stdio.h>
#include <stdlib.h>

char * str_tok(char *str,char *str1);
int input(char *, char *);

int ass2_exp9()
{
	char str[20];
	char str1[20];

	input(str, str1);

	printf ("str is %s\n",str_tok(str, str1));
	return 0;
}
char * str_tok(char *str,char *str1)
{

	int i;
	int j;

	for (i = 0; str[i] != '\0'; i++) {
		for (j = 0; str1[j] != '\0'; j++) {
			if (str1[j] == str[i]) {
				str[i] = ' ';		//comapring string with delimiter string
			}
		}
	}
	return str;
}	
