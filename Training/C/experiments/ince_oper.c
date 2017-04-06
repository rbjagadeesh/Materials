#include <stdio.h>
#if 0
int main ()
{

	int x =1;
	int y = 0;
	int z = 2;

	y++ && x++ || ++z;

	printf ("%d %d %d", x ,y ,z); 

	return 0;
}
#endif
#if 0
int main ()
{

	int x =10;
	int y = 8;
	int val1 = x & y;

	printf ("%d %d %d\n", x ,y ,val1); 

	return 0;
}
#endif
# if 0
int main ()
{
	int i ;
	char ch =127;

	for (i = 0; i < ch; i++){

		printf ("%d\n", ch); 
	}
	return 0;
}

#endif
# if 0
int main ()
{
	int i ;
	char ch[4] ={1,2,3,4};

	i = (ch[0] << 24 || ch[1] << 16 || ch[2] << 8 || ch[3]) ;
	printf ("%d\n", i); 

	return 0;
}
#endif
# if 1
//#define MAX
int main ()
{
	int i = 10;
	int j = 8;
	float k;
	
	k = i / j;

	printf ("%d\n", MAX); 

	return 0;
}
#endif
