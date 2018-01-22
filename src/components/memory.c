#include "inc/memory.h"

/*	TODO:
	- Read memory size & capacity from hardware.txt
	- ...
 */


mem_t *init_mem()
{
	mem_t *mem = malloc(sizeof(mem_t));

	if(!mem)
		cast_emsg(ET_MEM, "Allocation: failed");
	else 
  {
    mem->mRAM = malloc(sizeof(byte_t) * g_system.mRAM.slots * g_system.mRAM.size);
    mem->mHDD = malloc(sizeof(byte_t) * g_system.mHDD.slots * g_system.mRAM.size);
    mem->mSSD = malloc(sizeof(byte_t) * g_system.mSSD.slots * g_system.mSSD.size);
	}

	return mem;
}