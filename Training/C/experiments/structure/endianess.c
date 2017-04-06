#include <stdio.h>

typedef union {

         unsigned int value;

         struct {
                 unsigned char one   : 8;
                 unsigned char two   : 8;
                 unsigned char three : 8;
                 unsigned char four  : 8;
         }bitfield;
}uni;

int main() 
{
//         data_t var = {0x12345678};

	uni var;

	var.bitfield.one = 0x1;
	var.bitfield.two = 0x2;
	var.bitfield.three = 0x3;
	var.bitfield.four = 0x4;

	unsigned char *ptr = (unsigned char *)(&var);

         printf("The entire hex value is 0x%X\n", var.value);
         printf("The first byte is 0x%X \t%p\n", *(ptr + 0), ptr + 0);
         printf("The second byte is 0x%X \t%p\n", *(ptr + 1), ptr + 1);
         printf("The third byte is 0x%X \t%p \n", *(ptr + 2), ptr + 2);
         printf("The fourth byte is 0x%X \t%p\n", *(ptr + 3), ptr + 3);

         return 0;
}
