#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <linux/in.h>

#define MAX 512
#define FLAGS 0

int main ( void ) 
{
	int sockfd;
	char *buf;
	struct sockaddr_in server_addr;
//	struct sockaddr_in my_addr;
	socklen_t len = sizeof(struct sockaddr_in);		

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = 48000;

	if(NULL == (buf = malloc (MAX))) 
		fatal("malloc() failed");

	if(-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)))
		fatal("socket() failed");

	if(-1 == (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr_in)))) 
		fatal("bind() failed");

	if(-1 == (recvfrom(sockfd, (void *)buf, MAX, FLAGS,(struct sockaddr *) &server_addr, &len)))
		fatal("recvfrom() failed");

	printf ("%s\n", buf);

	close(sockfd);

	exit(EXIT_SUCCESS);
}
fatal(char *str)
{
	printf ("%s\n", str);	
	exit(EXIT_FAILURE);
}
