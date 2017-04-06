# include <stdio.h>

struct frame1
{
	char VP1 : 4;
	char GFC : 4;
	char VC1 : 4;
	char VP2 : 4;
	char VC2 : 8;
	char CLP : 1;
	char     : 1;
	char PT1 : 1;
	char     : 1;
	char VC3 : 4;
	char HEC : 8;
} f1;

struct frame2
{
	int sourceport            : 16;
	int destinationport       : 16;
	int sequencenumber            ;
	int acknowledgementnumber     ;
	int headerlength          :  4;
	int reserved              :  6;
	int codebits              :  6;
	int window                : 16; 
	int checksum              : 16;
	int urgent                : 16;
	int options;
	int data[];
} f2;

struct frame3
{
	int version        :  4;
	int headerlength   :  4;
	int servicetype    :  8;
	int totallength    : 16;
	int identification : 16;
	int flags          :  4;
	int fragmentoffset : 12;
	int ttl            :  8;
	int protocol       :  8;
	int headerchecksum : 16;
	int sourceipaddr       ;
	int destinationipaddr  ;
	int options        : 20;
	int                : 12;
} f3;

int main(void)
{
	printf("%d\n", sizeof(f1));
	printf("%d\n", sizeof(f2));
	printf("%d\n", sizeof(f3));
	return 0;
}

