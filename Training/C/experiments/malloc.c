#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
int main (void)
{
	int *ptr = NULL;

	ptr = malloc(10);

	ptr[0] = 1;
	ptr[1] = 2;
	ptr[2] = 3000000;
	ptr[3] = 200;

	printf ("%d\n", sizeof(ptr));
	printf ("%d\t%d\t%d\t%d\n", ptr[0],ptr[1],ptr[2],ptr[3]);

	free(ptr);
	return 0;
}
#endif
#if 0
char *cstr = "UBIQUITOUS";
char *str;
char *dstr;

int main(void)
{
	char *cstr1 = "UBIQUITOUS";

	str = (char *) malloc (10);
	printf ("0x%08x \n", str);
	str = "Gamut";
	printf ("0x%08x \n", str);

	printf ("0x%08x \n", cstr1);
	printf ("0x%08x \n", cstr);

	// printf("%c \n", cstr);

	dstr = (char *)malloc (20);
	printf ("0x%08x \n", dstr);
	strcpy (dstr, "OBLATION");
	printf ("0x%08x \n", dstr);

	free (str);
	free (dstr);

	return 0;
}
#endif
#if 0
int main (void)
{
	int *ptr = NULL;

	ptr = calloc(5, 10);

	ptr[0] = 1;
	ptr[1] = 2;
	ptr[2] = 3000000;
	ptr[3] = 200;

	printf ("%d\n", sizeof(ptr));
	printf ("%d\t%d\t%d\t%d\n", ptr[0],ptr[1],ptr[2],ptr[49]);

	free(ptr);
//	free(ptr);
	return 0;
}
#endif
#if 0
int main (void)
{
	int *ptr = NULL;

	ptr = malloc(10);

	ptr[0] = 1;
	ptr[1] = 2;
	ptr[2] = 3000000;
	ptr[3] = 200;

	ptr = realloc(ptr, 0);
	free(ptr);
	printf ("%d\t%d\t%d\t%d\n", ptr[0],ptr[1],ptr[2],ptr[3]);

//	free(ptr);
	return 0;
}
#endif


//checking malloc implementation

#if 0
int main (void)
{
	int *ptr = NULL;

	ptr = malloc(0);
	*ptr = 12;
	*ptr = 13;
	*ptr = 14;
//	printf ("ptr = %d\n", *(--ptr));
//	printf ("ptr = %d\n", *(--ptr));
//	printf ("ptr = %d\n", *((++ptr)));
	printf ("add = %p\n", ptr);
	printf ("ptr = %d\n", *(++ptr));
	printf ("ptr = %d\n", *((++ptr)));
	printf ("ptr = %d\n", *((++ptr)));
	printf ("ptr = %d\n", *((++ptr)));
	
	ptr = malloc(10);
	printf ("add = %p\n", ptr);
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(++ptr));

	ptr = malloc(10);
	printf ("add = %p\n", ptr);
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("size of ptr is %d\n", sizeof(*ptr));

	return 0;
}
#endif
#if 1
int main (void)
{
	int *ptr = NULL;
	int *ptr1 = NULL;

	ptr = malloc(16);
	*ptr = 12;
	*++ptr = 13;
	*++ptr = 14;
//	printf ("ptr = %d\n", *(--ptr));
//	printf ("ptr = %d\n", *(--ptr));
//	printf ("ptr = %d\n", *((++ptr)));
	ptr = ptr -3;

	printf ("add = %p\n", ptr);
	printf ("ptr = %d\n", *(++ptr));
	printf ("ptr = %d\n", *((++ptr)));
	printf ("ptr = %d\n", *((++ptr)));
	printf ("ptr = %d\n", *((++ptr)));
	printf ("ptr = %d\n", *(++ptr));
	printf ("ptr = %d\n", *(++ptr));
	
	ptr = (ptr1 = malloc(10));
	printf ("add = %p\n", ptr1);
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));
	printf ("ptr = %d\n", *(--ptr));

	printf ("add = %p\n", ptr1);
	printf ("ptr1 = %d\n", *(++ptr1));
	printf ("ptr1 = %d\n", *((++ptr1)));
	printf ("ptr1 = %d\n", *((++ptr1)));
	printf ("ptr1 = %d\n", *((++ptr1)));
	printf ("ptr1 = %d\n", *(++ptr1));

//	free(ptr);
	ptr1 = ptr1 - 5;
	free(ptr1);
//	free(ptr);
	return 0;
}
#endif
