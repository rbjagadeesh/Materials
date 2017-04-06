#include <stdio.h>
#include <unistd.h>

int main ( void )
{

	FILE *fp1;
	FILE *fp2;
	char *ch;

	fp1 = (FILE *) open("hii.txt","r"); 
	fp2 = (FILE *) open("hello.txt","w");
 
//	fd = (int ) fp1;

	read(1, ch, 100);
	write(1, ch, 100);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
