#ifndef _CPU_H
#define _CPU_H

#include <stdlib.h>
#include <inttypes.h>

#include "../../inc/hardware.h"
#include "../../inc/edbg.h"

/*  Architectures/modes:
 *  - X16: real 
 *  - X32: protected
 *  - X64: long
 */
#define X16 1
#define X32 2
#define X64 3   // futuristic

/*  register16_t:
 *  - Least gpr -segments.
 *  - 2 x 8 bit register segments
 */
typedef struct {
  int8_t AL;
  int8_t AH;
} register16_t;

/*  register32_t:
 *  - 32 bit gpr register
 */
typedef union {
  int32_t ERX;
  int16_t RX;
  register16_t LH;
} register32_t;

/*  pregister_t:
 *  - 32 bit memory pointer
 *  - 16 bit memory pointer --- legacy real mode
 */
typedef union {
  uint32_t p32;
  uint16_t p16;
} pregister_t;

/*  pregister32_t:
 *  - 32 bit memory pointer
 */
typedef uint32_t pregister32_t;

/*  EFLAGS_t:
 *  - CF:  carry 
 *  - PF:  parity 
 *  - AF:  adjust
 *  - ZF:  zero 
 *  - SF:  sign 
 *  - TF:   trap
 *  - IF:    interrupt
 *  - DF:  direction
 *  - OF:  overflow
 *  - IOPL:  I/O privellige level 2      -- current process
 *  - NT:  nested task
 *  - RF:   resume
 *  - VM:  virtual-8086 mode
 *  - AC:   alignment check
 *  - VIF:  virtual interrupt
 *  - VIP:  virtual interrupt pending
 *  - ID:    identification
 */
typedef struct {
  uint32_t CF      : 1;
  uint32_t O       : 1; 
  uint32_t PF      : 1;  
  uint32_t Z1      : 1; 
  uint32_t AF      : 1;
  uint32_t Z2      : 1;
  uint32_t ZF      : 1;
  uint32_t SF      : 1;
  uint32_t TF      : 1;
  uint32_t IF      : 1;
  uint32_t DF      : 1;
  uint32_t OF      : 1;
  
    uint32_t IOPL    : 2;

  uint32_t NT      : 1;
  uint32_t Z3      : 1;
  uint32_t RF      : 1;
  uint32_t VM      : 1;
  uint32_t AC      : 1;
  uint32_t VIF     : 1;
  uint32_t VIP     : 1;
  uint32_t ID      : 1;
} EFLAGS_t;

/*  cpu_t:
 *  - A:
 *  - B:
 *  - C:
 *  - D:
 */
typedef struct {

// --- general purpose

  register32_t A; // accumulator
  register32_t B; // base
  register32_t C; // counter
  register32_t D; // data

  register32_t SP; // stack pointer
  register32_t BP; // base pointer

  register32_t SI; // source
  register32_t DI; // destination

// --- segment pointers  --- legacy real mode

  pregister32_t ss;  // stack
  pregister32_t cs;  // code
  pregister32_t ds;  // data (1)
  pregister32_t es;  // data (2)
  pregister32_t fs;   // data (3)
  pregister32_t gs;  // data (4)

// --- 

  pregister32_t IP; // instruction pointer

// --- Flags

  EFLAGS_t eflags; // x86 flags
} cpu_t;



/* global cpu */
cpu_t *g_cpu;

/*  init_cpu:
 *  
 */
int init_cpu(int mode);

/*  free_cpu:
 *  
 */
void free_cpu();


#endif  //!_CPU_H