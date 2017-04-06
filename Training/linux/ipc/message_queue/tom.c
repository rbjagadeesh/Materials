#include "../header/errors.h"
#define filename "/mymq"

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}

int main ( void )
{
	mqd_t mqd;
	const char *msg_ptr = "hello RB";
	const char *msg_ptr1 = "h r u";
	char *buf;
	struct mq_attr attr;

	attr.mq_msgsize = 15;

	if(NULL == (buf = (char *) malloc(attr . mq_msgsize)))
        failure("malloc failed");

	if(-1 == (mqd = mq_open(filename, O_CREAT | O_RDWR, 0644, NULL)))
		failure("mq_open failed");

	if (-1 == mq_getattr(mqd, &attr))
		failure("mq_getattr failed");

	if(-1 == mq_send(mqd, msg_ptr, attr . mq_msgsize, 2)) 
		failure("mq_send failed");
			
	if(-1 == mq_send(mqd, msg_ptr1, attr . mq_msgsize, 2)) 
		failure("mq_send failed");

	getchar();

	if(-1 == mq_receive(mqd, buf, attr . mq_msgsize + 1, NULL)) 
		failure("mq_receive failed");

	printf ("%s\n", buf);
		
	exit(EXIT_SUCCESS);
}	
