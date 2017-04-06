#include <stdio.h>
#include <stdlib.h>
#define MAX 256
char *rem_sstr(char *str,char *sstr);
int input(char *, char *);
int strlength(char *);

int ass2_exp14()
{
	char str[20];
	char sstr[20];

	input(str, sstr);
	rem_sstr(str, sstr);
return 0;
}
char *rem_sstr(char *str,char *sstr)
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int c = 0;

	l = strlength(sstr);
	
	for ( i= 0; str[i] != '\0'; i++) {
		j = i;
		c= 0;
		for ( k =  0; sstr[k] != '\0'; k++,j++) {
			if (sstr[k] == str[j]) 
				c++;
			else
				break;
		}
		if (c == l) {
			for (m = j - c - 1 ; str[m] != '\0'; m++) {
				str[m] = str[m+c+1];
			}
		}
	}
	printf (" str %s\n", str);
return str;
}
