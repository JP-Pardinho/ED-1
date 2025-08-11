#ifndef __FILA_DE_PRIORIDADES__
#define __FILA_DE_PRIORIDADES__

#include <stdio.h>
#include <stdlib.h>

typedef struct generico {
    void *valor;
}G;

typedef struct fila {
    G itens[100];
    int tamanho = 0;
}F;

F *criaFilaPrioridades(F *fila, int c);
F *insere(F *fila, G valor);
F *corrige(F *fila);
F *minimo(F *fila);
F *extrairMinimo(F *fila);
F *decrementaChave(F *fila, G valorAntigo, G novoValor);
F *deleta(F *fila, G valor);
void imprimir(F *fila);

#endif