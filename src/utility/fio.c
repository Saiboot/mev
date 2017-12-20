#include "inc/fio.h"


char *fo(char *path)
{
  FILE* pFile = fopen(path, "r");

  if(!pFile) {
    cast_emsg(ET_IO, "File: not accessible");
    return NULL;
  }

  /* file size */
  fseek(pFile, 0L, SEEK_END);
  unsigned int size = ftell(pFile);
  fseek(pFile, 0L, SEEK_SET);
  rewind(pFile);

  if(size < 0)
    cast_emsg(ET_IO, "File: size");

  /* allocate file buffer - depending on file size */
  char *aBuf = malloc(sizeof(char) * size + 1);
  memset(aBuf, 0, size + 1);

  /* read file content into buffer */
  fread(aBuf, size, 1, pFile);
  if (ferror(pFile))
    return NULL;

  /* null-terminate buffer */
  aBuf[size] = '\0';

  /* close file stream */
  fclose(pFile);

  return aBuf;

}

void fi(char *data)
{

}

char *fkey(char *path, char *key)
{
  char *data = fo(path);

  char *token = strtok(data, "=");

  while(strcmp(key, token)) {
    strtok(NULL, "\n");
    token = strtok(NULL, "=");
  }

  return strtok(NULL, "\n");
}