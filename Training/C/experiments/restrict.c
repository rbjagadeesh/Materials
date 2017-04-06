#include <stdio.h>

#if 1
/* compile normally and using O3 option see the difference */

void func (int * restrict ptra, int *restrict ptrb, int *restrict ptrc);

int main (void)
{
	int a = 10;
	int b = 20;

	func (&a, &b, &a);	// passing same address in 1st and 3rd arguments
	printf ("%d\n", a);
	printf ("%d\n", b);

	return 0;
}
void func (int *restrict ptra, int *restrict ptrb, int *restrict ptrc)
{
	 /* value pointed by *ptra loaded to R1 register and value pointed by 
		ptrc into register R2 */

	*ptra += *ptrc;
	/* the above instruction assembly code 
		R1  <- *ptra
		R2  <- *ptrc
		add R1 R2
		R1 -> *ptra
	*/
	/* eventhough ptra and ptrc pointing to same memory the above change is 
	not reflected when i use ptrc because of restrict keyword because compiler 
	thinks the object pointed by ptrc is not changed so it wont load object pointed
	by ptrc again into register*/

	*ptrb += *ptrc;
	/* assembly for above 
		load R1 <- *ptrb
		add R1 R2
		load *ptrb <- R1
	*/
}
#endif
