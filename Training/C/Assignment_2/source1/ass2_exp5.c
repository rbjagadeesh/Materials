#include <stdio.h>
#include <stdlib.h>
#define MAX 256
char * snappend(char *str1, char *str2, int n);
int input(char *, char *);
int strlength(char *);
int ass2_exp5()
{
	char str1[20];
	char str2[20];
	int l;
	int n;

	input(str1, str2);

	l = strlength(str1);	
	str1[l - 1] = '\0';

	l = strlength(str2);	
	str2[l - 1] = '\0';
	printf ("enter number of characters to append ");
	scanf ("%d", &n);

	snappend(str1, str2, n);

	printf ("appended string  %s\n", str2);

	return 0;
}
char * snappend(char *str1, char *str2, int n)
{
	int i;
	int l;

	l = strlength(str2);	

	for(i = 0; i < n; i++){
		str2[l + i] = str1[i];			//appending
	}

	str2[l+i] = '\0';

	return str2;
}	
