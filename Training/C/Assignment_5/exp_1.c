#include <stdio.h>
#include <stdlib.h>

int input();
int exp_1();
int exp_2();
int exp_3();
int exp_4();
int exp_5();
int exp_6();
FILE *fp;
FILE *fp1;
int i;
int n;
char ch;

struct EH {
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};

struct EH e[10];	

int main(void)
{
	char ch;
	int c;

	printf ("   Menu\n1.uppercase to lowercase\n2. search string and print line\n3. remove comments\n");
	printf ("4. count words\n5. write info into file\n6. read info from file\n");

	do {

		printf ("enter ur choice");
		scanf ("%d", &c);

		switch(c){
			case 1 : 
				exp_1();
				break;
			case 2 : 
				exp_2();
				break;
			case 3 : 
				exp_3();
				break;
			case 4 : 
				exp_4();
				break;
			case 5 : 
				exp_5();
				break;
			case 6 : 
				exp_6();
				break;
		}
label:	printf ("do u want to continue [y/n]");
		getchar();
		scanf ("%c", &ch);

		if (ch == 'y') 
			continue;
		else if (ch == 'n') 
			return 0;
		else {
			printf ("invalid option \n");
			goto label;
		}
	}while(1);
	return 0;	
}

int exp_1()
{
	char ch;

	fp = fopen("hello.txt", "r");
	fp1 = fopen("hello.txt", "a");

	if (fp == NULL) {
		perror ("fopen failed");
		exit(1);
	}

	while((ch = getc(fp)) != EOF) {
		if(ch >= 'A' && ch <= 'Z') {
			ch = ch + 32;
			fputc(ch, fp1);
		}
		else {
			fputc(ch, fp1);		
		}
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}	

int exp_2()
{
	char s[20];
	int cnt = 0;

	printf ("Enter string ");
	scanf ("%s", s);

	fp = fopen("hii.txt", "r");
	fp1 = fopen("hii.txt", "a");

	while ((ch = fgetc(fp) != EOF )) {
		if (ch != '\n')
			cnt++;
		else
			cnt = 0;

		for (i = 0;(ch = fgetc(fp)) == s[i]; i++) {
			cnt++;
		}
		if (s[i] == '\0') {
			fseek(fp1, -cnt, SEEK_CUR);
			while((ch = fgetc(fp1)) != '\n')
				fputc(ch, fp1);
		} 
	}

	fclose(fp);
	fclose(fp1);
	return 0;
}

int exp_3()
{

	fp = fopen("comments.txt", "r");
	fp1 = fopen("comments.txt", "a");

	while((ch = fgetc(fp)) != EOF) {
		if( ch == '"'){
			fputc(ch,fp1);
			while(( ch = fgetc(fp)) != '"') {
				fputc(ch,fp1);
			}
			fputc(ch,fp1);
		}
		else if(ch == '<' ){
			fputc(ch,fp1);
			while((ch = fgetc(fp)) != '>') {
				fputc(ch,fp1);       
			}
			fputc(ch,fp1);
		}   
		else if(ch == '/') {
			if((ch = fgetc(fp))  == '*' ) {
				while((ch =fgetc(fp) != '*') || ((ch= fgetc(fp)) != '/')){      
					continue;
				} 
			} else if((ch == '/')){
				while(( ch =fgetc(fp)) != '\n')
					continue;
				fputc(ch,fp1);
			} else
				fputc(ch,fp1);
		}

		else {
			fputc(ch,fp1);
		}
	}

	fclose(fp);
	fclose(fp1);
	return 0;
}	
int exp_4()
{

	int count = 0;

	fp = fopen("hello.txt", "r");

	if (fp == NULL) {
		perror ("fopen failed");
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

int exp_5()
{
	fp = fopen ("info.db", "w");

	input();


	fwrite (e, sizeof(e), 2, fp);

	fclose(fp);
	return 0;
}

int exp_6()
{
	char buf[100];

	fp = fopen ("info.db", "w");
	fp1 = fopen ("info.db", "r");

	input();

	fwrite (e, sizeof(e), 2, fp);
	fread (buf, sizeof(e), 2, fp1);

	for (i = 0; i < n; i++) { 
		printf ("ident is   %s\n", e[i].e_ident);
		printf ("type is    %hi\n", e[i].e_type);
		printf ("machine is %hi\n", e[i].e_machine);
		printf ("version is %d\n", e[i].e_version);
		printf ("entry is   %u\n\n", e[i].e_entry);
	}

	fclose(fp);
	fclose(fp1);
	return 0;
}

int input()
{
	printf ("how many records do you want to write ");
	scanf ("%d", &n);

	for (i = 0; i < n; i++) {
		printf ("Enter data for %dth element\n", i);
		scanf ("%s", e[i].e_ident);
		scanf ("%hi", &e[i].e_type); 
		scanf ("%hi", &e[i].e_machine); 
		scanf ("%d", &e[i].e_version); 
		scanf ("%u", &e[i].e_entry); 
	}

	return 0;
}
