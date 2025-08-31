#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *prox;
} No;

typedef struct pilha {
    struct No *topo;
    int tamanho; 
} Pilha;

No *criaNo (char dado) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("\nErro: Nó não alocado\n");
        exit(1);
    }

    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

Pilha *criaPilha () {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL){
        printf("\nErro: Pilha não alocada\n");
        exit(1);
    }

    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

void empilhar(Pilha *p, char valor) {
    No *novo = criaNo(valor);
    if (p == NULL){
        p->topo = novo;
        p->tamanho++;
    }

    novo->prox = p;
    p = novo;
    p->tamanho++;
}

char desempilhar (Pilha *p) {
    if (p == NULL){
        return NULL;
    }

    No *aux = p;
    char dado = aux->dado;
    p->topo = aux->prox;
    p->tamanho--;
    free(aux);

    return dado;
}

int verificaVazia (Pilha *p) {
    if(p->topo == NULL){
        return 1;
    }

    return 0;
}

void liberarPilha (Pilha *p){
    No *aux = NULL;
    while (p->topo != NULL){
        aux = p->topo;
        p->topo = aux->prox;
        free(aux);
    }
}

int main () {
    char entrada[1000];
    Pilha *p = criaPilha();
    char dado;


    printf("\nDigite uma mensagem (Saida era invertida)");
    // scanf(" %s", entrada);
    fgets(entrada, 1000, stdin);

    for(int i=0; i != '\0'; i++){
        empilhar(p, entrada[i]);
    }

    for(int i = (p->tamanho); i > 0; i--) {
        dado = desempilhar(p);
        printf("%c", dado);
    }

    return 0;
}