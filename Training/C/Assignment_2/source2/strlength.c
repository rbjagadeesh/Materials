#include <stdio.h>
extern int strlength(char *);

int strlength(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i++;
	}
	
	return i;
}
