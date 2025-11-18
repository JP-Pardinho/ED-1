#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criaLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void insere(Lista *l, int valor) {
    No *no = malloc(sizeof(No));
    no->dado = valor;
    no->proximo = l->inicio;
    l->inicio = no;
}

void imprimeLista(Lista *l) {
    No *atual = l->inicio;
    while (atual) { //ou while (atual != NULL)
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
}

void liberaLista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *tmp = atual->proximo;
        free(atual);
        atual = tmp;
    }
    free(l);
    l = NULL;
}

int main() {
    Lista *l = criaLista();
    insere(l, 2);
    insere(l, 3);
    insere(l, 5);
    insere(l, 7);

    imprimeLista(l);

    liberaLista(l);

    return 0;
}