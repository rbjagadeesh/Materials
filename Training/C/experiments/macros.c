/*9. Write macros for the following using bitwise operations:
  a. To find maximum and minimum of 2 numbers
  b. To clear right most set bit in a number
  c. To clear left most set bit in a number
  d. To set right most cleared bit in a number
  e. To set left most cleared bit in a number
  f. To set bits from bit position ‘s’ to bit position ‘d’ in a given number and clear rest of the bits
  g. To clear bits from bit position ‘s’ to bit position ‘d’ in a given number and set rest of the bits
  h. To toggle bits from bit position ‘s’ to bit position ‘d’ in a given number*/


#include<stdio.h>


# define max(x,y) (x^((x^y) & -(x<y)))
# define min(x,y) (y^((x^y) & -(x<y))) 
# define clear_right_most_set_bit(x) (x&(x-1))
# define clear_left_most_set_bit(count,x) (x&(~(1<<count)))
# define set_right_most_clear_bit(x) (x|(x+1)) 
# define set_left_most_cleared_bit(count,n) (n&(~(1<<count)))
# define set_s_to_d_clear_rest(s,d) ((~(~0<<((d-s)+1))<<s))
# define s_to_d_toggle(n,s,d) (n^(~(~0<<(d-s+1))<<s))
# define clear_s_to_d_set_rest(n,s,d) (~((~(~0<<(d-s+1)))<<s)) 

void show_bit( int );
int main( )
{
	int n;		/* Number entered */
	int ch;		/* Choice*/
	int num1;		/* Number entered to find min and max*/
	int num2;		/* Number entered to find min and max*/
	int r1;		/* Holds the maximum value */
	int r2;		/* Holds the minimum value */
	int res;		/* Holds the final values of all macros */
	int count=0;	/* Holds the position of left most bit */
	int temp;		/* Holds the inverted value of the number */
	int s,d;		/* Holds the source and destination position */

	printf("Which operation you want to do?\n"
			"1. To find maximum and minimum of 2 numbers\n"
			"2. To clear right most set bit in a number\n"
			"3. To clear left most set bit in a number\n"
			"4. To set right most cleared bit in a number\n"
			"5. To set bits from  bit position s to bit position d in a given\n"
			"number and clear rest of the bits\n"
			"6. To toggle bits from bit position s to bit position d in a\n"
			"given number\n"
			"7. To set left most cleared bit in a number\n"
			"8. To clear bits from bit position ‘s’ to bit position ‘d’ in a\n"
			"given number and set rest of the bits\n" );

	scanf("%d",&ch);
	if(1 == ch)
	{
		printf(" Enter two numbers\n");
		scanf("%d %d",&num1,&num2);
		r1=max(num1,num2);
		r2=min(num1,num2);
		printf("Maximum value is %d and minimum value is %d\n",r1,r2);
	}

	else
	{
		printf(" Enter a number\n ");
		scanf("%d",&n);
		switch(ch)
		{
			case 2:
				res=clear_right_most_set_bit(n);
				printf("       	The     binary    representation  of  %d  is:",n);
				show_bit(n);
				printf("After clearing the right most set bit the number is:");
				show_bit(res);
				break;

			case 3:
				temp = n;
				while(temp > 1)
				{
					count++;
					temp>>=1;
				}
				res=clear_left_most_set_bit(count,n);
				printf("       	The     binary    representation  of  %d  is:",n);
				show_bit(n);
				printf("After clearing the left  most set bit the number is:");
				show_bit(res);
				break;
			case 4:
				res=set_right_most_clear_bit(n);
				printf("       The     binary    representation  of  %d  is:",n);
				show_bit(n);
				printf("After setting right most cleared bit the  number is:");
				show_bit(res);
				break;
			case 5:
				printf(" Enter s and d left adjusted\n");
				scanf("%d %d",&s, &d);
				res=set_s_to_d_clear_rest(s,d);
				printf("	The 	binary	 representation  of %d is:\n",n);
				show_bit(n);
				printf("After setting bits from %d to %d and clearing the rest:\n",s,d);
				show_bit(res);
				break;
			case 6:
				printf(" Enter s and d left adjusted\n");
				scanf("%d %d",&s,&d);
				res=s_to_d_toggle(n,s,d);
				printf("The binary representation of   %d   is:",n);
				show_bit(n);
				printf("After toggling bits from %d to %d is  :",s,d);
				show_bit(res);
				break;
			case 7:
				temp = n;
				temp=~temp;
				while(temp > 1)
				{
					count++;
					temp>>=1;
				}
				res=set_left_most_cleared_bit(count,n);
				printf("The  binary  representation  of  %d  is:",n);
				show_bit(n);
				printf("After setting the left most cleared bit:");
				show_bit(res);
				break;
			case 8:
				printf(" Enter s and d left adjusted\n");
				scanf("%d %d",&s,&d);
				res=clear_s_to_d_set_rest(n,s,d);
				printf("	The	 binary 	representation\n"
						"of %d is:\n",n);
				show_bit(n);
				printf("After clearing %d to %d bits and setting the\n"
						"rest:\n",s,d);
				show_bit(res);
				break;											

			default:
				printf("Enter a valid choice\n");

		}
	}
	return 0;
}
/*..........
  This function displays the binary format of the number in 32 bits
  ....*/


void show_bit(int n)
{
	int i;
	for(i=31;i>=0;i--) {
		(n & (1<<i)) ? printf("1"):printf("0");
		if(!(i%8))
			printf(" ");
	}
	putchar(10);
}
