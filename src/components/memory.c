#include "inc/memory.h"

/*	TODO:
	- Read memory size & capacity from hardware.txt
	- ...
 */


mem_t *init_mem(uint32_t ram_sz, uint32_t hdd_sz, uint32_t ssd_sz)
{
	mem_t *mem = malloc(sizeof(mem_t));

	if(!mem)
		cast_emsg(ET_MEM, "Allocation: failed");
	else {
		int RAM_CP = geti(fkey("hardware.txt", "RAM CAPACITY"));
		int RAM_AM = geti(fkey("hardware.txt", "RAM STICKS"));

    mem->ram = malloc(sizeof(RAM_t *) * )

		int HDD_SZ = geti(fkey("hardware.txt", "HDD SIZE"));
		fkey("hardware.txt", "HDD DRIVES");



		fkey("hardware.txt", "SSD SIZE");
		fkey("hardware.txt", "SSD DRIVES");
	}

	return mem;
}