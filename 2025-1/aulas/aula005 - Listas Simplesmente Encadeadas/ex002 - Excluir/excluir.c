#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int chave;
    struct No *prox;
} No;


No *criaNo(int valor){
    No *novo = (No *)malloc(sizeof(No));
    if(novo == NULL){
        printf("Alocação mal sucedida!\n");
        exit(1);
    } else{
        novo->chave = valor;
        novo->prox = NULL;
        return novo;
    }
    
}

No *insereIni(No *L, int valor){
    No *novo = criaNo(valor);
    if(L == NULL) L = novo;
    else{
        novo->prox = L;
        L = novo;
    }
    return L;
}


No *excluir (No *lista){
    No *fix = lista;
    
    // while(fix != NULL && fix->prox != NULL){
    while (fix != NULL){
        No *pred = fix;
        No *aux = fix->prox;
        while (aux != NULL){
            if (fix->chave == aux->chave){
                pred->prox = aux->prox;
                free(aux);
                aux = pred->prox;
            } else {
                pred = aux;
                aux = aux->prox;
            }
        }
        fix = fix->prox;
    }
    return lista;
}


void imprimeLista(No *lista){
    No *aux = lista;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }

}

void liberaLista(No *lista) {
    No *aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}


int main() {
    int valor = 0;
    No *lista = NULL;
    
    for (int i=0; i < 2; i++){
        scanf("%d", &valor);
        lista = insereIni(lista, valor);
    }


    printf("Lista com numeros repetidos:\n");
    imprimeLista(lista);
    printf("\n");

    lista = excluir(lista);  // Corrigir duplicatas

    printf("Lista sem numeros repetidos:\n");
    imprimeLista(lista);
    printf("\n");

    
    liberaLista(lista);

    return 0;
}