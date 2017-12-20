#include "inc/cpu.h"

#include <stdio.h>

cpu_t *init_cpu(int mode)
{
  cpu_t *cpu = malloc(sizeof(cpu_t));
  cpu.mode = mode;

  if(!cpu) {
    cast_emsg(ET_CPU, "Allocation: failed");
    return 0;
  }


  allocresrc(cpu);
  ///.-...

  return cpu;
}

void allocresrc(cpu_t *cpu)
{
  switch(cpu.mode) {
    case X16:
      strcpy(g_system->arch, "x16");

      /* segments */
      cpu->ss = malloc(sizeof(pregister32_t));
      cpu->cs = malloc(sizeof(pregister32_t));
      cpu->ds = malloc(sizeof(pregister32_t));
      cpu->es = malloc(sizeof(pregister32_t));
      cpu->fs = malloc(sizeof(pregister32_t));
      cpu->gs = malloc(sizeof(pregister32_t));

      break;
    case X32:
      strcpy(g_system->arch, "x86");

      /* stack prep */
      cpu.BP.ERX = RAM_SIZE * RAM_STICKS;
      cpu.SP.ERX = cpu.BP.ERX;

      break;
    default:
      break;
  }
}

/*  next_instruction:
 *  - get next instruction
 */
pregister32_t next_instruction()
{
  g_cpu.status.eFlags.EF = 0;  // flush eflags
  g_cpu.IP++;
  return g_cpu.IP;
}

/*  fetch_instruction:
 *  - 
 */
instruct_t fetch_i(RAM_t *ram)
{
  *(ram + next_instruction());


}

/*  dec_i:
 *  - 
 */
void dec_i(instruct_info_t info)
{
  //...
}

/*  exec_i:
 *  - 
 */
void exec_i(instruct_t instruction)
{
  //...
}

void cpu_cycle()
{
  instruct_info_t info    = fetch_i(instruct_addr);
  instruct_t instruction  = dec_i(info);

  exec_i(instruction);
}

void free_cpu()
{

//...

  free(g_cpu);
}