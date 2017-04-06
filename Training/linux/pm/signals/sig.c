#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include "../thread/errors.h"

#if 0
int main (void )
{

	pid_t pid;

	pid = fork();

	if (pid > 0) {
		printf ("I am in parent\n");
	} else if (pid == 0) {
		printf ("I am in parent\n");
	}
	
	kill(pid, sigusr1);

	return 0;
}
#endif

#if 0
void fun();

int main ( void )
{
	pid_t pid;

	if ((pid = fork()) == -1) {
		errno_abort("fork failed\n");
		exit(0);
	}

	if (pid == 0){
		printf ("i am in parent\n");
	} else if (pid > 0) {
		if(signal(SIGUSR1, fun) == SIG_ERR){
			errno_abort("sigaction failed\n");
			exit(0);
		}
		if(kill(getpid(), SIGUSR1) == -1){
			errno_abort("sigaction failed\n");
			exit(0);
		}
	}
	
	return 0;
}
void fun()
{
	printf ("signal woke me up\n");
	
}
#endif
#if 0
void sigfun1();
void sigfun2();

int main( void )
{ 
	pid_t pid;
  
	if ((pid = fork()) == -1) {
		errno_abort("fork failed\n");
		exit(0);
	}
	    
	if (pid == 0) { 
		printf ("hii\n");
//		signal(SIGUSR1,sigfun1);
//		signal(SIGUSR2,sigfun2);
		printf("\nPARENT: sending SIGUSR1\n\n");
		kill(pid,SIGUSR1);
//		sleep(3);
		printf("\nPARENT: sending SIUSR2\n\n");
		kill(pid,SIGUSR2);

	}else {  
		signal(SIGUSR1,sigfun1);
		signal(SIGUSR2,sigfun2);
		printf ("hello\n");
		wait(NULL);
	}
	return 0;
}

void sigfun1()
{
	printf("CHILD: I have received a SIGUSR1\n");
}

void sigfun2()
{ 

	printf("CHILD: I have received a SIGUSR2\n");
}
#endif
