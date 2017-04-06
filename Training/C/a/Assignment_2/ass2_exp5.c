#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
char * snappend(char *str1, char *str2, int n);

int main()
{
	char *ptr;
	char str1[20];
	char str2[20];
	int n;

	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(str1, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}
//	scanf ("%s", str1);

	printf ("string str1 is %s\n", str1);
	
	printf ("enter another string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(str2, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

//	scanf ("%s", str2);
	printf (" string str2 is %s\n", str2);

	printf (" Enter no of characters to append");
	scanf ("%d", &n);

	snappend(str1, str2, n);

//	printf ("appended string  %s\n", str2);

return 0;
}
char * snappend(char *str1, char *str2, int n)
{
	int i;
	int l;

	l = strlen(str2);	

//	printf ("l value %d\n", l);
	for(i = 0; i < n; i++){
		str2[l+i+1] = str1[i];
	}

	str2[l+i+1] = '\n';

	printf ("appended string  %s", str2);
	
	return str2;
}	
