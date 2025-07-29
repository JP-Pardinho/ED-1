#ifndef __PILHA_H__
#define __PILHA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha {
    char caracter[1];
    struct no *prox;
} Pilha;

Pilha *criaNo(char carac);
Pilha *insereInicio(Pilha *L, char carac);
Pilha *removeInicio(Pilha *L);

#endif