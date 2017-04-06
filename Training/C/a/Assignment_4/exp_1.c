#include <stdio.h>

int main(void)
{
#if 1
struct format {
	char VPI : 4;
	char GFC : 4;
	char VCI : 4;
	char VPI2 : 4;
	char VCI2;
	char CLP : 1;
	char PTI : 3;
	char VCI3 : 4;
	char HEC;
	}form;

	printf ("size of structure %d", sizeof(form));
	
	return 0;
}
#endif
#if 0
struct frame {
	short int checksum;
	short int urgent;
	int headerlenght : 4;
	int reserved : 6;
	int codebits : 6;
	short int window;
	int acknowledgment;
	int sequencenumber;
	short int sourceport;
	short int destnationport;
	}format;

	printf ("size of frame is %d\n", sizeof(format));

	return 0;

}
#endif

#if 0
struct fram {
	int options : 24;
	int padding : 8;
	int destination_ip_adrr;
	int source_ip_addr;
	int ttl : 8;
	int protocal : 8;
	int header_checksum : 16;
	int identification : 16;
	int flags : 8;
	int fragment_offset : 8;
	int version : 4;
	int header_lentgh : 4;
	int service_type : 8;
	int total_lentgh : 16;
	} form;

	printf ("size of structure %d", sizeof(form));
	return 0;
}
#endif
