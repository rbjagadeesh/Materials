#include "errors.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX 512

int main(int argc, char *argv[])
{
	int sockfd;
	struct sockaddr_in my_addr;
	struct hostent *hent;
	unsigned int ip_addr;
	char *buf = NULL;
	int len = (sizeof(my_addr));

	if(-1 == (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))){
		errno_abort("socket creation failed\n");
		exit(EXIT_FAILURE);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(40000);

	if(NULL == (hent = gethostbyname(argv[1]))) {
		errno_abort("gethostbyname failed");
		exit(EXIT_FAILURE);
	}		

	printf ("str = %s\n", argv[1]);
//	(ip_addr = (my_addr.sin_addr.s_addr = **(hent -> h_addr_list)));

	while(*hent -> h_addr_list) {
		memecpy((char *)a,*hent->h_addr_list++,sizeof(a));
		printf ("ip %s\n", (char *)inet_ntoa(a));
	}	


	printf ("ip address of host is %u\n", ip_addr);
	
/*	if(-1 == connect(sockfd, (struct sockaddr *)&my_addr, len)){
		errno_abort("sending request for connection failed \n")
		exit(EXIT_FAILURE);
	}
*/
	if(NULL == ( buf = malloc(MAX) ) ){
		errno_abort("malloc failed");
		exit(EXIT_FAILURE);
	}		
	
	close(sockfd);
	return 0;
}
