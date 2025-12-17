#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *dir;
    struct no *esq;
}No;

No *criaNo(int v) {
    No *novo = malloc(sizeof(No));
    novo->dado = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void libera(No *raiz) {
    if (raiz) {
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
    }
}

int main() {
    No *raiz = criaNo(8);
    raiz->esq = criaNo(3);
    raiz->dir = criaNo(10);
    raiz->esq->esq = criaNo(2);
    raiz->esq->dir = criaNo(6);
    raiz->dir->dir = criaNo(14);

    libera(raiz);

    return 0;
}