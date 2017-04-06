#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 256

int ass2_exp1();
int ass2_exp2();
int ass2_exp3();
int ass2_exp4();
int ass2_exp5();
int ass2_exp6();
int ass2_exp7();
int ass2_exp8();
int ass2_exp9();
int ass2_exp10();
int ass2_exp11();
int ass2_exp12();
int ass2_exp13();
int ass2_exp14();
int ass2_exp15();

int main(void)
{
	int choice;

	printf ("   Menu\n");
	printf (" 1. copy string into destination\n");
	printf (" 2. copy n characters from source to destination\n");
	printf (" 3. occurance of c in string\n");
	printf (" 4. string append\n");
	printf (" 5. string append n characters from s to d\n");
	printf (" 6. compare strings\n");
	printf (" 7. compare strings ignore case\n");
	printf (" 8. count initial set of chars in buf1\n");
	printf (" 9. strtok\n");
	printf (" 10.palindrome\n");
	printf (" 11.reverse string\n");
	printf (" 12.squeeze string\n");
	printf (" 13.Given string is rotating string of another string\n");
	printf (" 14.remove substring\n");
	printf (" 15.insert character in a string\n");
	
	printf ("enter your choice ");
	scanf ("%d", &choice);

	switch (choice) {

	case 1:
			printf (" 1. copy string into destination\n");
			ass2_exp1();
			break;
	case 2:
			printf (" 2. copy n characters from source to destination\n");
//			ass2_exp2();
			break;
	case 3:
			printf (" 3. occurance of c in string\n");
//			ass2_exp3();
			break;
	case 4:
			printf (" 4. string append\n");
//			ass2_exp4();
			break;
	case 5:
			printf (" 5. string append n characters from s to d\n");
//			ass2_exp5();
			break;
	case 6:
			printf (" 6. compare strings\n");
//			ass2_exp6();
			break;
	case 7:
			printf (" 7. compare strings ignore case\n");
//			ass2_exp7();
			break;
	case 8:
			printf (" 8. count initial set of chars in buf1\n");
//			ass2_exp8();
			break;
	case 9:
			printf (" 9. strtok\n");
//			ass2_exp9();
			break;
	case 10:
			printf (" 10.palindrome\n");
//			ass2_exp10();
			break;
	case 11:
			printf (" 11.reverse string\n");
//			ass2_exp11();
			break;
	case 12:
			printf (" 12.squeeze string\n");
//			ass2_exp12();
			break;
	case 13:
			printf (" 13.Given string is rotating string of another string\n");
//			ass2_exp13();
			break;
	case 14:
			printf (" 14.remove substring\n");
//			ass2_exp14();
			break;
	case 15:
			printf (" 15.insert character in a string\n");
//			ass2_exp15();
			break;
	}

return 0;
}
