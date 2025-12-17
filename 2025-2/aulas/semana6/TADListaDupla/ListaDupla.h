#ifndef __LISTA_H_
#define __LISTA_H_
#include <stdbool.h>


typedef struct no {
    int dado;
    struct no *proximo;
    struct no *anterior;
} No;

typedef struct listaDupla ListaDupla;

ListaDupla *criaListaDupla();

void liberaListaDupla(ListaDupla *lista);

void insereInicioListaDupla(ListaDupla *lista, int elem);

void insereFimListaDupla(ListaDupla *lista, int elem);

No *primeiroNoListaDupla(ListaDupla *lista);

No *ultimoNoListaDupla(ListaDupla *lista);

void imprimeListaDupla(ListaDupla *lista);

bool listaDuplaVazia(ListaDupla *l);

int tamanhoListaDupla(ListaDupla *lista);

No *procuraListaDupla(ListaDupla *lista, int valor);

No *procuraNoListaDupla(ListaDupla *lista, No *p);

void removeElementoListaDupla(ListaDupla *lista, int valor);

void removeNoListaDupla(ListaDupla *lista, No *p);

ListaDupla* filtraListaDupla(ListaDupla *lista, bool (*compara)(int)) ;

#endif
