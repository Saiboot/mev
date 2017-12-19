#include "components/inc/cpu.h"
#include "inc/edbg.h"

#include <stdio.h>


int main(int argc, char const **argv)
{

  init_emsg();    // wrap with console header

  if(!init_cpu(1))
    print_emsg();

  free_cpu();
  free_emsg();


  return 0;
}