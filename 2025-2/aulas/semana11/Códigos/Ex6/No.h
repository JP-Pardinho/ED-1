#ifndef __NO_H
#define __NO_H

#include "Util.h"

typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
}No;

No *criaNo(int);

void liberaNo(No *);

void imprimeNo(No *);

#endif