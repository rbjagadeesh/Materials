#include <stdio.h>
#include <stdlib.h>

#if 0
int main(void)
{
	int a[2];
	int i;
	int b[2];

	printf("%p\n", &i);

	for(i = 0; i < 2; i++) {
		printf("a[%d] = %p\n",i, &a[i]);
		printf("b[%d] = %p\n",i, &b[i]);
	}

	return 0;
}
#endif

#if 0// Declaration without typedef

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p;

//	struct point p = {.y = 2, .x = 1} ;//Initialise at time of declaration only

//	struct point p = {1,2};//initialise at time of declaration only

	p . x = 1;
	p . y = 2;	

	printf("%d\t %d\n", p.x , p.y); 
	return 0;
}

#endif

#if 0//Declaration with typedef

/* Define a type point to be a struct with integer members x, y */
typedef struct {
   int    x;
   int    y;
} point;

int main(void) {

/* Define a variable p of type point, and initialize all its members inline! */
    point p = {1,3};

/* Define a variable q of type point. Members are uninitialized. */
    point q = p;

/* Assign the value of p to q, copies the member values from p into q. */
//    q = p;

/* Change the member x of q to have the value of 3 */
    q.x = 3;

/* Demonstrate we have a copy and that they are now different. */
    if (p.x != q.x) printf("The members are not equal! %d != %d\n", p.x, q.x);

/* Define a variable r of type point. Members are uninitialized. */
    point r;

/* Assign values using compound literal (ISO C99/supported by GCC > 2.95) */
  r = (point) {1,2};

	printf("%d\t%d\n", r.x, r.y);

    return 0;
}
#endif

#if 0 //Accessing structure members using pointers without DMA

typedef struct point
{
   int x;
   int y;
} point;

int main()
{
    point *ptr, point1;
    ptr = &point1;// Referencing pointer to memory address of point1

    printf("Enter integer: ");
    scanf("%d",&(*ptr).x);

    printf("Enter number: ");
    scanf("%d",&(*ptr).y);

    printf("Displaying: ");
    printf("%d \t %d\n",(*ptr).x,(*ptr).y);

    return 0;
}

#endif

#if 0 //Accessing structure members using pointers with DMA

typedef struct point
{
   int x;
   int y;
} point;

int main()
{
    point *ptr, point1;

	ptr = (struct point*)malloc(sizeof(struct point));

    printf("Enter integer: ");
    scanf("%d",&(*ptr).x);

    printf("Enter number: ");
    scanf("%d",&(*ptr).y);

    printf("Displaying: ");
    printf("%d \t %d\n",(*ptr).x,(*ptr).y);

    return 0;
}

#endif

#if 0//operations on structures

typedef struct point
{
   int x;
   int y;
} point;

int main()
{
    point point1, point2;

    printf("Enter integer: ");
    scanf("%d",&point1.x);

    printf("Enter number: ");
    scanf("%d",&point1.y);

	point2 = point1;

    printf("Displaying: ");
    printf("%d \t %d\n",point2.x,point2.y);

    return 0;
}

#endif

#if 1

struct node {
	int a;
	struct node1 {
		int b;
		int c;
	}d;
};

int main(void)
{
	printf("%d\n", sizeof(struct node));

	return 0;
}
#endif
