#include <stdio.h>
#define diff 32

int main(void)
{

	FILE *fp;
	FILE *fp1;
	char ch;

	fp = fopen("text.txt","r");
	fp1 = fopen("text1.txt","w+");

	while ((ch = fgetc(fp)) != EOF) {
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch + diff;
			fputc(ch,fp1);
		}
		else if (ch >= 'a' && ch <= 'z') {
			ch = ch - diff;
			fputc(ch,fp1);
		}
		else {
			fputc(ch,fp1);
		}
	}

	fclose (fp);
	fclose (fp1);
	return 0;
}
