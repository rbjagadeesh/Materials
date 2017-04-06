#include "../header/errors.h"

#define filename "fifo"
#define MAX 100

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}

int main ( void )
{
	int fd;
	char *buf = "heee"; 

//	if(NULL == (buf = (char *) malloc(MAX))) 
//		failure("malloc failed");

	if (-1 == mkfifo(filename, 0666)) 		//creating fifo
		failure("mkfifo falied");

	if(-1 == (fd = open(filename, O_WRONLY)))		//opening fifo file
		failure("open failed");
		
	if(-1 == write(fd, buf, MAX))
		failure("write failed");

	printf ("successfully writted into fifo\n");

	close(fd);	
	exit(EXIT_SUCCESS);
}
