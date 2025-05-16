#include <stdio.h>
#include <stdlib.h>

typedef struct L1
{
    int chave;
    struct L1 *prox;
} L1;

L1 *criaNo(int valor){
    L1 *novo = (L1 *)malloc(sizeof(L1));
    if(novo == NULL){
        printf("Alocação mal sucedida!\n");
        exit(1);
    } else{
        novo->chave = valor;
        novo->prox = NULL;
        return novo;
    }
    
}

L1 *insereIni(L1 *L, int valor){
    L1 *novo = criaNo(valor);
    if(L == NULL) L = novo;
    else{
        novo->prox = L;
        L = novo;
    }
    return L;
}

L1 *concatena (L1 *lista1, L1 *lista2){
    L1 *aux = lista1;
    if(lista1 == NULL){
        lista1 = lista2;
        return lista1;
    }

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = lista2;
    return lista1;
}   

void imprimeLista(L1 *lista){
    L1 *aux = lista;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }

}

int main(){

    L1 *lista1 = NULL;
    L1 *lista2 = NULL;

    lista1 = insereIni(lista1, 99);
    lista2 = insereIni(lista2, 100);

    lista1 = concatena(lista1, lista2);

    imprimeLista(lista1);

    free(lista1);
    free(lista2);
    return 0;
}