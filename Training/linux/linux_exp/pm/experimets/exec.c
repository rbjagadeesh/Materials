#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if 1
int main (int argc, char *argv[])
{
	pid_t pid;
//	char *str;
	*argv[1] = "/home/Downloads/test";
	int num;
/*
	if (NULL == fgets (str, 100, stdin)) {
		perror ("fgets failed");
		exit(0);
	}*/
//	printf("jagadeesh@jagadeesh:~")

	pid = fork();

//	str[strlen(str)] = '\0';

//	while(1) {
//		printf ("path$");
		printf("jagadeesh@jagadeesh:~");

		if (pid) {
			wait();
		} else {
			if (-1 == (num = execvp(argv[0], argv[1]))){
//				continue;	
			}
		}
//	}
	return 0;
}
#endif

#if 0
int main (int argc, char *argv[])
{
	int num = 0;
	pid_t pid;
	
	if (-1 == (pid = fork())) {
		perror("fork failed and no child process created");
		exit(0);
	} 

	while(1) {
			
		printf("\njagadeesh@jagadeesh:~");
		getchar();
		if (pid > 0) {
			wait();
		} else if (pid == 0) {
			if (-1 == (num == execvp(argv[1], argv))) {
				perror("fork failed");
				exit(0);
			}
		continue;
		}
	}
	return 0;
}

#endif
