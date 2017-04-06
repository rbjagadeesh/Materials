#include <stdio.h>
#include <stdlib.h>

int elfhdr_print(FILE *fp);
int section_hdr_print(FILE *fp);

FILE *fp;

int main ( void ) 
{

	int choice;
	char ch;

	fp = fopen ("elf", "r");

	elfhdr_print(fp);
	section_hdr_print(fp);
	printf (" 3. print program header\n");

	return 0;
}
