#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// basics of 1d array
#if 1
int main( void )
{
	int a[4] = { 2, 1, 3, 4 };

	int *p = a;// It's not pointer to array !!!
			   // It's just pointer to the first element of array !!!

	printf ("size %d\n", sizeof(a));

	int *q = (a + 0);

	printf(" %p   %p\n", q, p);

	q = (a + 1);

	printf(" %d \n", *q);

	q = (a + 2);

	printf(" %d \n", *q);

	return 0;
}
#endif

//dynamic array 
#if 0
int main( void )
{
	int *p = NULL, i, num, sum = 0;

	printf(" How many elements do you need to add ??\n ");
	
	scanf("%d ", &num);

	p = (int *) malloc ( num * sizeof (int));

	printf(" Enter the elements \n");

	for (i = 0; i < num; i++) 
		scanf("%d", (p + i));
	
	for ( i = 0; i < num ; i++) 
		printf(" %p contain %d\n ", (p + i), *(p + i));

	for ( i =0; i < num; i++) 
		sum = sum + *( p + i);

	printf(" sum is %d ", sum );

	free(p);

	return 0;
}
#endif 
// pointer to array

#if 0
int main( void )
{
	int j;
	int i;
	int a[3][3];
	int (*p)[3] = a; // pointer to an 1D array of 3 ints

	printf(" enter the elements \n ");

	for ( i = 0;  i < 3; i++) {
		for ( j = 0; j < 3; j++) {
			scanf(" %d", ( *(p + i) + j));
		}
	}

	for ( i = 0;  i < 3; i++) {
    	for ( j = 0; j < 3; j++) {
        	printf(" %d\t", *( *(p + i) + j));
        }
		printf(" \n"); 
	}

	return 0;
}
#endif
// difference between string literal and character array
#if 0
void fun (char s1[]);

int main( void )
{
	char s1[ ] = "CARE";
//	char *s2 = "CARE";

	s1[2] = 'g';

//	s2[2] = 'g';

	
	printf(" %d ", sizeof(s1));
	printf(" %d ", strlen(s1));
//	printf(" %s ", s2);

	fun(s1);
	printf(" %s ", s1);

	return 0;
}
void fun (char arr[])
{
	arr[1] = 'e';
}
#endif

#if 0
//void fun (int p[][]);
void fun (int (*p)[3]);

int main (void)
{
	int a[3][3] = {1,2,3,4,5,6};

	printf ("addr is %p\n", a);
	printf ("addr is %p\n", a + 1);
	printf ("addr is %p\n", &a + 1);
	printf ("addr is %p\n", *a + 1);

	fun(a);

	return 0;
}
void fun (int (*p)[3])
{
	int i;
	int j;

	for ( i = 0;  i < 3; i++) {
    	for ( j = 0; j < 3; j++) {
        	printf(" %d\t", *( *(p + i) + j));
        }
		printf(" \n"); 
	}
}
#endif
// understanding pointers and arrays
#if 0
int main( void )
{
	int arr[3][5] = { {1,2,3,4,5},
					  	{6,7,8,9,10},
							{11,12,13,14,15}};

	int **p = arr;

	printf(" *++p = %p \n ", *++p);
	printf(" *p++ = %p \n ", *p++);
	printf(" *(p+1) = %p \n", *(p + 1));

    printf(" &arr = %p \n ", &arr);
    printf(" arr = %p \n ", arr);
	printf(" *arr = %p \n ", *arr);
	
	printf(" &arr + 1 = %p\n ", &arr + 1);
	printf(" arr + 1 = %p\n ",  arr + 1);
	printf(" *arr + 1 = %p\n ", *arr + 1);
	
	printf(" **arr = %d \n ", **arr);
	printf(" *(*arr + 1) = %d\n ", *(*arr + 1));
	printf(" *(arr + 1) = %p\n ", *(arr + 1));
	printf(" *(*(arr + 1) = %d\n ", *(*(arr + 1)));
	printf(" **(arr + 1) = %d\n ", **(arr + 1));
	printf(" *(*(arr + 2) + 3) = %d\n", *(*(arr + 2 ) + 3));

	return 0;
}
#endif
