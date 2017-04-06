#include<stdio.h>
//#include<stdio.h>

#if 0
int main(void)
{
	struct record {
		/*		int sd;
				unsigned char ch;

				int sd;
				char ch;
				int sd1;

				char ch;
				short sd;

				char ch;
				int sd;
				char ch1;

				char ch;
				char ch1;
				int sd;

				char ch;
				short sd1;
				int sd;

				char ch;

				short sd;
				int sd1;
				char ch;

				int sd;
				short sd1;
		 */
		short sd1;
		//		char ch;
	}rec;

	printf("size of structure : %d\n",sizeof(struct record));
	printf("size of char ch : %d\n",sizeof(rec.ch));
	//	printf("size of int sd  : %d\n",sizeof(rec.sd));
	//	printf("size of char ch1 : %d\n",sizeof(rec.ch1));
	printf("size of short sd1 : %d\n",sizeof(rec.sd1));
	printf("addr of ch  : %p\n",&rec.ch);//the ch is given 4 bytes of memory instead of 1byte due to structure padding
	//	printf("addr of sd : %p\n",&rec.sd);
	//	printf("addr of ch1 : %p\n",&rec.ch1);
	printf("addr of sd1 : %p\n",&rec.sd1);

	return 0;
}
#endif
#if 0
struct u_tag {
	unsigned int age : 7;
	unsigned int     : 6 ;  // it will just assign empty 6 bits nd these can't be assigned and used for padding                             
	unsigned int     : 0;  // it is used to leave the remaining bits uninitialised and move to next integer byte 
	unsigned int rn  : 10;                                                      
	//  unsigned int trg : 0;  // error: zero width for bit-field ‘trg’             
};                                                                              

/*void showbits(struct u_tag a)                                                   
  {                                                                               
  int i;                                                                      

  for(i = 31 ; i >= 0 ; i--){ //showbits is not applicable since  >> is applicable only for integers                                      
  printf("%d",(a>>i)&1);                                                  
  }                                                                           
  printf("\n");                                                               
  }                                                                               
 */                                                                                
int main (void)                                                                 
{                                                                               
	struct u_tag m1;                                                            
	printf("size of m1 : %d\n",sizeof(m1));                                     
	m1.age = 127;                                                                                                                   
	printf("m1.age = %d\n",m1.age);                                             
	return 0;                                                                   
}  
#endif
#if 0
int main (void)
{
	typedef struct anony {
		char a[5];
		int b;
	} anony;

	union {
		char a;
		int b;
	} arr[2] = {{65}, {'a'}};

	anony obj1 = {"hiijj", 10};

	printf("%c \t %c \n", arr[0].a, arr[1].b);
	printf ("%d\n", sizeof(arr[0]));
	printf ("obj1 = %s\t obj1.a = %d\n", obj1.a, obj1.b);
	return 0;	
}
#endif
#if 0
int main (void)
{
	typedef struct tag {
		int a;
		char b;
	} alias;

	alias r = {5, 'c'};
	struct tag r = {10, 'C'}; // if use both struct tag & alias simultaneously it gives redefnition error
	//	struct tag = {10, 'C'}; // expected identifier
	//	tag r = {5, 'c'};	 //gives an error unkown type name 'tag'
	printf("%d\t %c\n", r.a, r.b);
	return 0;
}
#endif
#if 0
int main (void)
{
	struct a {
		int a;
		char b;
	} ;

	struct a a;

	a.a = 5;
	a.b = 'e';
	printf("%d\t%c\n", a.a, a.b);
	printf ("sizeof = %d\n", sizeof(a));
	return 0;
}
#endif
#if 0
int main (void)
{
	struct {
		enum {error = 10,warning,fault};
	} erro;

	printf("%d\n", warning);
	return 0;
}
#endif
#if 0
void func (void);
/*struct test {
  int a;
  };
  struct test member;
 */
int main (void) 
{
	struct test {
		int a;
	};
	struct test member;
	int a;
	a = 10;
	printf("a (before) = %d\n", a);
	func();
	printf("a (after) = %d\n", a);
	return 0; 
}

void func (void)
{
	member.a = 20;
	printf("a in fun %d\n", member.a);
}
#endif
#if 0
typedef struct {
	int rno;
	char name[];
} student, pupil; // we can give 1 or names for the struct through struct
/*struct class {
  int rno;
  char name[];
  } student; // error: ‘student’ redeclared as different kind of symbol
// that means for different structures we can't have same variable
 */
int main (void)
{
	student a1;
	pupil b1;

	a1.rno = 10;
	b1.rno = a1.rno;
	//	student.rno = 15;
	//	student.rno = student.rno;

	printf("%d\n", b1.rno);
	return 0;	
}
#endif
#if 0
struct test {
	char a;
	char *p;
	short b;
	double d;
	enum sa{a, b, c} m2;
	struct test* c;
	//		struct test c;
} m1;

int main (void)
{
	/*	struct test {
	//		char a;
	char *p;
	short b;
	double d;
	enum sa{a, b, c} m2;
	struct test* c;
	//		struct test c;
	} m1;*/
	char *p1;
	m1.m2 = c;
	//	enum sa{a, b, c = 10, d, e} ;
	//	enum sa{} m2;
	printf("sizeof : %d\n", sizeof(m1));
	printf("sizeof : %d\n", (m1.m2));

	printf("sizeof : %d\n", sizeof(p1));
	return 0;
}
#endif
#if 0
struct my{
	int a[0];
}m;

int main (void)
{
	printf ("%d\n", sizeof(m));
}
#endif
#if 0
int main (void)
{
	struct str_name {
		int a;
//		register b;
	} a;

	register c;
//	a.b = 20;
	c  = 200;
	printf("%d\n", c);
	printf ("%d\n", sizeof(a));

	return 0;
}
#endif
#if 0
struct can {
//	double f;
	short a;
	short b;
	char ch;
};
int main (void)
{
	printf ("%d\n", sizeof(struct can));

	return 0;
}
#endif
#if 0
struct can {
//	double f;
	short a;
	short b;
	char ch;
}s;
int main (void)
{
	s.b = 0x1;
	printf ("s = %d\n", s);
	printf ("&s = %p\n", &s);

	return 0;
}
#endif
#if 0
struct can {
	#include <stdio.h>
	#define MAX 12
	double f;
	short a;
	short b;
	char ch;
}s;
int main (void)
{
	int p;

//	p = s;
	printf ("s = %d\n", sizeof(s)/ sizeof(p));
	printf ("&s = %p\n", &s);
//	printf ("s.max = %d\n", s.a);

	return 0;
}
#endif
#if 0
struct can {
	short a : 9;
	int b : 9;
	char ch;
	short c : 9;
	int d : 9;
	char chh;
}s;
int main (void)
{
	s.a = 123;

	printf ("s.a = %hd\n", s.a);
	printf ("%d\n", sizeof(s));

	return 0;
}
#endif
#if 0
struct site {
//	char name[10] = "GeeksQuiz";
    int no_of_pages = 200;
}ptr, ptr2;
int main()
{
	ptr2 == ptr; 
    return 0;
}
#endif
#if 0
struct A
{
        double d;
};
struct bitfields
{
        int i;
        int a:16;
        float j;
        int b:16;
        struct A k;
        unsigned int c:7;
};

int main()
{
    printf(" %d ",sizeof(struct bitfields));
	return 0;
}
#endif

#if 0
int main (void)
{

	int a[0];
	printf(" %d ",sizeof(a[0]));
    printf(" %d ",sizeof(a));

	return 0;
}
#endif
#if 0//problem
#pragma pack(push , 1)
struct tag
{
        short s:9;
        int j:9;
        char c;
        short t:9;
        short u:9;
        char d;
};
int main (void)
{

	printf(" %d ",sizeof(struct tag));
//	printf(" %d ",sizeof(a));

	return 0;
}
#endif
#if 0
struct st {
	int a:33;
    int b;
}obj;
int main()
{
        obj.a = 7;
        printf("%d  %d\n",obj.a,obj.b);
        printf("%d\n", sizeof(obj));
}
#endif
#if 0
struct st {
	int a;
    char b;
	int c;
}obj;
int main()
{
        obj.a = 7;
        printf("%d  b =%c\n", sizeof(obj),obj.b);
}
#endif
#if 0
struct exp{ 
	int a; 
	int b; 
	int c; 
}; 
int fun(struct exp *s1) 
{ 
	printf("%d",s1->a); 
	printf("%d",s1->b); 
	printf("%d",(*s1).c); 
} 
int main() 
{ 
	struct exp s1; 
	s1.a=10; 
	s1.b=20; 
	s1.c=30; 
	fun(&s1); 
	return 0;
}
#endif
#if 1
struct st {
	int a:1;
    int b:2;
	char c;
}obj;
int main()
{
//        obj.a = 7;
 //       printf("%d  %d\n",obj.a,obj.b);
        printf("%d\n", sizeof(obj));
}
#endif
