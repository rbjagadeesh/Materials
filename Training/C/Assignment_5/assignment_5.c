#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#if 0
int main(void)
{
	FILE *ftr;
	FILE *ftr1;
	char ch;

	ftr = fopen("./s1.text", "r+");
	if(ftr == NULL) {
		perror("File doesnot exist");
		exit(1);
	}

	ftr1 = fopen("./s1.text", "r+");
	if(ftr1 == NULL) {
		perror("File doesnot exist");
		exit(1);
	}


	while((ch = fgetc(ftr)) != EOF) {

		if(ch >= 'A' && ch <= 'Z')	{
			ch = ch + 32;
			fputc(ch, ftr1); 
		}
		else {
			fputc(ch, ftr1);   
		}
	}
	fclose(ftr);
	fclose(ftr1);
	return 0;
}
#endif
#if 0
int main(void)
{	

	FILE *fp;
	FILE *fp1;
	char c;

	fp = fopen("1.c","r+");
	if(fp == NULL ) {
		perror("File doesnot exit");
		exit(1);
	}
	fp1 = fopen("2.c","w");
	if(fp1 == NULL ) {
		perror("File doesnot exit");
		exit(1);
	}		
	while((c = fgetc(fp)) != EOF) {
		if( c == '"'){
			fputc(c,fp1);
			while(( c = fgetc(fp)) != '"') {
				fputc(c,fp1);
			}
			fputc(c,fp1);
		}
		else if(c == '<' ){
			fputc(c,fp1);
			while((c = fgetc(fp)) != '>') {
				fputc(c,fp1);		
			}
			fputc(c,fp1);
		}	
		else if(c == '/') {
			if((c = fgetc(fp))  == '*' ) {
				while((c =fgetc(fp) != '*') || ((c= fgetc(fp)) != '/')){
					continue;
				} 
			} else if((c == '/')){
				while(( c =fgetc(fp)) != '\n')
					continue;
				fputc(c,fp1);
			} else
				fputc(c,fp1);
		}

		else {
			fputc(c,fp1);
		}
	}

	fclose(fp);
	fclose(fp1);

	return 0;

}

#endif

#if 0
extern int lenght(char *s);
extern int search(char *str,char *s);
int main(void)
{
	FILE *f;
	char str[100] ;
	char s[100];
	int lineno = 0;
	int c;
	int flag;

	printf("enter a string to search in a file:");
	fgets(str,10,stdin);
	c = lenght(str);
	if( c > 0 &&  str[c - 1] == '\n')
		str[c- 1 ] = '\0' ;

	f = fopen("s2.text","r");
	if( f == NULL) {
		perror("Flie doesnot exit");
		exit(1);
	}

	while(fgets(s,100,f) != NULL) {

		if(search(s,str)) {
			lineno++;
			printf("string %s is found in "
					"----> %s <----"
					" at line number %d\n",str,s,lineno);
			flag = 1;
			break;

		}else {
			lineno++;
			continue; 	
		}
	}
	if(flag == 0)
		printf("String not found\n");

	fclose(f);
	return 0;

}  
#endif

#if 0
int main(void)
{
	FILE *ptr;
	char ch;
	int count = 0;

	ptr = fopen("s2.text","r");
	if(ptr == NULL) {
		perror("File doesnot exist");
		exit(1);
	}

	while((ch = fgetc(ptr)) != EOF) {

		if(ch == '\0' || ch == '\n' || ch == 32 || ch == '\t'  )  {		

			while((ch = fgetc(ptr)) == 32 || ch == '\t'|| ch == '\n') {
				count = 0;
				continue;
			}
			count++;
		} 
	}
	fclose(ptr);			

	printf("Number of words in  given file = %d\n",count);

	return 0;

}
#endif
#if 0
struct EH {
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};

int main( void )
{ 
	struct EH e[10];
	int i;
	FILE *f;
	f = fopen("info.db", "w");
	if(f == NULL) {
		perror("File doesnot exist");
		exit(1);
	}

	for(i = 0; i < 2 ; i++) {

		printf("enter the e_ident =");
		scanf("%s", e[i].e_ident);
		printf("enter e_type=");
		scanf("%hi", &e[i].e_type);
		printf("enter the e_machine =");
		scanf("%hi", &e[i].e_machine);
		printf("enter the e_version=");
		scanf("%d", &e[i].e_version);
		printf("enter the e_entry=");
		scanf("%d", &e[i].e_entry);

	}
	fwrite(e , sizeof(e), 1, f);
	fclose(f);		 
} 
#endif
#if 1
struct EH {
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};

int main()
{
	struct EH b[2];
	FILE *fp;
	int i;
	fp = fopen("info.db", "r");
	if(fp == NULL) {
		perror("File doesno exist");
		exit(1);
	}

	fread(b, sizeof(b), 1, fp);
	for( i = 0; i < 2; i++) {
		printf(" the e_ident =%s\n", b[i].e_ident);
		printf(" e_type=%hi\n", b[i].e_type);
		printf(" the e_machine =%hi\n", b[i].e_machine);
		printf(" the e_version=%d\n", b[i].e_version);
		printf(" the e_entry=%d\n", b[i].e_entry);
	}
	fclose(fp);

}
#endif



