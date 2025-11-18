#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *ant;
    struct no *prox;
} No;

No *criaNo(int valor){
    No *novo = NULL;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro: Alocação não funcionou!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

No *buscaOrd(No *lista, int valor){
    No *aux = lista;
    while (aux != NULL && valor > aux->dado) {
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

No *insereOrd(No *lista, int valor){
    No *novo = criaNo(valor);
    No *aux = buscaOrd(lista, valor);
    if(aux == NULL) return novo;
    else { 
        if (aux->dado < valor) { //MAIOR QUE TODOS
            aux->prox = novo;
            novo->ant = aux;
        } else {
            novo->prox = aux;
            if(aux->ant == NULL) lista = novo;      
            else {
                aux->ant->prox = novo;
                novo->prox = aux->ant;
            }  
        }
        aux->ant = novo;
    }
    return lista;
} 

No *fusao(No *lista1, No *lista2){
    No *resultado = NULL;
    No *aux1 = lista1;
    No *aux2 = lista2;
    while (aux1 != NULL || aux2 != NULL){
        
    }
    
}

int main(){


    return 0;
}