#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <inttypes.h>

#include "components/inc/memory.h"
#include "components/inc/cpu.h"

/*	
 *	gs_   ... global system variable
 *	gsp_  ... global system pointer
 *	
 */

// system bus ??

/*  sys_info:
 *  collection of system information
 *  - Architecture
 *  - ...
 */
typedef struct {
  char arch[3];	// Architecture

// --- memory

  uint8_t ram_sticks;	// RAM
  uint32_t *ram_cap;	// - capacity

  uint8_t hdd_sticks;	// HDD
  uint32_t *hdd_sz;		// - size

  uint8_t ssd_sticks;	// SSD
  uint32_t *ssd_sz;		// - size
 
// --- cpu

  uint8_t cpu_cores;
  uint8_t cpu_threads;

//
// --- monitor --- incl ,-OPENGL
//

  //...
} sys_info;

/* Hardware */
cpu_t *gsp_cpu;		/* CPU */
mem_t *gsp_mem;		/* Memory */


sys_info g_system;


/*	init_deps:
 *	- 
 */
int init_deps();

/*	flush_deps:
 *	- 
 */
int flush_deps();

#endif //!_SYSTEM_H