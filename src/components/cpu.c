#include "inc/cpu.h"

#include <stdio.h>

int init_cpu(int mode)
{
  if(g_cpu) {
    cast_emsg(ET_CPU, "Allocation: duplicate");
    return 0;
  }

  g_cpu = malloc(sizeof(cpu_t));

  if(!g_cpu) {
    cast_emsg(ET_CPU, "Allocation: failed");
    return 0;
  }

  return 1;

}

void resrc_alloc(int mode)
{
  switch(mode) {
    case X16:
          // ..
      break;
    case X32:

          g_cpu->BP.ERX = RAM_SIZE * RAM_STICKS;
          g_cpu->SP.ERX = g_cpu->BP.ERX;

      break;
    default:
      break;
  }
}

void free_cpu()
{

//...

  free(g_cpu);
}