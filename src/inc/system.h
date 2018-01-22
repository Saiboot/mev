#ifndef _SYSTEM_H
#define _SYSTEM_H

#include <inttypes.h>

#include "components/inc/memory.h"
#include "components/inc/cpu.h"
#include "utility/inc/system.h"

#define HARDWARE_PATH "hardware.txt"

/*	
 *	gs_   ... global system variable
 *	gsp_  ... global system pointer
 *	
 */

// system bus ??

/*  memory_t:
 *  - RAM, HDD & SSD
 */
typedef struct {
    uint8_t slots;  // slots * size
    uint32_t *size;  // => Total memory
} memory_t;

/*  sys_info:
 *  collection of system information
 *  - Architecture
 *  - ...
 */
typedef struct {
  char arch[2];	// Architecture
  uint8_t archID;
  
// --- memory

  memory_t mRAM;
  memory_t mHDD;
  memory_t mSSD;
 
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