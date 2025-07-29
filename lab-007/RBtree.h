#ifndef __RB_TREE__
#define __RB_TREE__

#include <stdio.h>
#include <stdlib.h>

#define NEGRO 0
#define RUBRO 1

typedef struct No {
    int chave;
    int cor;
    // VERMELHO: 1 / PRETO: 0 
    struct no* esq;
    struct no* dir;
    struct no* pai;
}No;

No no_externo = {-1, NEGRO, NULL, NULL, NULL};

No *EXTERNO = &no_externo;

No* criaNo(int chave);

No* busca(No* raiz, int valor);

void imprime(No* raiz, int nivel);

No* rotacaoEsquerda(No* T, No* w);

No* rotacaoDireita(No* T, No* w);

No* insere(No* raiz, int valor);

No* insereFixup(No* raiz, No* z);

No* sucessor(No* x);

No* exclui(No* raiz, int valor);

No* excluiFixup(No* raiz, No* x);

#endif