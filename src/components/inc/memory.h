#ifndef _MEM_H
#define _MEM_H

#include "../../inc/hardware.h"
#include <inttypes.h>

#include "../../utility/inc/edbg.h"
#include "../../utility/inc/fio.h"

//
//	TODO:
//	- x86 paging
//
//

/*  byte_t:
 *  - ...
 */
typedef uint8_t byte_t;

/*  x16mem_t:
 *  - ...
 */
typedef uint16_t x16mem_t;

/*  x32mem_t:
 *  - ...
 */
typedef uint32_t x32mem_t;

/*  x64mem_t:
 *  - ...
 */
typedef uint64_t x64mem_t;

typedef union {
  x16mem_t *x16;
  x32mem_t *x32;
  x64mem_t *x64;
} MEMORY_t;

/*	mem_t:
 *	- mRAM: :                    		      	<-----.
 *	- mHDD: :                  			           <--'--.
 *	- mSSD: :                					            <--'--.
 *														                          |
 *	                                                 . -'
 */
typedef struct {
	MEMORY_t mRAM;
	MEMORY_t mHDD;
	MEMORY_t mSSD;
} mem_t;

/*	init_mem:
 *	- RAM:
 *	- HDD:
 *	- SSD:
 */
mem_t *init_mem();

/*	x86 paging structure:

	PTE: page table
	PDE: page directory
	PDTE: page-directory-table
	

*/


// Instruction set

struct {
  


} instruct_t;


#endif //!_MEM_H