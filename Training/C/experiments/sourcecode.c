#include <stdio.h>

int main(void)
{
	char ch; 
	FILE *fp = fopen(__FILE__, "r");

	printf("file name = %s\n\n",__FILE__);

	while (ch != EOF) {
		ch = fgetc(fp);
		putchar(ch);
	}

	fclose(fp);

	return 0;
}
