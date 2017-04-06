#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 256

int rev(char *, char *, int, int);

int main(void)
{
	char *str1;
	char str[MAX];
	char revstr[MAX];
	int l = 0;
	int i = 1;

	printf ("enter string ");

	if((str1 = ((char *)(malloc(sizeof(char) * MAX)))) == NULL){
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == fgets(str,MAX,stdin)){
		perror ("fgets failed");
		exit(1);
	}
	
	printf ("given string %s", str);

	while(str[i] != '\0'){
		l++;
		i++;
	}

	printf ("length of str %d\n", l);

	i = 0;

	rev(str,revstr,i,l);

	return 0;
}

int rev(char *str, char *revstr, int i, int l)
{
	if(str[i] != '\0'){
		revstr[i] = str[l - 1];
		i++;
		l--;
		rev(str,revstr,i,l);
	}
	else{
		revstr[i] = '\0';
		printf ("reversed str %s\n", revstr);
	}

	return 0;
}

