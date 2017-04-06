#include <unistd.h>
extern void myprintf(unsigned int num);
#define NIBBLE 4
                                                                                
void myprintf(unsigned int num)                                                 
{                                                            
                                                                            
	unsigned int r = 0; 
	char *line="\n";
	while( num ) { 
		r = (r << NIBBLE) + (num & 0x000f);                                                  num = num >> 4;
	}
	while(r) {
		num = r & 0x000f;                                                               num = num + '0';                                                                r = r >> NIBBLE;                                                                num = write(1, &num, 2); 
	}
	write(1,line,1);
	return;                                                                   
}                                                                               
                     
