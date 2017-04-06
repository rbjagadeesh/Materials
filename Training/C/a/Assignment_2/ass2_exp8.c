#include <stdio.h>
#include <stdlib.h>
#define MAX 256
size_t str_spn(const char *buf1, const char *buf2);

int main()
{
	char *ptr;
	char buf1[20];
	char buf2[20];

	printf ("enter string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(buf1, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

	printf ("source string sbuf is %s\n", buf1);
	
	printf ("enter another string ");

	if(((ptr = ((char *)(malloc(sizeof(char) * MAX)))) == NULL)) {
		perror ("malloc failed");
		exit(1);
	}

	if(NULL == (fgets(buf2, MAX, stdin))){
		perror ("fgets failed");
		exit(1);
	}

	printf (" string buf2 is %s\n", buf2);

	printf ("count of charcaters in buf1 is %d\n", str_spn(buf1, buf2));

	return 0;
}
size_t str_spn(const char *buf1, const char *buf2)
{
	int i = 0;
	int j = 0;

	for(j = 0; buf2[j] != '\n'; j++){
		if(buf1[i] == buf2[j]) {
			i++;
			j = 0;
		}
	}
	return i;
}
	
