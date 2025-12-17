#ifndef __LISTA_H_
#define __LISTA_H_

#include <stdbool.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

typedef struct lista Lista;

Lista *criaLista();

void liberaLista(Lista* lista);

void insereInicioLista(Lista *lista, int elem);

void imprimeLista(Lista *lista);

bool listaVazia(Lista *l);

int tamanhoLista(Lista *lista);

No* primeiroNoLista(Lista *lista);

No* ultimoNoLista(Lista *lista);

void insereFimLista(Lista *lista, int elem);

No* n_esimo(Lista *lista, int n);

No* procuraLista(Lista *lista, int valor);

void removeElementoLista(Lista *lista, int valor);

Lista* copiaLista(Lista *lista);

void insereMisteriosoLista(Lista *lista, int valor);


#endif
