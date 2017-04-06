#include <stdio.h>

volatile int a = 10;

void func( int );

int main( void )
{

	func( a );

	return;
}


void func( int a )
{
	while ( 1 ){

	if( a % 2) {
		printf(" hi\n ");

	 }

	}
	return;
}
