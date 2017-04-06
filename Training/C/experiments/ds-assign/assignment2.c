#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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
	char ch;
	int choice;

	printf ("   Menu\n1.copy string into destination\n2. copy n characters from source to destination\n3. occurance of c in string\n");
	printf ("4. string append\n5. string append n characters from s to d\n6. compare strings\n7. compare strings ignore case\n");
	printf ("8. count initial set of chars in buf1\n9.strtok\n10.palindrome\n11.reverse string\n12.squeeze string\n13.Given string is rotating string of another string\n");
	printf ("14.remove substring\n15.insert character in a string\n");

	do {
		printf ("enter your choice ");
		scanf ("%d", &choice);

		switch (choice) {

			case 1:
				printf (" 1. copy string into destination\n");
				getchar();
				ass2_exp1();
				break;
			case 2:
				printf (" 2. copy n characters from source to destination\n");
				getchar();
				ass2_exp2();
				break;
			case 3:
				printf (" 3. occurance of c in string\n");
				getchar();
				ass2_exp3();
				break;
			case 4:
				printf (" 4. string append\n");
				getchar();
				ass2_exp4();
				break;
			case 5:
				printf (" 5. string append n characters from s to d\n");
				getchar();
				ass2_exp5();
				break;
			case 6:
				printf (" 6. compare strings\n");
				getchar();
				ass2_exp6();
				break;
			case 7:
				printf (" 7. compare strings ignore case\n");
				getchar();
				ass2_exp7();
				break;
			case 8:
				printf (" 8. count initial set of chars in buf1\n");
				getchar();
				ass2_exp8();
				break;
			case 9:
				printf (" 9. strtok\n");
				getchar();
				ass2_exp9();
				break;
			case 10:
				printf (" 10.palindrome\n");
				getchar();
				ass2_exp10();
				break;
			case 11:
				printf (" 11.reverse string\n");
				getchar();
				ass2_exp11();
				break;
			case 12:
				printf (" 12.squeeze string\n");
				getchar();
				ass2_exp12();
				break;
			case 13:
				printf (" 13.Given string is rotating string of another string\n");
				getchar();
				ass2_exp13();
				break;
			case 14:
				printf (" 14.remove substring\n");
				getchar();
				ass2_exp14();
				break;
			case 15:
				printf (" 15.insert character in a string\n");
				getchar();
				ass2_exp15();
				break;
		}

		printf ("do you want to continue [y/n] ");
		scanf ("%c", &ch);
		getchar();

		if (ch == 'y') {
			continue;
		} else if (ch == 'n') {
			return 0;
		} else {
			printf ("invalid input ");
			continue;
		}
	}while(1);
	return 0;
}
