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

void imprime(No *raiz) {
    if(raiz != NULL) {
        printf("%d\n", raiz->dado);
        imprime(raiz->esq);
        imprime(raiz->dir);
    }
}

int main() {
    No *raiz = criaNo(8);
    raiz->esq = criaNo(3);
    raiz->dir = criaNo(10);
    raiz->esq->esq = criaNo(2);
    raiz->esq->dir = criaNo(6);
    raiz->dir->dir = criaNo(14);

    imprime(raiz);

    return 0;
}