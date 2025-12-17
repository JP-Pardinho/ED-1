#include <stdio.h>
#include <stdlib.h>

#include "Arvore.h"
#include "Util.h"

struct arvore {
    No *raiz;
    int numeroNos;
};

/**
 * @brief Cria a árvore
 * 
 * @return Arvore* 
 */
Arvore *criaArvore() {
    Arvore *arvore = mallocSafe(sizeof(Arvore));
    arvore->raiz = NULL;
    arvore->numeroNos = 0;
    return arvore;
}

/**
 * @brief Faz a desalocação de memória utilizada pelos nós da árvore
 * 
 * @param r 
 */
void liberaNosArvore(No *r){
    if(r != NULL) {
        liberaNosArvore(r->esq);
        liberaNosArvore(r->dir);
        liberaNo(r);
    }
}

/**
 * @brief Libera os nós da árvore
 * 
 * @param arvore 
 */
void liberaArvore(Arvore *arvore) {
    /* Note que é chamada a função auxiliar passando o nó raiz */
    liberaNosArvore(arvore->raiz);
    free(arvore);
}

/**
 * @brief Verifica se a árvore está vazia ou não
 * 
 * @param arvore 
 * @return true ou false
 */
bool arvoreVazia(Arvore *arvore) {
    return arvore == NULL || arvore->raiz == NULL;
}

void padding( char ch, int n ){
  for (int i = 0; i < n; i++ )
    putchar(ch);
}

/**
 * @brief Função auxiliar para imprimir os nós da árvore
 * 
 * @param no 
 * @param nivel 
 */
void imprimeArvoreAux ( No *no, int nivel ){
  if ( no == NULL ) {
    padding('\t', nivel );
    puts("~");
  } else {
    imprimeArvoreAux ( no->dir, nivel + 1 );
    padding('\t', nivel );
    imprimeNo(no);
    imprimeArvoreAux ( no->esq, nivel + 1 );
  }
}

/**
 * @brief Imprime os nós da árvore
 * 
 * @param arvore 
 */
void imprimeArvore(Arvore *arvore) {
    /* Note que é chamada a função auxiliar passando o nó raiz */
    imprimeArvoreAux(arvore->raiz, 0);
}

/**
 * @brief Função auxiliar para realizar a busca
 * 
 * @param r 
 * @param valor 
 * @return No* 
 */
No* buscaAux (No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) 
        return raiz;
    if (raiz->dado > valor)
        return buscaAux(raiz->esq, valor);
    else
        return buscaAux(raiz->dir, valor);
}

/**
 * @brief Faz a busca na árvore através do inteiro valor
 * 
 * @param arvore 
 * @param valor 
 * @return No* 
 */
No *buscaArvore(Arvore *arvore, int valor) {
    /* Note que é chamada a função auxiliar passando o nó raiz */
    return buscaAux(arvore->raiz, valor);
}

/**
 * @brief Insere um novo nó na árvore binária de busca
 * 
 * @param raiz 
 * @param novo 
 * @return No* 
 */

No* insereNo(No* raiz, No* novo) {
    return NULL;
    AVISO(Arvore.c : ainda não completei a função 'insereNo');

    // if (raiz == NULL)
    //     return // ???
    
    // if (novo->dado < raiz->dado)
    //     raiz->esq = // ???
    // else
    //     raiz->dir = // ???
    
    // return // ???

}

/**
 * @brief Insere um novo valor na árvore. 
 * 
 * @param arvore 
 * @param valor 
 */
void insereArvore(Arvore *arvore, int valor) {
    arvore->raiz = insereNo(arvore->raiz, criaNo(valor));
    arvore->numeroNos++;
}

/**
 * @brief Função auxiliar para calcular a altura da árvore
 * 
 * @param r 
 * @return int 
 */
int alturaAux(No *r) {

    AVISO(Arvore.c : ainda não completei a função 'alturaAux');
    return 0;

    // if (r == NULL)
    //     return ???
    // int hSAE = ???
    // int hSAD = ???
    // if (hSAE > hSAD)
    //     return ???
    // else
    //     return ???
}

/**
 * @brief Calcula a altura da árvore
 * 
 * @param arvore 
 * @return int 
 */
int alturaArvore(Arvore *arvore) {
    /* Note que é chamada a função auxiliar passando o nó raiz */
    return alturaAux(arvore->raiz);
}

/**
 * @brief Retorna a quantidade de nós da árvore
 * 
 * @param arvore 
 * @return int 
 */
int numeroNosArvore(Arvore *arvore) {
    return arvore->numeroNos;
}


