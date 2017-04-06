#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

#if 0
int main ( void )
{

	while(1) {
		fprintf (stdout, "output");
		fprintf (stderr, "error ");

		sleep(1);
	}

	return 0;
}
#endif
#if 0
int main ( void )
{
	while(1) {
		printf ("%s", stdout);

		sleep(1);
	}

	return 0;
}
#endif
#if 0
int main ( void )
{
	int fd;
	int n = 3;
	FILE *fp = NULL;
	char *str;

	fd = open("file.txt", O_WRONLY); 

	dup2(fd, 1);

	while(n--) {
//		fprintf (stdout, "output ");
//		fprintf (stderr, "error ");
		fscanf (stdin, "%s", str);
		printf ("hello  ");
//		sleep(1);
	}

	return 0;
}
#endif
#if 1
int main( void )
{
	printf ("first");
	fprintf (stderr, "second");

	return 0;
}
#endif
