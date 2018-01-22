#ifndef _CPU_H
#define _CPU_H

#include <stdlib.h>
#include <inttypes.h>

#include "../../inc/hardware.h"
#include "../../inc/system.h"
#include "../../inc/edbg.h"

#include "memory.h"

/*  Architectures/modes:
 *  - X00: error
 *  - X16: real 
 *  - X32: protected
 *  - X64: long
 */
#define X00 0
#define X16 1
#define X32 2
#define X64 3

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
  int32_t ERX;        //  [   <-- ERX -->      ]
  int16_t RX;         //  [ <-RX-> ][          ]
  register16_t LH;    //  [        ][ AL ][ AH ]
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
typedef MEMORY_t *pRegister32_t;   // TODO: FIX THIS!

/*  EFLAGS_t:
 *  CPU Flags - 32 bits (17 in use)
 *  Z1-Z4: not in use.
 *  FS - full status -- register holds every flag.
 */
typedef struct {
  uint32_t CF      : 1;     // --- carry
  uint32_t Z1      : 1;     // -reserved: 0
  uint32_t PF      : 1;     // --- parity
  uint32_t Z2      : 1;     // -reserved: -
  uint32_t AF      : 1;     // --- adjust
  uint32_t Z3      : 1;     // -reserved: -
  uint32_t ZF      : 1;     // --- zero
  uint32_t SF      : 1;     // --- sign
  uint32_t TF      : 1;     // --- trap
  uint32_t IF      : 1;     // --- interrupt
  uint32_t DF      : 1;     // --- direction
  uint32_t OF      : 1;     // --- overflow
                            
    uint32_t IOPL    : 2;   // --- I/O privellige level 2    -- current process
                            
  uint32_t NT      : 1;     // ---  nested task
  uint32_t Z4      : 1;     // -reserved: -
  uint32_t RF      : 1;     // --- resume
  uint32_t VM      : 1;     // --- virtual-8086 mode
  uint32_t AC      : 1;     // --- alignment check
  uint32_t VIF     : 1;     // --- virtual interrupt
  uint32_t VIP     : 1;     // --- virtual interrupt pending
  uint32_t ID      : 1;     // --- identification
} EFLAGS_t;

/*  EFLAGSREG_t
 *  - EFLAGS register wrapper
 *  - useage: toggle every flag off with AF/all flags
 */
typedef union {
  uint32_t AF;      // -- all flags
  EFLAGS_t fc;      // -- flag collection
} EFLAGSREG_t;

/*  status_t:
 *  cpu status
 */
typedef struct {

// --- flags

  const uint8_t flags = 21;   // -- amount of flags

// --- physic

  int8_t temperature;   // :: celsius

//...

} status_t;

/*  cpu_t:
 *  - ...
 */
typedef struct {

// --- general purpose

  register32_t A; // accumulator
  register32_t B; // base
  register32_t C; // counter
  register32_t D; // data

  pRegister32_t SP; // stack pointer
  pRegister32_t BP; // base pointer

  register32_t SI; // source
  register32_t DI; // destination

// --- segment pointers  --- legacy real mode

  pRegister32_t ss;  // stack
  pRegister32_t cs;  // code
  pRegister32_t ds;  // data (1)
  pRegister32_t es;  // data (2)
  pRegister32_t fs;  // data (3)
  pRegister32_t gs;  // data (4)

// --- 
  uint8_t mode;
  pRegister32_t IP; // instruction pointer

// --- flags

  EFLAGSREG_t eFlags;         // -- EFLAGS register

// --- cpu status

  status_t status;

} cpu_t;

//
//  TODO:
//  - CPU cores || threads
//  - ..
//
//

/*  init_cpu:
 *  
 */
int init_cpu(int mode);

/*  cpu_cycle:
 *  - 
 */
void cpu_cycle();

/*  free_cpu:
 *  
 */
void free_cpu();


#endif  //!_CPU_H