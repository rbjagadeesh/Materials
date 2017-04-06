#include <stdio.h>

#if 0
struct bit {

        int a : 3;
        int b : 2;

}t;

int main(void)
{
        t.a = 15;
        t.b = 16;

        if(t.a) {

        printf("%u\n", t.a);
        printf("%u\n", t.b);
        }
        return 0;
}
#endif

#if 1

#pragma pack(1)
struct bit {
	int b : 29;
	char a : 7;
	char c : 4;
	int d: 23;
};

int main(void)
{
	printf("%d", sizeof(struct bit));
	return 0;
}	

#endif
