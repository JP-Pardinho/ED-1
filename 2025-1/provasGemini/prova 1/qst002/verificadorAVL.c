#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Para usar a função abs()

typedef struct no {
    int chave;
    struct no *esq, *dir;
} No;

// Função para criar um novo nó (facilita os testes)
No* criarNo(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função auxiliar (a sua já estava correta)
int max(int a, int b){
    return (a > b) ? a : b;
}

// ---- FUNÇÕES CORRIGIDAS ----

// Calcula a altura de um nó. Altura de NULL é -1.
int alturaNo(No *no) {
    if (no == NULL) {
        return -1;
    }
    return 1 + max(alturaNo(no->esq), alturaNo(no->dir));
}

// Calcula o fator de balanceamento de um nó.
int obterFatorBalanc(No *no) {
    if (no == NULL) {
        return 0;
    }
    return alturaNo(no->esq) - alturaNo(no->dir);
}

// Verifica recursivamente se a árvore é AVL.
int ehAVL(No *raiz) {
    // 1. Caso base: uma árvore vazia é AVL.
    if (raiz == NULL) {
        return 1; // true
    }

    // 2. Calcula o fator de balanceamento do nó atual.
    int fatorBalanceamento = obterFatorBalanc(raiz);

    // 3. Verifica as 3 condições:
    //    a) Fator do nó atual é válido?
    //    b) A sub-árvore esquerda é AVL?
    //    c) A sub-árvore direita é AVL?
    if (abs(fatorBalanceamento) <= 1 && ehAVL(raiz->esq) && ehAVL(raiz->dir)) {
        return 1; // true
    }
    
    // Se qualquer condição falhar, a árvore não é AVL.
    return 0; // false
}


int main() {
    printf("--- Testando Verificador de AVL ---\n");

    /*
    Exemplo 1: Árvore que É AVL
        20
       /  \
      10  30
    */
    No *raizAVL = criarNo(20);
    raizAVL->esq = criarNo(10);
    raizAVL->dir = criarNo(30);

    if (ehAVL(raizAVL)) {
        printf("Teste 1: A arvore 1 EH uma arvore AVL. (Correto)\n");
    } else {
        printf("Teste 1: A arvore 1 NAO EH uma arvore AVL. (Incorreto)\n");
    }


    /*
    Exemplo 2: Árvore que NÃO É AVL (fator de balanc. da raiz é -2)
        10
         \
          20
           \
            30
    */

    No *raizNaoAVL = criarNo(10);
    raizNaoAVL->dir = criarNo(20);
    raizNaoAVL->dir->dir = criarNo(30);

    if (ehAVL(raizNaoAVL)) {
        printf("Teste 2: A arvore 2 EH uma arvore AVL. (Incorreto)\n");
    } else {
        printf("Teste 2: A arvore 2 NAO EH uma arvore AVL. (Correto)\n");
    }

    return 0;
}