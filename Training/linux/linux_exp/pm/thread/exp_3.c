#include "errors.h"

void failure(char *msg)
{
	errno_abort(msg);
	exit(EXIT_FAILURE);
}

int g_var = 20;                                                          
pthread_t pt;

void *thr (int *h_var)
{   
	g_var = 25;
	*h_var = 35;

	printf("In the thread1\n");
	printf("tid = %d\n", getpid());   
	printf("g_var = %d\n",g_var);
	printf("h_var = %d\n",*h_var);
	pthread_detach(pt);
}                                                     
int main (void)
{
    int status;            
	int l_var = 40;      
	int *h_var = malloc(sizeof(int));

	*h_var = 30;                                               

    if(-1 == (status  = pthread_create(&pt, NULL, (void *) &thr, h_var)))
		failure("pthread_create failed");

    printf("pid = %d\n", getpid());        
	printf("g_var = %d\n",g_var);  
	printf("h_var = %d\n",*h_var); 

	return 0;
}                                
