#include <stdio.h>
#include <stdlib.h>

int main()
{

	FILE *fp;
	char ch;
	int count = 0;

	fp = fopen("hello.txt", "r");

	if (fp == NULL) {
		perror ("getc failed");
		exit(1);
	}

	while((ch = getc(fp)) != EOF) {
		if(ch == '\n' || ch == '\t' || ch == ' ') {
			count++;
			while ((ch = getc(fp)) == '\n' || ch == '\t' || ch == ' ')
				continue;
		}
		else {
			continue;		
		}
	}
	printf ("Number of words in given file is %d\n", count);

	fclose(fp);
	return 0;
}		
