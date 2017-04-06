#include <stdio.h>
#include <stdlib.h>
#define MAX 256
size_t str_spn(const char *buf1, const char *buf2);
int input(char *, char *);

int ass2_exp8()
{
	char *ptr;
	char buf1[20];
	char buf2[20];

	input(buf1, buf2);
	printf ("count of charcaters in buf1 is %d\n", str_spn(buf1, buf2));

	return 0;
}
size_t str_spn(const char *buf1, const char *buf2)
{
	int i = 0;
	int j = 0;

	for(j = 0; buf2[j] != '\0'; j++){
		if(buf1[i] == buf2[j]) {
			i++;						//counting no of characters
			j = 0;
		}
	}
	return i;
}

