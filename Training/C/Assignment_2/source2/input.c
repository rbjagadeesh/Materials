#include <stdio.h>
#include <stdlib.h>
#define MAX 256
extern int input(char *str1, char *str2);
extern int inputsingle(char *str1);
int input(char *str1, char *str2)
{
	char *ptr;
	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(str1, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

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

	printf (" string str2 is %s\n", str2);

return 0;
}
int inputsingle(char *str1)
{
	char *ptr;
	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(str1, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

	printf ("string str1 is %s\n", str1);

	return 0;
}
