#include<stdio.h>
#if 0
int main(void)
{
	int a,b;
	printf("enter a,b");
	scanf("%d %d",&a,&b);
	printf("value of a+b %d\n",a+b);
	printf("value of a>b %d\n",a>b);
	printf("value of a&&b %d\n",a&&b);
	printf("value of a|b %d\n",a|b);
	printf("value of a=b %d\n",a=b);
	printf("value of size of a %d\n",sizeof(a));
	printf("value of a>b %d\n",a>b? a:b);
	return 0;
}
#endif
#if 0
int main(void)
{
	char a,b;
	printf("enter a,b");
	scanf("%c %c",&a,&b);
	printf("value of a+b %d\n",a+b);
	printf("value of a>b %d\n",a>b);
	printf("value of a&&b %d\n",a&&b);
	printf("value of a|b %d\n",a|b);
	printf("value of a=b %d\n",a=b);
	printf("value of size of a %d\n",sizeof(a));
	printf("value of a>b %d\n",a>b? a:b);
	return 0;
}
#endif
#if 0
int main(void)
{
	char a,b;
	printf("enter a,b");
	scanf("%c %c",&a,&b);
	printf("value of a+b %c\n",a+b);
	printf("value of a>b %c\n",a>b);
	printf("value of a&&b %c\n",a&&b);
	printf("value of a|b %c\n",a|b);
	printf("value of a=b %c\n",a=b);
	printf("value of size of a %d\n",sizeof(a));
	printf("value of a>b %c\n",a>b? a:b);
	return 0;
}
#endif
#if 1
int main(void)
{
	double a,b;
	printf("enter a,b");
	scanf("%lf %lf",&a,&b);
	printf("value of a+b %lf\n",a+b);
//	printf("value of a>b %lf\n",a>b);
//	printf("value of a&&b %lf\n",a&&b);
//	printf("value of a|b %lf\n",a|b);
	printf("value of a=b %lf\n",a=b);
	printf("value of a/=b %lf\n",a/=b);
	printf("value of size of a %d\n",sizeof(a));
	printf("value of a>b %lf\n",a>b? a:b);
	return 0;
}
#endif

