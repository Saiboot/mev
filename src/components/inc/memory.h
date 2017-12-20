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

/*  RAM_t:
 *  - ...
 */
typedef uint32_t RAM_t;

/*  HDD_t:
 *  - ...
 */
typedef uint32_t HDD_t;

/*  SSD_t:
 *  - ...
 */
typedef uint32_t SSD_t;


/*	mem_t:
 *	- RAM: -capacity: # RAM_CAP			       	<-----.
 *	- HDD: -size: # HDD_SIZE				           <--'--.
 *	- SSD: -size: # SSD_SZ 						            <--'--.
 *														                          |
 *	TODO: make amount of RAM, HDD & SSD types dynamic. -'
 */
typedef struct {
	RAM_t *ram[RAM_STICKS];
	HDD_t *hdd[HARD_DRIVES];
	SSD_t *ssd[SOLID_DRIVES];
} mem_t;

/*	init_mem:
 *	- RAM:
 *	- HDD:
 *	- SSD:
 */
mem_t *init_mem(uint32_t ram_sz, uint32_t hdd_sz, uint32_t ssd_sz);

/*	x86 paging structure:

	PTE: page table
	PDE: page directory
	PDTE: page-directory-table
	

*/



#endif //!_MEM_H