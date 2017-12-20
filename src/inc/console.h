#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "utility/inc/edbg.h"

/*	console_t:
 *	- 
 */
typedef struct {
	ErrCL_t *eCL;
	//...
} con_util_t;

static con_util_t gu_console;	// global utility

inline void init_console_util(con_util_t co)
{
	co->eCL = init_emsg();
}

#endif //!_CONSOLE_H