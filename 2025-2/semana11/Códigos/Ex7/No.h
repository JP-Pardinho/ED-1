#ifndef __NO_H
#define __NO_H

#include "Util.h"

typedef struct no {
    String palavra;
    int quantidade;
    struct no *esq;
    struct no *dir;
}No;

No *criaNo(String);

void liberaNo(No *);

void imprimeNo(No *);

#endif