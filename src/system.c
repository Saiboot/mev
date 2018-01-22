#include "inc/system.h"

void load_memory_info(char *type, memory_t *memory)
{
    char type_str[strlen(type)];
    for (int i = 0; type[i]; i++)
        type_str[i] = toupper(type[i]);

    char *slots_str = strcat(type_str, "_SLOTS");
    char *size_str strcat(type_str, "_SIZE");

    memory.slots = atoi(fio_find_key(HARDWARE_PATH, slots_str));

    memory.size = malloc(sizeof(uint32_t) * memory.slots);
    uint32_t rsz = atoi(fio_find_key(HARDWARE_PATH, size_str));
    for (int i = 0; i < memory.slots; i++)
        memory.size[i] = rsz;
}

void load_hardware_info()
{
    g_system->arch = fio_find_key(HARDWARE_PATH, "Architecture");
    switch(g_system->arch) {
        case "16":
            g_system.archID = X16;
            break;
        case "32" || "86":
            g_system.archID = X32;
            break;
        case "64":
            g_system.archID = X64;
            break;
        default:
            g_system.archID = X00;
            break;
    }

    // Memory
    load_memory_info("RAM", &g_system.mRAM);
    load_memory_info("HDD", &g_system.mHDD);
    load_memory_info("SSD", &g_system.mSSD);

}

int init_deps()
{

    load_hardware_info();

	g_cpu = init_cpu(g_system.archID);  //<--- FIX!
	print_emsg();

	g_mem = init_mem();
    print_emsg();

    g_cpu.IP = &g_mem->mRAM;    // set cpu - instruction pointer to first instruction loaded into RAM

}

int flush_deps()
{
	free_mem(g_mem);
	free_cpu(g_cpu);
}