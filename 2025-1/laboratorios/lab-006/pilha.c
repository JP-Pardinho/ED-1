#include "pilha.h"

Pilha *criaNo(char carac){
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    if (novo == NULL){
        printf("\nErro: Nó não alocado\n");
        exit(1);
    }
    strcpy(novo->caracter, carac);
    novo->prox = NULL;
    return novo;
}

Pilha *insereInicio(Pilha *L, char carac){
    Pilha *novo = criaNo(carac);

    if(L == NULL) return novo;
    novo->prox = L;
    L = novo;
    return L;
}

Pilha *removeInicio(Pilha *L){
    Pilha *aux = L;

    if(aux == NULL){
        printf("Erro: Pilha vazia");
        return NULL;
    }

    L = L->prox;
    free(aux);
    return L;
}


