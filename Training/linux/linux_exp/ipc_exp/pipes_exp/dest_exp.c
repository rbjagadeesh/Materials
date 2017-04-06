#include "../header/errors.h"

#define filename "fif"
#define MAX 100

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}

int main ( void )
{
	int fd;
	char *buf;

	if(NULL == (buf = (char *) malloc(MAX))) 
		failure("malloc failed");

	if(-1 == (fd = open(filename, O_RDONLY)))
		failure("open failed");

	if(-1 == read(fd, buf, MAX))
		failure("write failed");

	printf ("%s\n", buf);

	close(fd);
	unlink(filename);
	return 0;
}
