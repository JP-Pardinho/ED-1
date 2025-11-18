#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
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

    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

int verificaVazia (Pilha *p) {
    return (p->topo == NULL);
}

char desempilhar (Pilha *p) {
    if (verificaVazia(p)){
        printf("\nErro: Pilha vazia!\n");
        return '\0';
    }

    No *aux = p->topo;
    char dado = aux->dado;
    p->topo = aux->prox;
    p->tamanho--;
    free(aux);

    return dado;
}


void liberarPilha (Pilha *p){

    while (!verificaVazia(p)){
        desempilhar(p);
    }

    free(p);
}

int main () {
    char entrada[1000];
    Pilha *p = criaPilha();
    char dado;


    printf("\nDigite uma mensagem (Saida era invertida): ");
    // scanf(" %s", entrada);
    fgets(entrada, 1000, stdin);

    for(int i=0; entrada[i] != '\0'; i++){
        if (entrada[i] != '\n') {
            empilhar(p, entrada[i]);
        }
    }


    for(int i = (p->tamanho); i > 0; i--) {
        dado = desempilhar(p);
        printf("%c", dado);
    }

    printf("\n");

    liberarPilha(p);
    return 0;
}