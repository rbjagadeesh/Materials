#include <stdio.h>
#include <string.h>
extern int myatoi(char *);
#if 0
int main(int argc)
{
	printf ("no of files in a folder is %d\n", argc);
	return 0;
}
#endif
#if 0
int main(int argc,char * argv[])
{
	int count = 0;
	int i;
	int j;

	for(i = 0; argc != 0; i++, argc--) {
		for(j = 0; argv[i][j] != 0; j++) {
			if( argv[i][j] == '.' && argv[i][j+1] == 'c' && argv[i][j+2] == '\0') {
				count++; 
			} else {
				continue;
			}
		}
	}
	printf ("number of c files is %d\n", count);

	return 0;
}
#endif
#if 1
int main(int argc, char *argv[])
{
	int calc(char *oper, char * n1, char * n2);
	int (*fp)(char *oper, char * n1, char * n2);		//function pointer
	fp = calc;
	fp(argv[1], argv[2], argv[3]); 	//invoking calc function
	printf("%p\n", calc);
	printf("%d\n", sizeof(calc));

	return 0;
}
int calc(char *oper, char * n1, char * n2)
{
	int a =  myatoi(n1);
	int b =  myatoi(n2);

	if(strcmp(oper,"add") == 0) {
		printf ("addition value is %d\n", (a + b));
	}else if (strcmp(oper,"sub") == 0) {
		printf ("submission value is %d\n", (a - b));
	} else if (strcmp(oper,"mul") == 0) {
		printf ("multiple value is %d\n", (a * b));
	} else if (strcmp(oper,"div") == 0) {
		printf ("divison value is %d\n", (a / b));
	} else {
		printf ("Invalid input\n");
	}
	return 0;
}
#endif
