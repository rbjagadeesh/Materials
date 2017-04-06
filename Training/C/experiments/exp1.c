#include<stdio.h>
#include<stdlib.h>

#if 0
// 1st
int main(void)
{
	printf ("%d\n", printf("%u\n", 45555)); //display positive integer value
	printf("%i\n", 455);	//display a number in signed form
	printf("%d\n", +455);	//use '+' sign for a number and display integer 
	printf("%ld\n", 455);  //use '-' sign for a number and display integer
	printf("%hd\n", 32000);			//length modifiers
	printf("%ld\n", 2000000000L);	//legth modifiers
	printf("%o\n", 455);	//octal form of integer number
	printf("%u\n", 455);  //display positive number in unsigned format
	printf("%u\n", -1); //display negative number in unsigned format
	printf("%x\n", 455); //display in hex form
	printf("%X\n", 455); 

return 0;
}
#endif
#if 0
// 2nd
int main(void)
{
	printf("e = %e\n", 321.65); //Display floating point number in scientific exponential form. 
	printf("e = %e\n", +321.65); //use '+' sign for the same above.
	printf("e = %e\n", -321.65); // use '-' sign for the same above.
	printf("E = %E\n", 321.65); //We can use E for displaying floating point number in scientific exponential form.
	printf("f = %f\n", 321.65); //double precision floating point number
	printf("g = %g\n", 321.65); // %g will display which ever the shortest number among %f and %e
	printf("G = %G\n", 321.65); //  %g will display which ever the shortest number among %f and %E
	printf("a = %a\n", 321.65); //floating point value will be displayed in hex form
	printf("%*d\n", 5, 10); //giving field width using '*'. 
	printf("%.*s\n", 3, "abcdef"); // giving precision to a string using '*'.

return 0;
}
#endif
#if 0
// 3rd
int main(void)
{
	printf("%4d\n", 1); //three spaces will be their before as number as number width is 1 and we have given field width of 4
	printf("%4d\n", 12); //two spaces will be their before as number as number width is 2 and we have given field width of 4
	printf("%4d\n", 123);  //one space will be their before as number as number width is 3 and we have given field width of 4
	printf("%4d\n", 1234);  // number width is same as field with in format specifier
	printf("%4d\n", 12345); //overflow of field width, this number will exceed the width 

	//will be same as above but one space will be reserved before number for negation sign
	printf("%4d\n", -1);
	printf("%4d\n", -12);
	printf("%4d\n", -123);
	printf("%4d\n", -1234);
	printf("%4d\n", -12345);

	return 0;
}
#endif
#if 0
int main()
{	
	int a = 10;

	printf("global edge\n\b");
	printf("\rglobal edge");

return 0;
}
#endif
#if 0
// 4th
int main(void)
{
	int i =  873;
	double f = 123.94566;
	char s[] = "global edge";
	
	printf("%.4d\n%.9d\n\n", i, i); // given a precision of 4 and 9 to integer 873 using %d specifier

	printf("%.5f\n%e\n%.6g\n\n", f, f, f); /* given a precision of 5 and 6 to a folating point number in %f , %e and %g form to know the 								difference of f, g and e.*/

	printf("%9.5s\n", s); // give field width as well as precision to a string.
	printf("%-5.7s\n", s); //using '-' sign for field width 

	return 0;
}
#endif

#if 0
// 5th
int main(void)
{
	printf("%10s%10d%10c%6f\n\n", "hello", 7, 'a', 1.23); // shift these data 10 space right. 
	printf("%-10s%-10d%-10c%-10f\n", "hello", 7, 'a', 1.23); // again shift those data 10 space back using '-' sign. 

	return 0;
}
#endif

#if 0
// 6th
int main(void)
{
	char *str = "Global";	//declare const string

	printf("%010d\n%010d\n", 786, -786); //append zero before number to the remaining field width. 

	printf("%+d\n%+d\n", 786, -786); // use of '+' flag to give positive sign to only positive number.

	printf("%-10d\n%-d\n", 786, -786); //use of '-' flag
	printf("% d\n% d\n", 547, -547); //use of "space" flag to show a space before a number signed numbers
	printf("str = %s\n", str + 1); // display string after one character

return 0;
}
#endif

#if 0
// 7th
int main(void)
{
	int c = 1427;
	double p = 1427.120;

	printf("%o\n", c); //octal form of signed integer value.
	printf("%#o\n", c); //append 0 before octal form of signed number.
	printf("%x\n", c); //hex form of signed integer value.
	printf("%#x\n", c); //append 0x before octal form of signed number.
	printf("%X\n", c); //hex form of signed integer value.
	printf("%#X\n", c); //append 0X before octal form of signed number.
	printf("%g\n", p); /*zeros will not be displayed as it is the all zeros and precison of number will be 						removed   */ 	
	printf("%#g\n", p);//number will be displayed as it is though after precision their are zeros.
	printf("%G\n", p); /*zeros will not be displayed as it is the all zeros and precison of number will be 						removed   */                                                      
    	printf("%#G\n", p);  //number will be displayed as it is though after precision their are zeros.

	printf("%+09d\n", 452); //give '+' flag, append 0 before number with 9 field width.
	printf("%09d\n", 452); //append 0 before number with 9 field width.
	
return 0;
}
#endif

#if 0
//Que Why \n is not used to use in scanf?
int main(void)
{
	int a;
	int b;
	char c;
	printf("Enter:");
	scanf("%d,%d", &a, &b); /* after running the program try to give input like (1) 5,6 (2) 5, 6 (3) 5 , 6 (4) 5 ,6 see the results what 						will happen if give space like this. scanf response towards space */   
	printf("%d %d\n", a, b); 
	scanf("%*[ \n\t]%c", &c); //skip new-line, tabs and spaces from given input.
	printf("%c\n",c); 
return 0;
}
#endif
#if 0
int main(void)
{
	char arr[5];

	scanf("%s",arr); //scanf will allow to input a data overflowing the bound of 5. 
	printf("%s",arr);

	return 0;
}
#endif
#if 0
int main(void)
{
	char arr1[5];
	char ch[6];
	char arr2[7];
	/* give input as " abcedefghi " for both arr1 and arr2 
		data of arr1 and arr2 are overlapping with memory assigned to ch as the data is overflowing */ 		
	printf("Enter your string:");
	scanf("%s",arr1);
//	printf("%s",arr1);
	printf("Enter your string:"); 
	scanf("%7s",arr2);
	printf("%s\n %s",arr1,arr2);
	printf("\n%s", ch);
return 0;	
}
#endif
#if 0
/* use of scanf in while loop and for loop */
int main(void)
{
    int  n;
	int i = 0;
//  while(scanf("%d", &n) == 1)
  //	printf("%d\n", n);

	for((i = scanf("%d", &n)); i < 5 ; i++ )
		printf("Hello world\n");
return 0;
}
#endif
#if 0
/* concept of scan set, A-Z number are only displayed others are skipped.*/
int main(void)
{
	char str[5];
	printf("Enter a string: ");
	scanf("%[A-Z]s", str);

	printf("You entered: %s\n", str);

return 0;
}
#endif
#if 0
/* gets is not working as it is not specifying the space required for string to input.*/
int main()
{
   char str[50];

   printf("Enter a string : ");
   gets(str);

   printf("You entered: %s", str);

   return(0);
}
#endif

#if 0
#include <stdarg.h>
double average(int num,...)
{
	va_list valist; //declaration of valist of type va_list,variable capable of storing a variable-length argument list.
	double sum = 0.0;
	int i;
	va_start(valist, num); //va_start() macro initializes valist for subsequent use by va_arg()

		for (i = 0; i < num; i++) {
			sum += va_arg(valist, int); //access all the arguments pointed by va_list of type int
		}

	va_end(valist); /*clean memory reserved for valist */

return sum/num;
}

int main()
{
	printf("Average is = %f\n", average(4, 2, 7, 4, 5)); //first argument is the number of arguments
	printf("Average is = %f\n", average(3, 5, 'A', 15));

return 0;
}

#endif

