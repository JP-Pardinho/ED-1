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
        exit(1);
    } else {
        novo->dado = valor;
        novo->prox = NULL;
        return novo;
    }
}

No *incereOrde(No *lista, int valor){
    No *novo = criaNo(valor);
    No *aux = lista, *pred = NULL;
    if (lista == NULL) lista = novo;
    else {
        while (aux != NULL && valor > aux->dado){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            novo->prox = lista; 
            lista = novo;
        } else {
            pred->prox = novo;
            novo->prox = aux;
        }
    }
    return novo;
}

No *fusao(No *lista1, No *lista2) {
    No *nova_lista = NULL; 
    No *ultimo = NULL;

    if(lista1 == NULL) return lista2;
    if(lista1 == NULL) return lista1;

    if(lista1->dado <= lista2->dado){
        nova_lista = lista1;
        lista1 = lista1->prox;
    } else{
        nova_lista = lista2;
        lista2 = lista2->prox;
    }
    
    ultimo = nova_lista;

    while (lista1 != NULL && lista2 != NULL){
        if(lista1->dado <= lista2->dado){
            ultimo->prox = lista1;
            lista1 = lista1->prox;
        } else {
            ultimo->prox = lista2;
            lista2 = lista2->prox;
        }
        ultimo = ultimo->prox;
    }
    
    if(lista1 != NULL){
        ultimo->prox = lista1;
    } else {
        ultimo->prox = lista2;
    }

    return nova_lista;
}

void imprimeLista(No *lista) {
    No *aux = lista;
    while(aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
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
    No *lista1 = NULL;
    No *lista2 = NULL;
    No* resultado = NULL;
    int qnt = 0, i=0;
    int chave;

    printf("\nSomando: \n");
    printf("A lista 1 tem quantos elementos: ");
    scanf("%d", &qnt);
    for (i = 0; i < qnt; i++){
        printf("Digite a chave: ");
        scanf("%d", &chave);
        lista1 = incereOrde(lista1, chave);        
    }   
    printf("A lista 2 tem quantos elementos: ");
    scanf("%d", &qnt);
    for (i = 0; i < qnt; i++){
        printf("Digite a chave: ");
        scanf("%d", &chave);
        lista2 = incereOrde(lista2, chave);
    }

    resultado = fusao(lista1, lista2);
    imprimeLista(resultado);

    liberaLista(resultado);

    return 0;
}