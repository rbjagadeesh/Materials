#include <stdio.h>
#include <stdarg.h>

void error(char *);

int main (void)
{
	char *fmt = "seg fault";
	error(fmt);

	return 0;
}
void error(char *str, ...)
{

	va_list args;

	va_start(args, str);

	fprintf (stderr, "error : ");
	vfprintf (stderr, str, args);
	fprintf (stderr, "\n ");
	va_end(args);
}
