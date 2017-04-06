#include <stdio.h>
#include <stdlib.h>

int input(char *, char *);
int strlength(char *);

int ass2_exp6()
{
	char str1[20];
	char str2[20];
	int i = 0;
	int l;

	input(str1, str2);

	l = strlength(str1);	
	str1[l - 1] = '\0';

	l = strlength(str2);	
	str2[l - 1] = '\0';

	while ((str1[i] == str2[i]) && str1[i] != '\0' && str2[i] != '\0') {
		i++;						//compare strings
		continue;
	}

	if(str1[i] == str2[i]){
		printf ("strings are equal\n");
		return 0;
	}
	else if (str1[i] > str2[i]) {
		printf ("str1 is greater than str2\n");
		return 1;
	}
	else if (str1[i] < str2[i]) {
		printf ("str2 is greater than str1\n");
		return -1;
	}

	return 0;
}
