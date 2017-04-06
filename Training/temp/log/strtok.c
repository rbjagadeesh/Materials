#include <stdio.h>
#include <string.h>

int main (void)
{

	char str[] = "hello,hru,iamfine,hru";
	char *ptr;

	ptr = strtok (str, ",");
	printf ("\n%s\n", str);
	
	while(ptr != NULL){
		printf ("%s\n", ptr);
		ptr = strtok (NULL, ",");
	}

	printf ("\n%s\n", str);
	return 0;
}
