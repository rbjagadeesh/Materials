#include "errors.h"
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 512

int main( void )
{
	int sockd;
	int accept_sockd;
	struct sockaddr_in my_addr;
	struct sockaddr_in client_addr;
	void *buf;
	int len = (sizeof(client_addr));

	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = INADDR_ANY;
	my_addr.sin_port = htons(40000);

	if(-1 == (sockd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))){
		errno_abort("socket() failed");
	}

	if(-1 == bind(sockd, (struct sockaddr *)&my_addr, sizeof(my_addr))){
		errno_abort("bind() failed");
	}

	if(-1 == listen(sockd, 0)){
		errno_abort("listen() failed");
	}

	if(-1 == (accept_sockd = accept(sockd, (struct sockaddr *)&client_addr, &len) ) ){
		errno_abort("Connecton acceptance failed");
	}

	if(NULL == ( buf = malloc(MAX) ) ){
		errno_abort("malloc failed \n");
		exit(EXIT_FAILURE);
	}

	while(1){
		
		printf ("client :");
		if(-1 == read(accept_sockd, buf, MAX)){
			errno_abort("receiving the data from client failed \n");	
		}

		printf("%s \n", (char *)buf);

		printf("Enter the data to be send to client : ");

		if(NULL == (buf = fgets(buf, MAX, stdin))){
			perror("fgets failed");
			exit(EXIT_FAILURE);
		}

		if(-1 == write(accept_sockd, buf, MAX)){
			errno_abort("write failed");
		}

		printf ("Do u want to exit[y/n]");
		if('y' == (getc(stdin))) 
			break;
	}

	free(buf);
	close(accept_sockd);

	if(-1 == close(sockd)) {
		errno_abort("close() failed");
	} 

	return 0;
}
