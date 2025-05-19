#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *criaNo(int valor){
    No *novo = (No *)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro: Alocação mal feita!\n");
        exit(404);
    } else {
        novo->dado = valor;
        novo->prox = NULL;
        return novo;
    }
}

// No incereOrde(No *lista, int valor){
//     No *novo = criaNo(valor);
//     No *aux = lista, *pred = aux;
//     if (lista == NULL) lista = novo;
//     else {
//         while (aux != NULL && valor > aux->dado){
//             if()
//         }

//     }
    
// }

No *concatena(No *lista1, No *lista2){
    No *aux = lista1;
    
}

int main() {


    return 0;
}