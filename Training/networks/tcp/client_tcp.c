#include "errors.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX 512

int main(void)
{
	int sockfd;
	struct sockaddr_in my_addr;
	char *buf = NULL;
	int len = (sizeof(my_addr));

	if(-1 == (sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))){
		errno_abort("socket creation failed\n");
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_port = htons(40000);
	
	if(-1 == connect(sockfd, (struct sockaddr *)&my_addr, len)){
		errno_abort("sending request for connection failed \n")
	}

	if(NULL == ( buf = malloc(MAX) ) ){
		errno_abort("malloc failed");
		exit(EXIT_FAILURE);
	}		

	while(1){
		printf ("Enter data that send to server ");
		if(NULL == (buf = fgets(buf, MAX, stdin))){
			errno_abort("fgets failed");
			exit(EXIT_FAILURE);                                  
		}  

		if(-1 == write(sockfd, buf, MAX)){                            
        	errno_abort("Sending data to client failed \n");
		}

		printf ("server :");	
		if(-1 == read(sockfd, buf, MAX)){                             
        	errno_abort("receiving the data from client failed \n");
		} 

		printf("%s \n", buf);

		printf ("Do u want to exit[y/n] ");
		if('y' == (getc(stdin))) 
			break;
	}

	free(buf);
	close(sockfd);

	return 0;
}
