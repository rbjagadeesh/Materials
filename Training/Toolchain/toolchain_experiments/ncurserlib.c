#include <stdio.h>
#include <curses.h>

void main( void )
{
	int i;

//	initscr();
	clear();

	for(i=0; i<LINES; i++){
//		move(i, i);
	
/*		if (i%2 == 1)
			standout();
		else
			standend();
*/
		addstr("Hello, world");
//		sleep(1);
//		refresh();
	}
	
	endwin();

}
