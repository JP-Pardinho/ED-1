#ifndef __ARVORE_H
#define __ARVORE_H

#include "No.h"

typedef struct arvore Arvore;

Arvore *criaArvore();

void liberaArvore(Arvore *);

void imprimeArvore(Arvore *);

bool arvoreVazia(Arvore *);

No *buscaArvore(Arvore *, int);

void insereArvore(Arvore *, int);

int alturaArvore(Arvore *);

int numeroNosArvore(Arvore *);

#endif