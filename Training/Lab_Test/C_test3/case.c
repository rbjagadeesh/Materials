#include <stdio.h>
#define diff 32

int main(void)
{

	FILE *fp;

	char ch;

	fp = fopen("text.txt","r+");
	
	while ((ch = fgetc(fp)) != EOF) {
		fseek (fp,-1,SEEK_CUR);
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch + diff;
			fputc(ch,fp);
		}
		else if (ch >= 'a' && ch <= 'z') {
			ch = ch - diff;
			fputc(ch,fp);
		}
		else {
			fputc(ch,fp);
		}	
	}
	
	fclose (fp);
	return 0;
}
