#include "inc/system.h"

void fetch_hardware_info()
{
	//...
}

int init_deps()
{
	g_cpu = init_cpu(X32);
	print_emsg();

	g_mem = init_mem();
    print_emsg();
}

int flush_deps()
{
	free_mem(g_mem);
	free_cpu(g_cpu);
}