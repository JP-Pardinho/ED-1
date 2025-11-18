#ifndef __LISTA_H_
#define __LISTA_H_
#include <stdbool.h>


typedef struct no {
    void* dado;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct lista Lista;

Lista *criaLista();

void liberaLista(Lista *lista, void(* LiberarCallback )(void *));

void insereInicioLista(Lista *lista, void *elem);

void insereFimLista(Lista *lista, void *elem);

No *primeiroNoLista(Lista *lista);

No *ultimoNoLista(Lista *lista);

void imprimeLista(Lista *lista, void(* ImprimeCallback )( void *));

bool listaVazia(Lista *l);

int tamanhoLista(Lista *lista);

No *procuraLista(Lista *lista, void* valor, int (*CompararCallbak)(void *, void *));

No *procuraNoLista(Lista *lista, No *p);

void removeElementoLista(Lista *lista, void *valor, int (*CompararCallbak)(void *, void *), void (*LiberarCallback)(void *));

void removeNoLista(Lista *lista, No *p);

Lista* filtraLista(Lista *lista, bool (*compara)(int)) ;

#endif
