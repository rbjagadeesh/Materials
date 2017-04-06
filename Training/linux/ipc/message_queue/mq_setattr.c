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

	if(-1 == (mqd = mq_open(filename, O_CREAT | O_RDWR, 0644, NULL)))
		failure("mq_open failed");

	attr . mq_flags = O_NONBLOCK;
	attr . mq_maxmsg = 15;
	attr . mq_msgsize = 100;

	if (-1 == mq_getattr(mqd, &attr))
		failure("mq_getattr failed");

	if(-1 == mq_send(mqd, msg_ptr, attr . mq_msgsize, 2)) 
		failure("mq_send failed");
			
	if(-1 == mq_send(mqd, msg_ptr1, attr . mq_msgsize, 2)) 
		failure("mq_send failed");

	printf ("no of msgs in queue is %ld\n", attr.mq_curmsgs);

	mq_unlink(filename);
	exit(EXIT_SUCCESS);
}	
