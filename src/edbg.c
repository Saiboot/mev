#include "inc/edbg.h"

#define ET 2

const char ET_CPU[] = "[CPU]";
const char ET_MEM[] = "[Memory]";

const char *E_TYPES[ET] = {
        ET_CPU,
        ET_MEM
};


int init_emsg()
{
  if(!g_ErrCL) {
    g_ErrCL = malloc(sizeof(ErrCL_t));
    g_ErrCL->error = malloc(sizeof(char));

    return 1;
  }
  return 0;
}

void cast_emsg(const char *comp_def, const char *msg)
{
  
  /* reallocate error string to reduce error collection size */
   g_ErrCL->error = realloc(g_ErrCL->error, sizeof(char) * strlen(msg));

  /* flush error collection */
  memset(g_ErrCL->error, 0, strlen(comp_def));
  memset(g_ErrCL->comp, 0, COMP_LEN);

  /* insert new error */
  strcpy(g_ErrCL->comp, comp_def);
  strcpy(g_ErrCL->error, msg);

}

int got_error()
{
  for (int i = 0; i < ET; ++i)
    if(!strcmp(g_ErrCL->comp, E_TYPES[i]))
      return 1;
  return 0;
}

void print_emsg()
{
  if(got_error())
    printf("%s::[ERROR] %s\n", g_ErrCL->comp, g_ErrCL->error);
}

void free_emsg()
{
  free(g_ErrCL->error);
  memset(g_ErrCL->comp, 0, COMP_LEN);
  free(g_ErrCL);
}