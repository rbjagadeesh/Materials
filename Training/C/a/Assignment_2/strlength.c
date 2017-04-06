#include <stdio.h>

int strlength(char *str)
{
	int l = 0;
	int i = 0;

	while (str[i] != '\0') {
		l++;
	}
	
	return l;
}
