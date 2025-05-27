#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
} No;

No *criaNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if(novo == NULL) {
        printf("Erro: Alocação mal feita!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

No *insereOrdenado(No *lista, int valor) {
    No *novo = criaNo(valor);
    No *atual = lista;
    No *anterior = NULL;
    
    while(atual != NULL && valor > atual->dado) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if(anterior == NULL) {
        novo->prox = lista;
        lista = novo;
    } else {
        anterior->prox = novo;
        novo->prox = atual;
    }
    
    return lista;
}

No *fusao(No *lista1, No *lista2) {
    No dummy;
    No *ultimo = &dummy;
    dummy.prox = NULL;
    
    while(lista1 != NULL && lista2 != NULL) {
        if(lista1->dado <= lista2->dado) {
            ultimo->prox = lista1;
            lista1 = lista1->prox;
        } else {
            ultimo->prox = lista2;
            lista2 = lista2->prox;
        }
        ultimo = ultimo->prox;
    }
    
    ultimo->prox = (lista1 != NULL) ? lista1 : lista2;
    return dummy.prox;
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
    while(lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main() {
    No *lista1 = NULL;
    No *lista2 = NULL;
    No *resultado = NULL;
    int qnt = 0, i = 0;
    int chave;

    printf("Lista 1 - Quantos elementos: ");
    scanf("%d", &qnt);
    for(i = 0; i < qnt; i++) {
        printf("Digite a chave: ");
        scanf("%d", &chave);
        lista1 = insereOrdenado(lista1, chave);
    }
    
    printf("Lista 2 - Quantos elementos: ");
    scanf("%d", &qnt);
    for(i = 0; i < qnt; i++) {
        printf("Digite a chave: ");
        scanf("%d", &chave);
        lista2 = insereOrdenado(lista2, chave);
    }

    printf("\nLista 1: ");
    imprimeLista(lista1);
    printf("Lista 2: ");
    imprimeLista(lista2);

    resultado = fusao(lista1, lista2);
    printf("\nLista fundida: ");
    imprimeLista(resultado);

    // Não precisamos liberar lista1 e lista2 pois elas foram fundidas em resultado
    liberaLista(resultado);

    return 0;
}