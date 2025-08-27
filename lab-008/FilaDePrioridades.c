#include "FilaDePrioridades.h"

F *criaFilaPrioridades(F *fila, int c){
    F *fila = (F*)malloc(sizeof(F));
    if (fila == NULL) {
        printf("\nErro: alocação mal sucedida\n");
        exit(1);
    }

    fila->tamanho = c;
    return fila;    
}

int compara(void *k, void *l){
    k = (G*)k;
    l = (G*)l;
    
}

F *corrige(F *fila, void* compara(void*, void*)){
    int aux = fila->tamanho;
    while (aux > 1 && compara(fila->itens[aux/2], fila->itens[aux]) < 0){
        
    }
}

F *insere(F *fila, G valor){
    if(fila == NULL){
        fila->itens[1] = valor;
        return fila;
    }

    fila->itens[fila->tamanho + 1] = valor;
    fila->tamanho++;
    fila = corrige(fila);
    return fila;
}