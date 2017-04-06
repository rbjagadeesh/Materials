#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
char * sappend(char *str1, char *str2);
int input(char *, char *);
int strlength(char *);
int ass2_exp4()
{
	char *ptr;
	char str1[20];
	char str2[20];
	int l;

	input(str1, str2);

	l = strlength(str1);	
	str1[l - 1] = '\0';

	l = strlength(str2);	
	str2[l - 1] = '\0';

	sappend(str1, str2);

	printf ("appended string  %s\n", str2);

	return 0;
}
char * sappend(char *str1, char *str2)
{
	int i;
	int l;

	l = strlength(str2);	

	for(i = 0; str1[i] != '\0'; i++){
		str2[l + i] = str1[i];		//appending to string
	}

	str2[l+i] = '\0';

	return str2;
}	
