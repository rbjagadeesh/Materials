#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10

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

int exp_9(int);
int max_min();
int clearrightmost(int n);
int clearleftmost(int n);	
int setrightmost(int n);
int setleftmost(int n);	
int setbit(int n, int s, int d);
int clearbits(int n, int s, int d);
int togglebits(int n, int s, int d);

int setbits(int,int,int,int);
int invert(int,int,int);
int exp_12(int, int ,int);

int n;
int s;
int d;
int pos;
int x;
int snum;
int dnum;
int i;
int c;

int my_atoi()
{
	int y = 0;
	char buf[MAX];

	if(NULL == fgets(buf, MAX, stdin)) {
		perror("fgets failed");
		exit(1);
	}
	*(buf + strlen(buf) - 1) = '\0';

	for (i = 0; buf[i] != '\0'; i++) {
		if(buf[i] >= '0' && buf[i] <= '9') {
			y = ((10 * y) + (buf[i] - '0')); 
		} else {
			printf("Input is not valid");
			exit(1);
		}
	}
	return y;
}

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
	getchar();
	switch (choice) {

		case 1:
			printf (" bit swap\n");

			printf ("Enter Number");
			n = my_atoi();
			showbits(n);

			printf ("\n Enter source position ");
			s = my_atoi();

			printf ("\n Enter destination position ");
			d = my_atoi();

			bit_swap(n,s,d);

			break;
		case 2:

			printf (" bit swapin s and d\n");

			printf ("\n Enter source Number ");
			snum = my_atoi();
			showbits(snum);

			printf ("\n Enter destination Number ");
			dnum = my_atoi();
			showbits(dnum);

			printf ("\n Enter source position ");
			s = my_atoi();

			printf ("\n Enter destination position ");
			d = my_atoi();

			exp_2(snum,dnum,s,d);

			break;
		case 3:

			printf (" n bit swap in s and d\n");

			printf ("\n Enter source Number ");
			snum = my_atoi();
			showbits(snum);

			printf ("\n Enter destination Number ");
			dnum = my_atoi();
			showbits(dnum);

			printf ("\n Enter lentgh ");
			n = my_atoi();

			printf ("\n Enter source position ");
			s = my_atoi();

			printf ("\n Enter destination position ");
			d = my_atoi();

			bit_copy(snum,dnum,n,s,d);

			break;
		case 4:
			printf (" toggle bit\n");

			printf ("\n Enter Number ");
			n = my_atoi();
			showbits(n);

			exp_4();

			break;
		case 5:
			printf (" set bit macro\n");

			printf ("\n Enter Number ");
			n = my_atoi();
			showbits(n);

			printf ("\n Enter positoin ");
			pos = my_atoi();

			exp_5(n,pos);

			break;
		case 6:
			printf (" rotate funtion\n");

			printf ("\n Enter Number ");
			n = my_atoi();
			showbits(n);

			exp_6(n);

			break;
		case 7:
			printf ("count no of bit set and cleared\n");

			printf ("\n Enter Number ");
			n = my_atoi();
			showbits(n);

			exp_7();

			break;
		case 8:
			printf ("fuction for trailing and leading bits\n");

			printf ("\n Enter Number ");
			n = my_atoi();

			showbits(n);
			exp_8();

			break;
		case 9:
			printf (" functions of macros\n");

			printf ("\n Enter Number ");
			n = my_atoi();

			showbits(n);

			exp_9(n);

			break;
		case 10:
			printf (" setbits function\n");
			int y;

			printf ("\n Enter Number ");
			x = my_atoi();

			showbits(x);

			printf ("\n Enter destination Number ");
			y = my_atoi();

			showbits(y);

			printf ("\n Enter lentgh ");
			n = my_atoi();

			printf ("\n Enter position ");
			pos = my_atoi();

			setbits(x,pos,n,y);

			break;
		case 11:

			printf (" invert function\n");

			printf ("\n Enter Number ");
			x = my_atoi();
			showbits(x);

			printf ("\n Enter lentgh ");
			n = my_atoi();

			printf ("\n Enter position ");
			pos = my_atoi();

			invert(x,pos,n);

			break;
		case 12:
			printf (" getbit \n");

			printf ("\n Enter Number ");
			x = my_atoi();
			showbits(x);

			printf ("\n Enter lentgh ");
			n = my_atoi();

			printf ("\n Enter position ");
			pos = my_atoi();

			exp_12(x,pos,n);

			break;
	}
	return 0;
}

int bit_swap(int n, int s, int d)
{
	int bit1;
	int bit2;

	if ( s < d) {
		s = s + d;
		d = s - d;
		s = s - d;
	}

	bit1 = ( n & (1 << (s -1)));
	bit2 = ( n & (1 << (d -1)));

	n = ( n & (~(1U << (s -1))));
	n = ( n & (~(1U << (d -1))));

	n = (n | (bit1 >> (s - d)));
	n = (n | (bit2 << (s - d)));

	printf ("after swap \n");
	showbits(n);

	return 0;
}

int exp_2(int snum,int dnum, int s, int d)
{
	int bit1;
	int bit2;
	int key = 1;

	bit1 = (((snum & (key << (s -1))) >> (s - 1)) << (d - 1));
	bit2 = (((dnum & (key << (d -1))) >> (d - 1)) << (s - 1));

	snum = ((snum & ( ~(1U << (s - 1)))) | bit2);
	dnum = ((dnum & (~ (1U << (d - 1)))) | bit1);

	printf ("after swap \n");
	showbits(snum);
	showbits(dnum);

	return 0;
}

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

int exp_5(int n, int pos)
{
#define bit_ts (n, pos); n = (n | (1U << (pos - 1)));

	bit_ts(n,pos);

	showbits(n);

	return 0;
}

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
	int bit;

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 
	printf ("Left rotation\n");
	for(; num > i; i++){
		bit = ((n & (1 << ((sizeof(int) * 8) - 1))) >> ((sizeof(int) * 8) - 1));
		n = (bit | (n << 1) );
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

	for (; num > i; i++){
		n = ((n >> 1) | ((n & 1) << ((sizeof(int) * 8) - 1)));
		showbits(n);
	}
	return 0;
}
unsigned int left_rotate_n_bits (unsigned int n)
{
	int num;
	int r;
	int r1;
	int bit;

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 

	printf ("\nenter no of bits to rotate");
	scanf ("%d", &r);

	for(; num != 0; num--) {
		r1 = r; 
		for ( ; r1 != 0; r1--) {
			bit = ((n & (1 << ((sizeof(int) * 8) - 1))) >> (((sizeof(int) * 8) - 1)));
			n = (bit | (n << 1));
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

	printf ("enter no of times to rotate ");
	scanf ("%d", &num); 

	printf ("\nenter no of bits to rotate");
	scanf ("%d", &r);

	for(; num != 0; num--) {
		r1 = r; 
		for ( ; r1 != 0; r1--) {
			n = ((n >> 1) | ((n & 1) << ((sizeof(int) * 8) - 1)));
		}
		showbits(n);
	} 

	return 0;
}

int exp_7()
{
	int ch;

	printf (" Menu\n");
	printf ("1.count set bits\n");
	printf ("2.count clear bits\n");

	printf ("enter your choice ");
	scanf ("%d", &ch);

	switch (ch) {

		case 1 :count_bit_set(n);	
				break;
		case 2 :count_bit_clear(n);	
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

int exp_8()
{
	int ch;
	int num;

	printf (" \nMenu\n");
	printf (" 1.count leading set bits\n");
	printf (" 2.count leading cleared bits\n");
	printf (" 3.count trailing cleared bits\n");
	printf (" 4.count trailing set bits\n");

	printf ("enter choice ");
	scanf ("%d", &ch);

	switch (ch) {
		case 1 :
			cnt_leading_set_bits (num);
			break;
		case 2 :
			cnt_leading_cleared_bits (num);
			break;
		case 3 :
			cnt_trailing_cleared_bits (num);
			break;
		case 4 :
			cnt_trailing_set_bits (num);
			break;
	}
	return 0;
}
int cnt_leading_set_bits (int num)
{
	int m;
	for (i = 31; i >= 0; i--) {
		m = (num >> i) & 1;
		if (m == 1) {
			c++;
		}
		else {
			break;
		}
	}
	printf ("count is %d\n", c); 
	return 0;
}
int cnt_leading_cleared_bits (int num)
{
	int m;
	for (i = 31; i >= 0; i--) {
		m = (num >> i) & 1;
		if (m == 0) {
			c++;
		}
		else {
			break;
		}
	}
	printf ("count is %d\n", c);
	return 0;
}
int cnt_trailing_cleared_bits (int num)
{
	int m;

	for (i = 0; i <= 31; i++) {
		m = (num & (1 << i));
		if (m == 0) {
			c++;
		}
		else {
			break;
		}
	}
	printf ("count is %d\n", c);
	return 0;
}
int cnt_trailing_set_bits (int num)
{
	int m;

	for (i = 0; i <= 31; i++) {
		m = (num & (1 << i));
		if (m == 1) {
			c++;
			m = 0;
		}
		else {
			break;
		}
	}
	printf ("count is %d\n", c);
	return 0;
}

int exp_9(int n)
{
	int ch;

	printf (" \nMenu\n");
	printf (" 1. maximum and minimum\n");
	printf (" 2. clear right most bit\n");
	printf (" 3. clear left most bit\n");
	printf (" 4. set right most cleared bit\n");
	printf (" 5. set left most cleared bit\n");
	printf (" 6. set bits from s to d\n");
	printf (" 7. clear bits from s to d\n");
	printf (" 8. Toggle bits from s to d\n");

	printf ("enter your choice ");
	scanf ("%d", &ch);

	switch (ch) {

		case 1 :printf ("Max_Min\n");
				max_min();	
				break;
		case 2 :printf ("clear right most bit\n");
				clearrightmost(n);	
				break;
		case 3 :printf ("clear left most bit\n");
				clearleftmost(n);	
				break;
		case 4 :printf ("set right most bit\n");
				setrightmost(n);	
				break;
		case 5 :printf ("set left most bit\n");
				setleftmost(n);
				break;
		case 6 :printf ("set bits from s to d and clear rest\n");
				setbit(n,s,d);
				break;
		case 7 :printf ("clear bits from s to d and set rest\n");
				clearbits(n, s, d);
				break;
		case 8 :printf ("toggle bits from s to d\n");
				togglebits(n, s, d);
				break;
	}

	return 0;
}
int max_min()
{
#define  maxmin(a,b) for (i = 0; i <= 31; i++) { if((a >> i) & 1) l = i; if ((b >> i )  & 1) m = i;} 

	int a;
	int b;
	int i;
	int m = 0;
	int l = 0;
	printf ("enter a");
	scanf ("%d", &a);
	printf ("enter b");
	scanf ("%d", &b);
	maxmin(a,b);
	if (l > m)
		printf ("a is greater\n");
	else
		printf ("b is greater\n");
	return 0;
}
int clearrightmost(int n)	
{
#define clearright(n); n = n & (n - 1);

	clearright(n);
	showbits(n);
	return 0;
}
int clearleftmost(int n)	
{
#define clearleft(n); n = n & (0 << ((sizeof(int) * 8 ) - 1));

	clearleft(n);
	showbits(n);

	return 0;
}
int setrightmost(int n)	
{
#define setright(n); n = n | 1;

	setright(n);
	showbits(n);

	return 0;
}
int setleftmost(int n)	
{
#define setleft(n); n = n | (1 << ((sizeof(int) * 8) - 1));

	setleft(n);
	showbits(n);

	return 0;
}
int setbit(int n, int s, int d)
{
#define setbit(n,s,d); n = ((~ (~0 << size) << (s - size)));

	int size;

	printf ("\n Enter source position ");
	scanf ("%d", &s);

	printf ("\n Enter destination position ");
	scanf ("%d", &d);
	size = s - d + 1;

	setbit(n,s,d);
	showbits(n);

	return 0;
}
int clearbits(int n, int s, int d)
{
#define clearbit(n,s,d); n =  ((~(~ (~0 << size)) << (s - size)));

	int size = s - d + 1;
	printf ("\n Enter source position ");
	scanf ("%d", &s);

	printf ("\n Enter destination position ");
	scanf ("%d", &d);
	clearbit(n,s,d);
	showbits(n);

	return 0;
}
int togglebits(int n, int s, int d)
{
#define togglebit(n,s,d);  for (i = d; i > (s- d +1); i++)n = (n ^ (1U << i));

	int i;
	int size = s - d + 1;

	printf ("\n Enter source position ");
	scanf ("%d", &s);

	printf ("\n Enter destination position ");
	scanf ("%d", &d);

	togglebit(n,s,d);
	showbits(n);

	return 0;
}
int setbits(int x,int pos,int n,int y)
{

	y = ((y & ~((~(~0 << n)) << (pos - n))) | (x & ((~ (~0 << n)) << (pos - n))));

	showbits(y);

	return 0;
}
int invert(int x,int pos,int n)
{
	int i;
	int bit1;
	int bit2 = 0;
	int bit3;

	bit1 = ((x & ((~ (~0 << n)) << (pos - n))) >> (pos - n));
	x = (x & ~((~(~0 << n)) << (pos - n)));
	showbits(bit1);

	for (i = 0; i < n; i++) {
		bit1 = (bit1 ^ (1 << i));
	}
	showbits(bit1);

	x = x | (bit1 << (pos - n));
	showbits(x);
	return 0;
}

int exp_12(int x, int pos, int n)
{
#define getbits (x,pos,n); bit1 = (x & ((~ (~0 << n)) << (pos - 1)));

	int bit1;

	getbits(x,pos,n);

	showbits(bit1);
	return 0;
}
