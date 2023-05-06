#ifndef _M_FILE_H_
#define _M_FILE_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

int32_t mfile_size(const char *path);

char *mfile_load(const char *path, int32_t *size);

void mfile_unload(char *buf);

#endif
