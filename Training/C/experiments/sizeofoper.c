#include <stdio.h>
#if 0
int main(void)
{
	printf("size of unsigned int %d\n",sizeof(int));	
	printf("size of unsigned float %d\n",sizeof(float));
	printf("size of unsigned double %d\n",sizeof(double));
	printf("size of unsigned char %d\n",sizeof(char));
	printf("size of signed int %d\n",sizeof(signed int));
//	printf("size of signed float %d\n",sizeof(signed float));
	//	printf("size of signed double %d\n",sizeof(signed double));
	printf("size of signed char %d\n",sizeof(signed char));
	printf("size of short int %d\n",sizeof(short int));
	//	printf("size of short float %d\n",sizeof(short float));
	//	printf("size of short double %d\n",sizeof(short double));
	//	printf("size of short char %d\n",sizeof(short char));
	printf("size of long int %d\n",sizeof(long int));
//	printf("size of long float %d\n",sizeof(long float));
	printf("size of long double %d\n",sizeof(long double));
	printf("size of long long int %d\n",sizeof(long long int));
	//	printf("size of long char %d\n",sizeof(long char));

	return 0;
}
#endif

#if 1
#define CHAR char *
typedef char * CH;

int main (void)
{
	char *a,b;
	CHAR c,d;
	CH e,f;
	int g = sizeof(a,b,c,d,e,f);

	printf ("g = %d\n", g);

	return 0;
}
#endif
