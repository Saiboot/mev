#include "components/inc/cpu.h"
#include "inc/edbg.h"

#include <stdio.h>

// -- utilities
#include "inc/console.h"

#include "inc/system.h"

int main()
{
  console_init(gu_console);
  init_deps();

  init_emsg();    // wrap with console init



  free_emsg();

  flush_deps();
  return 0;
}