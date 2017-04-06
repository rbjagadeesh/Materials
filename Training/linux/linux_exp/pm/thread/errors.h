#ifndef __errors_h
#define __errors_h

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/* 
 * NOTE : the "do { " ... " } while (0); "braceting around the macros
 * allows the err_abort and errno_abort macros to be used as if they
 * were function calls. Even in contexts where a trailing ";" would 
 * generate a null statement. For example.
 *
 * 			if (status != 0);
 * 				err_abort (status, "messages");
 *			else
 *				return status;
 *
 * will not compile if err_abort is a macro ending with ")". Because
 * C doesnot expect a ";" to follow the "}" in the do ... while construct, err_abort and
 * errno_abort can be used as if they were a function calls.
 */

#define err_abort(code, text)  do {\
	fprintf (stderr, "%s at %s: %d : %s\n", \
		text, __FILE__, __LINE__, strerror (code)); \
	abort (); \
	} while (0);

#define errno_abort(text) do {\
	fprintf (stderr, "%s at %s:%d: %s\n", \
		text, __FILE__, __LINE__, strerror (errno));\
	abort ();\
	} while (0);

#endif

