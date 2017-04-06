#include <stdio.h>

int showbits(int n);

int bit_swap(int, int, int);
int exp_2(int, int,int,int);
int bit_copy(int,int,int,int,int);
int exp_4();
int	even_bit_toggle(int n);		
int	odd_bit_toggle(int n);		
int exp_5(int,int);
int exp_6(int n);
unsigned int left_rotate_bits (unsigned int);
unsigned int right_rotate_bits (unsigned int);
unsigned int left_rotate_n_bits (unsigned int);
unsigned int right_rotate_n_bits (unsigned int);	
int exp_7();
int count_bit_set(int n);
int count_bit_clear(int n);
int exp_8();
int exp_9();
int setbits(int,int,int,int);
int invert(int,int,int);
int exp_12();

int n;
int s;
int d;
int pos;
int x;
int snum;
int dnum;

int main(void)
{
	int choice;

	printf ("   Menu\n");
	printf (" 1. bit swap\n");
	printf (" 2. bit swap in s and d\n");
	printf (" 3. n bit swap in s and d\n");
	printf (" 4. toggle bit\n");
	printf (" 5. set bit\n");
	printf (" 6. rotate functions\n");
	printf (" 7. count no of bit set and cleared\n");
	printf (" 8. fuction for trailing and leading bits\n");
	printf (" 9. functions of macros\n");
	printf (" 10.setbits function\n");
	printf (" 11.invert function\n");
	printf (" 12.getbits function\n");
	
	printf ("enter your choice ");
	scanf ("%d", &choice);

	switch (choice) {

	case 1:
			printf (" bit swap\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);
			showbits(n);

			printf ("\n Enter source position ");
			scanf ("%d", &s);
			
			printf ("\n Enter destination position ");
			scanf ("%d", &d);

//		 	bit_swap(n,s,d);

			break;
	case 2:

//			int snum;
//			int dnum;

			printf (" bit swapin s and d\n");
			
			printf ("\n Enter source Number ");
			scanf ("%d", &snum);
			showbits(snum);
			
			printf ("\n Enter destination Number ");
			scanf ("%d", &dnum);
			showbits(dnum);
			
			printf ("\n Enter source position ");
			scanf ("%d", &s);
			
			printf ("\n Enter destination position ");
			scanf ("%d", &d);

		 	exp_2(snum,dnum,s,d);

			break;
	case 3:
//			int len;
//			int dnum;

			printf (" n bit swap in s and d\n");
			
			printf ("\n Enter source Number ");
			scanf ("%d", &snum);
			showbits(snum);
			
			printf ("\n Enter destination Number ");
			scanf ("%d", &dnum);
			showbits(dnum);

			printf ("\n Enter lentgh ");
			scanf ("%d", &n);

			printf ("\n Enter source position ");
			scanf ("%d", &s);
			
			printf ("\n Enter destination position ");
			scanf ("%d", &d);
		 	
//			bit_copy(snum,dnum,n,s,d);

			break;
	case 4:
			printf (" toggle bit\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);
			showbits(n);

	//	 	exp_4();

			break;
	case 5:
			printf (" set bit macro\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);
			showbits(n);
			
			printf ("\n Enter positoin ");
			scanf ("%d", &pos);

//		 	exp_5(n,pos);

			break;
	case 6:
			printf (" rotate funtion\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);
			showbits(n);

		 	exp_6(n);

			break;
	case 7:
			printf ("count no of bit set and cleared\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);
			showbits(n);

//			exp_7();

			break;
	case 8:
			printf ("fuction for trailing and leading bits\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);

			exp_8();

			break;
	case 9:
			printf (" functions of macros\n");

			printf ("\n Enter Number ");
			scanf ("%d", &n);

			exp_9();

			break;
	case 10:
			printf (" setbits function\n");
			int y;

			printf ("\n Enter Number ");
			scanf ("%d", &x);
			showbits(x);

			printf ("\n Enter destination Number ");
			scanf ("%d", &y);
			showbits(y);

			printf ("\n Enter lentgh ");
			scanf ("%d", &n);

			printf ("\n Enter position ");
			scanf ("%d", &pos);

//			setbits(x,pos,n,y);

			break;
	case 11:
	
			printf (" invert function\n");

			printf ("\n Enter Number ");
			scanf ("%d", &x);
			showbits(x);

			printf ("\n Enter lentgh ");
			scanf ("%d", &n);

			printf ("\n Enter position ");
			scanf ("%d", &pos);

			invert(x,pos,n);

			break;
	case 12:
			printf (" getbit \n");

			printf ("\n Enter Number ");
			scanf ("%d", &x);

			exp_12();

			break;
	}
return 0;
}
#if 0
int bit_swap(int n, int s, int d)
{
	int bit1;
	int bit2;
	int key = 1;

	if ( s < d) {
		s = s + d;
		d = s - d;
		s = s - d;
	}

	bit1 = ( n & (key << (s -1)));
	bit2 = ( n & (key << (d -1)));

	n = ( n & (~(1U << (s -1))));
	n = ( n & (~(1U << (d -1))));
	
	showbits(n);

	n = (n | (bit1 >> (s -d)));
	n = (n | (bit2 << (s - d)));

	printf ("after swap \n");
	showbits(n);

return 0;
}
#endif

int exp_2(int snum,int dnum, int s, int d)
{
	int bit1;
	int bit2;
	int key = 1;


	bit1 = ( snum & (key << (s -1)));
	bit2 = ( dnum & (key << (d -1)));

	snum = ( snum & (~(1U << (s -1))));
	dnum = ( dnum & (~(1U << (d -1))));
	
	if ( s < d) {
		s = s + d;
		d = s - d;
		s = s - d;
	}

	bit1 = (bit1 >> (s - d)) ;
	bit2 = (bit2 << (s - d)) ;

	snum = (snum | bit2 );
	dnum = (dnum | bit1 );

	printf ("after swap \n");
	showbits(snum);
	showbits(dnum);

return 0;
}
#if 0
int bit_copy(int snum, int dnum, int n, int s, int d)
{
	int bit1;

	bit1 = (snum & ((~ (~0 << n)) << (s - n)));
	dnum = (dnum & ~((~(~0 << n)) << (d - n)));

	if(s < d) {
		bit1 = bit1 << (d - s);
	}
	else {
		bit1 = bit1 >> (s - d);
	} 

	dnum = dnum | bit1;

	showbits(dnum);
	
return 0;
}
#endif
#if 0
int exp_4()
{
	int ch;

	printf (" 1. Even bit toggle\n");
	printf (" 2. odd bit toggle\n");

	printf ("enter your choice ");
	scanf ("%d", &ch);

	switch (ch) {

	case 1 :printf ("even toggle");
			even_bit_toggle(n);		
			break;
	case 2 :printf ("odd bit toggle");
			odd_bit_toggle(n);		
			break;
	}
return 0;
}
int	even_bit_toggle(int n)
{
	int i;

	for (i = ((sizeof(int) * 8) - 1); i > 0; i = i - 2) {
		n = (n ^ (1U << i));
	}
	showbits(n);
return 0;
}	
int	odd_bit_toggle(int n)	
{
	int i;

	for (i = 0; i <= ((sizeof(int) * 8) - 1); i = i + 2) {
		n = (n ^ (1U << i));
	}
	showbits(n);
return 0;
}
#endif
#if 0
int exp_5(int n, int pos)
{
	#define bit_ts (n, pos); n = (n | (1U << (pos - 1)));

	bit_ts(n,pos);

	showbits(n);

return 0;
}
#endif
#if 1
int exp_6(int n)
{
	int i = 0;
	int ch;
	
	printf (" \nMenu\n");
	printf (" 1. left rotate\n");
	printf (" 2. right rotate\n");
	printf (" 3. left rotate n bits\n");
	printf (" 4. right rotate n bits\n");

	printf ("enter your choice ");
	scanf ("%d", &ch);

	switch (ch) {

	case 1 :printf ("left rotate\n");
			left_rotate_bits(n);	
			break;
	case 2 :printf ("right rotate\n");
			right_rotate_bits(n);	
			break;
	case 3 :printf ("left rotate n bits\n");
			left_rotate_n_bits(n);	
			break;
	case 4 :printf ("right rotate n bits\n");
			right_rotate_n_bits(n);	
			break;
	}
return 0;
}

unsigned int left_rotate_bits (unsigned int n)
{
	int num;
	int i = 0;

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 
	printf ("Left rotation\n");
	while(num > i){
		n = ((n <<1) | (n & (1 << ((sizeof(int) * 8) - 1))));
		i++;
	showbits(n);
	}
return 0;
}

unsigned int right_rotate_bits (unsigned int n)
{
	int num;
	int i = 0;

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 
	printf ("Right rotation\n");
	while(num > i){
		n = ((n >> 1) | ((n & 1) << ((sizeof(int) * 8) - 1)));
		i++;
	showbits(n);
	}
	return 0;
}
unsigned int left_rotate_n_bits (unsigned int n)
{
	int num;
	int r;
	int key = 1;
	int r1;

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 

	printf ("\nenter no of bits to rotate");
	scanf ("%d", &r);

	for(; num != 0; num--) {
			r1 = r; 
		for ( ; r1 != 0; r1--) {
			n = ( n << key) | (n & (key << ((sizeof(int) * 8) - 1)));
		}
	showbits(n);
	} 
return 0;
}
unsigned int right_rotate_n_bits (unsigned int n)
{
	int num;
	int r;
	int r1;
	int key = 1;

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 

	printf ("\nenter no of bits to rotate");
	scanf ("%d", &r);

	for(; num != 0; num--) {
			r1 = r; 
		for ( ; r1 != 0; r1--) {
			n = ( n << key) | (n & (key << ((sizeof(int) * 8) - 1)));
		}
	showbits(n);
	} 


return 0;
}
#endif
#if 0
int exp_7()
{
	int ch;
	
	printf (" Menu\n");
	printf ("1.count set bits\n");
	printf ("2.count clear bits\n");

	printf ("enter your choice ");
	scanf ("%d", &ch);

	switch (ch) {

	case 1 :printf ("count set bits\n");
			count_bit_set(n);	
			break;
	case 2 :printf ("count clear bits\n");
			count_bit_clear(n);	
			break;
	}

return 0;
}
int count_bit_set(int n)
{
	int i;
	int c = 0;

	for (i = 0; i <= ((sizeof(int) * 8) - 1); i++) {
		if ( n & (1U << i)) {
			c++;
		}
		else {
			continue;
		}
	}
	printf ("Number of set bits in number %d\n", c);
return 0;
}
int count_bit_clear(int n)
{
	int i;
	int c = 0;

	for (i = 0; i <= ((sizeof(int) * 8) - 1); i++) {
		if ( n & (1U << i)) {
			continue;
		}
		else {
			c++;
		}
	}
	printf ("Number of clear bits in number %d\n", c);
return 0;
}
#endif
int exp_8()
{

return 0;
}
int exp_9()
{

return 0;
}
#if 0
int setbits(int x,int pos,int n,int y)
{

	int bit1;

	bit1 = (x & ((~ (~0 << n)) << (pos - n)));
	y = (y & ~((~(~0 << n)) << (pos - n)));

	y = y | bit1;

	showbits(y);

return 0;
}
#endif
int invert(int x,int pos,int n)
{
	int n1 = n;
	int bit1;
	int bit2 = 0;

	bit1 = (x & ((~ (~0 << n)) << (pos - n)));
	x = (x & ~((~(~0 << n)) << (pos - n)));

	for (;n1 != 0; n1--,pos++) {
		bit2 = (bit1 & (1U << (pos - n)));
				
		bit2 = bit2 | (bit2 << 1);
	showbits(bit2);
	}

//	showbits(bit2);

	x = x | bit2;
	showbits(x);
return 0;
}
int exp_12()
{

return 0;
}
