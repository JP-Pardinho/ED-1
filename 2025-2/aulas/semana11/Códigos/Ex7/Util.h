#ifndef __UTIL_H
#define __UTIL_H

#include <stdio.h>

#define ERRO(msg) fprintf(stderr, "ERRO: %s\n", #msg)
#define AVISO(msg) fprintf(stdout, "AVISO: %s\n", #msg)

typedef enum {
    false,
    true
} bool;

typedef char *String;

void *mallocSafe(size_t nbytes);

void removePontuacao(String str);

#endif