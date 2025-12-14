#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERRO(msg) fprintf(stderr, "ERRO: %s\n", #msg)
#define AVISO(msg) fprintf(stdout, "AVISO: %s\n", #msg)

void *mallocSafe(size_t nbytes);


#endif