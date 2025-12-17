#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * @param palavra 
 * @return No* 
 */
No* buscaAux (No* r, String palavra) {
    if (r == NULL) 
        return r;
    // A função strcmp compara duas strings e retorna:
    // - 0 se as strings são iguais
    // - um valor negativo se a primeira string é menor que a segunda
    // - um valor positivo se a primeira string é maior que a segunda
    int comparacao = strcmp(palavra, r->palavra);
    if (comparacao == 0)
        return r;   
    else if (comparacao < 0)
        return buscaAux(r->esq, palavra);
    else
        return buscaAux(r->dir, palavra);
}

/**
 * @brief Faz a busca na árvore através do string palavra
 * 
 * @param arvore 
 * @param palavra 
 * @return No* 
 */
No *buscaArvore(Arvore *arvore, String palavra) {
    /* Note que é chamada a função auxiliar passando o nó raiz */
    return buscaAux(arvore->raiz, palavra);
}

/**
 * @brief Insere um novo nó na árvore binária de busca
 * 
 * @param raiz 
 * @param novo 
 * @return No* 
 */
No *insereNo(No *raiz, No *novo){
    if(raiz == NULL)
        return novo;

    if (strcmp(novo->palavra, raiz->palavra) < 0)
        raiz->esq = insereNo(raiz->esq, novo);
    else 
        raiz->dir = insereNo(raiz->dir, novo);

    return raiz;
}

/**
 * @brief Insere uma nova palavra na árvore. Se a palavra já estiver na 
 * árvore, o campo 'quantidade' associado ao nó da palavra é aumentado 
 * em uma unidade. 
 * 
 * @param arvore 
 * @param palavra 
 */
void insereArvore(Arvore *arvore, String palavra) {
    /**
     * Da forma como está implementada, todos as palavras são incluídas na árvore.
     * Sua tarefa é incluir uma palavra, apenas se ela ainda não pertencer a árvore.
     * Caso ela já esteja na árvore, você devem apenas atualizar (aumentar em uma
     * unidade) o campo 'quantidade'
     * do nó associado a palavra. 
     * 
     */
    AVISO(Arvore.c: ainda não completei a função 'insereArvore');
    arvore->raiz = insereNo(arvore->raiz, criaNo(palavra));
    arvore->numeroNos++;

}

/**
 * @brief Função auxiliar para calcular a altura da árvore
 * 
 * @param r 
 * @return int 
 */
int alturaAux(No *r) {
    if(r == NULL)
        return -1;
    int hSAE = alturaAux(r->esq);
    int hSAD = alturaAux(r->dir);
    if (hSAE > hSAD)
        return hSAE + 1;
    else
        return hSAD + 1;
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


/**
 * @brief Retorna o nó da árvore cujo campo 'quantidade' é o maior.
 * 
 * @param arvore 
 * @return No* 
 */
No *palavraMaisFrequente(Arvore *arvore) {
    AVISO(Arvore.c: ainda não completei a função 'palavraMaisFrequente');
    //Dica: Implemente outra função auxiliar que receba a raiz da árvore
    return arvore->raiz;
}


