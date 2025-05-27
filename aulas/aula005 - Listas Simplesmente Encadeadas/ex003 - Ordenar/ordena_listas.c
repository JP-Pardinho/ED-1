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
    No *aux1 = lista1;
    No *aux2 = lista2;
    No *resultado = NULL;
    No *ultimo = NULL;
    
    if (aux1 == NULL) {
        return aux2;
    } else if (aux2 == NULL) {
        return aux1;    
    }
    
    // Inicializa a lista resultado
    if (aux1->dado <= aux2->dado) {
        resultado = aux1;
        aux1 = aux1->prox;
    } else {
        resultado = aux2;
        aux2 = aux2->prox;
    }
    ultimo = resultado;
    
    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->dado <= aux2->dado) {
            ultimo->prox = aux1;
            aux1 = aux1->prox;
        } else {
            ultimo->prox = aux2;
            aux2 = aux2->prox;
        }
        ultimo = ultimo->prox;
    }
    
    // Anexa os elementos restantes
    if (aux1 != NULL) {
        ultimo->prox = aux1;
    } else {
        ultimo->prox = aux2;
    }
    
    return resultado;
}

void imprimeLista(No *lista){
    No *aux = lista;
    if(aux == NULL) return;
    printf(" - %d - ", lista->dado);
    imprimeLista(lista->prox);
    printf("\n\n");
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

    // liberaLista(lista1);
    // liberaLista(lista2);
    liberaLista(resultado);

    return 0;
}