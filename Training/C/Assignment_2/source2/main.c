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

	enum str { copy = 1, copyn, find_c, append, append_n, cmp_str, cmp_istr, cntchar, strtok, pal, rev_str, squeeze, rotate_str,  rm_str, insert};

	do {
		printf ("enter your choice ");
		scanf ("%d", &choice);

		switch (choice) {

			case copy:
				printf (" 1. copy string into destination\n");
				getchar();
				ass2_exp1();
				break;
			case copyn:
				printf (" 2. copy n characters from source to destination\n");
				getchar();
				ass2_exp2();
				break;
			case find_c:
				printf (" 3. occurance of c in string\n");
				getchar();
				ass2_exp3();
				break;
			case append:
				printf (" 4. string append\n");
				getchar();
				ass2_exp4();
				break;
			case append_n:
				printf (" 5. string append n characters from s to d\n");
				getchar();
				ass2_exp5();
				break;
			case cmp_str:
				printf (" 6. compare strings\n");
				getchar();
				ass2_exp6();
				break;
			case cmp_istr:
				printf (" 7. compare strings ignore case\n");
				getchar();
				ass2_exp7();
				break;
			case cntchar:
				printf (" 8. count initial set of chars in buf1\n");
				getchar();
				ass2_exp8();
				break;
			case strtok:
				printf (" 9. strtok\n");
				getchar();
				ass2_exp9();
				break;
			case pal:
				printf (" 10.palindrome\n");
				getchar();
				ass2_exp10();
				break;
			case rev_str:
				printf (" 11.reverse string\n");
				getchar();
				ass2_exp11();
				break;
			case squeeze:
				printf (" 12.squeeze string\n");
				getchar();
				ass2_exp12();
				break;
			case rotate_str:
				printf (" 13.Given string is rotating string of another string\n");
				getchar();
				ass2_exp13();
				break;
			case rm_str:
				printf (" 14.remove substring\n");
				getchar();
				ass2_exp14();
				break;
			case insert:
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
