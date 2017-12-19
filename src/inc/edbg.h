#ifndef _ERR_DBG_H
#define _ERR_DBG_H

/*  TODO:
 *  - Component error handler
 *    -- Assert(0) --> Assert!   <assert.h>
 *    -- error string collector 
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define COMP_LEN 10

extern const char ET_CPU[];
extern const char ET_MEM[];

/*  ErrCL_t :: Error Collection:
 *  - comp: 
 *  - error: 
 */
typedef struct {
  char comp[COMP_LEN];
  char *error;
} ErrCL_t;


ErrCL_t *g_ErrCL;

/*  init_emsg:
 *  
 */
int init_emsg();

/*  cast_emsg:
 *  
 */
void cast_emsg(const char *comp_def, const char *msg);

/*  print_emsg:
 *  
 */
void print_emsg();

/*  free_emsg:
 *  
 */
void free_emsg();

#endif  //!_ERR_DBG_H