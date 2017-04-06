#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
	int fd;
	int fd1;
	int fd2;
	char *buf;
	char *buf1;
	char *buf2;

	if(-1 == (fd = open("session.txt", O_RDWR))) {
		perror("session hasn't created");
		exit(EXIT_FAILURE);
	}
	if(-1 == (fd1 = open("session.txt", O_WRONLY))) {
		perror("session hasn't created");
		exit(EXIT_FAILURE);
	}

	fd2 = open("session.txt", O_RDONLY);

	printf ("fd = %d\n", fd);
	printf ("fd1 = %d\n", fd1);
	printf ("fd2 = %d\n", fd2);

	buf = malloc(100);
	buf1 = malloc(100);
	buf2 = malloc(100);

	buf = "hii hello";
	buf1 = "this is RB";

	write(fd, buf, 100);
	write(fd1, buf1, 100);

	getchar();
	
	read(fd2, buf2, 100);

	printf("%s\n", buf2);

	return 0;
}
