# include <stdio.h>

struct node {
	char a;
	char c;
	char b;
	short d;
};

struct link {
	char a;
	short i;
};

struct pan {
	char ch;
	int a;
	char p;
};

struct can {
	char m;
	char c;
	int n;
};

struct mms {
	char ch;
	short s;
	int n;
};

struct nm {
	char c;
};

struct art {
	short s;
	short n;
	char ch;
};

struct quier {
	short s;
	short n;
	int m;
};
struct covet {
	short s;
	int n;                       
	short m;
};

struct {
	char c;
	short s;
}a;

struct {
	char c;
	short s;
}z;
struct {
	char c;
	char d;
	int :0;
	char :0;
	short :9;
	char e;
	long :0;
}b;

struct test
{
   unsigned int x;
   unsigned long long int y;
   unsigned int z;
}t ;

#if 1

int main(void)
{
/*	t.x =10;
	unsigned int *ptr1 = &t.x;
	unsigned int *ptr2 = &t.z;
	unsigned int *ptr3 = &t.y;

	printf("t.x%d\n", t.x);
	printf("t.y%ld\n", t.y);
	printf("t.z%d\n", t.z);
	printf("x %p\n", ptr1);
	printf("y %p\n", ptr3);
	printf("z %p\n", ptr2);
	printf("%d\n", (ptr2 - ptr1));

*/	printf("1 %d\n", sizeof(struct node));
	printf("2 %d\n", sizeof(struct link));
	printf("3 %d\n", sizeof(struct pan));
	printf("4 %d\n", sizeof(struct can));
	printf("5 %d\n", sizeof(struct mms));
	printf("6 %d\n", sizeof(struct nm));
	printf("7 %d\n", sizeof(struct art));
	printf("8 %d\n", sizeof(struct quier));
	printf("9 %d\n", sizeof(struct covet));
	printf("unnamed %d\n", sizeof(b));
	printf("union %d\n", sizeof(a));
	printf("union %d\n", sizeof(z));
	printf("%d\n", sizeof(t));
	return 0;
}

# endif

# if 0

int main(void)
{
	struct emp {
		int emp;
		int emp2;
		struct emp2 {
			int emp3;	
		}emp2;
	} emp;
	
	emp.emp2.emp3 = 15;
	emp.emp1 = 10;
	printf("%d	%d",emp.emp1, emp.emp2.emp3);
	return 0;
}

# endif

# if 0

#include <string.h>
 
struct student 
{
     int id;
     char name[30];
     float percentage;
};
 
int main() 
{
     int i;
     struct student record[2];
 
     // 1st student's record
     record[0].id=1;
     strcpy(record[0].name, "Asish");
     record[0].percentage = 80;
 
     // 2nd student's record         
     record[1].id=2;
     strcpy(record[1].name, "Gopal");
     record[1].percentage = 90;
 
     // 3rd student's record
     record[2].id=3;
     strcpy(record[2].name, "Eeshwar");
     record[2].percentage = 85;
      // 4th student's record
     record[3].id=4;
     strcpy(record[3].name, "Somesh");
     record[3].percentage = 95;
  
     for(i = 0; i < 4; i++)
     {
         printf("     Records of STUDENT : %d \n", i+1);
         printf(" Id is: %d \n", record[i].id);
         printf(" Name is: %s \n", record[i].name);
         printf(" Percentage is: %f\n\n",record[i].percentage);
		 printf(" address is %p \n", &record[i]);
     }
     return 0;
}

# endif

# if 0
struct {
	double a;
	int c;
//	char c;
	char d;
    int b;
} AoS[5];

struct {
	double a[5];
	int c[5];
	char d[5];
	int b[5];
} SoA;

int main(void)
{
	int i;

	for(i = 0; i < 5; i++) {
		printf("%p\n", &AoS[i].a);
		printf("%p\n", &AoS[i].c);
		printf("%p\n", &AoS[i].d);
		printf("%p\n", &AoS[i].b);

	}

	printf("\n");	

	for(i = 0 ; i < 5; i++) {
		printf("%p\n", &SoA.a[i]);
		printf("%p\n", &SoA.c[i]);
		printf("%p\n", &SoA.d[i]);
		printf("%p\n", &SoA.b[i]);
	}
	
	printf("%d\n", sizeof(AoS));
	printf("%d\n", sizeof(SoA));

	return 0;
}
# endif
