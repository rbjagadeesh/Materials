#include "errors.h"

#define filename "./fifo1"
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

	fgets(buf, MAX, stdin);	

	if (-1 == mkfifo(filename, 0666)) 
		failure("mkfifo falied");

	if(-1 == (fd = open(filename, O_WRONLY)))
		failure("open failed");
		
	if(-1 == write(fd, buf, MAX))
		failure("open failed");

	close(fd);	
	return 0;
}
