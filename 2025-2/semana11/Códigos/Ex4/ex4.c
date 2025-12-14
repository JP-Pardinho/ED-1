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

int misterio1(No *raiz) {
    if (raiz == NULL)
        return 0;
    int nnSAE = misterio1(raiz->esq);
    int nnSAD = misterio1(raiz->dir);
    return nnSAE + nnSAD + 1;
}

int misterio2(No *raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    return misterio2(raiz->esq) + misterio2(raiz->dir);
}

int main() {
    No *raiz = criaNo(8);
    raiz->esq = criaNo(3);
    raiz->dir = criaNo(10);
    raiz->esq->esq = criaNo(2);
    raiz->esq->dir = criaNo(6);
    raiz->dir->esq = criaNo(9);

    printf("Misterio1: %d\n", misterio1(raiz));
    printf("Misterio2: %d\n", misterio2(raiz));

    return 0;
}