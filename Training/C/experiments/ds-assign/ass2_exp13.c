#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strrot(char *str,char *str1);
int input(char *, char *);
int strlength(char *);
int i;

int ass2_exp13()
{
	char str[20];
	char str1[20];

	input(str, str1);
	i = strrot(str, str1);
	if (i == 1) 
		printf ("str and str1 are rotated strings\n");
	else 
		printf ("str and str1 are not rotated strings\n");
return 0;
}
int strrot(char *str,char *str1)
{
	char *c;
	int j =0;

	if (strlength(str) != strlength(str1)) 
		return 0;
	c = (char *) malloc (sizeof(char) * ((strlength(str) * 2) + 1));

	c[0] ='\0';

	strcat(c,str);
	strcat(c,str);
	
	while ( c[i] != '\0') {
		if( str1[j] == c[i]) {
			for (;str1[j] == c[i] && str1[j] != '\0';j++) {
				continue;		
			}
		}
		if (j == strlength(str1)) 
			return 1;
		i++;
	}
	free(c);
return 0;
}
