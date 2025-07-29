#include "RBtree.h"

No *criaNo(int chave){
    No *novo = (No*)calloc(1, sizeof(No));
    if (novo == NULL){
        printf("\nErro de alocação\n");
        exit(1);
    }

    novo->chave = chave;
    novo->cor = RUBRO;
    return novo;
}

No* busca(No* raiz, int valor){
    if(raiz->chave == EXTERNO){
        return EXTERNO;
    }
    
    if (raiz->chave == valor){
        return raiz;
    }
    if (raiz->chave > valor){
        return busca(raiz->esq, valor);
    } else {
        return busca(raiz->dir, valor);
    }
}

void imprime(No* raiz, int nivel){
    if (raiz == EXTERNO || raiz == NULL) return;
    
    Imprime(raiz->dir, nivel + 1);
    
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("[%d : %s]\n", raiz->chave, raiz->cor == RUBRO ? "RUBRO" : "NEGRO");
    
    Imprime(raiz->esq, nivel + 1);
}
