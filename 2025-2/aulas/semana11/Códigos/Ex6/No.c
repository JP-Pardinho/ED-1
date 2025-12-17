#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "No.h"
#include "Util.h"

/**
 * @brief Cria um nó
 * 
 * @param dado 
 * @return No* 
 */
No *criaNo(int dado) {
    No *no = mallocSafe(sizeof(No));
    no->dado = dado;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

/**
 * @brief Faz a desalocação de memória usada pelo nó
 * 
 * @param no 
 */
void liberaNo(No *no) {
    if (no) {
        free(no);
    }
}

/**
 * @brief Imprime a informação contida no nó
 * 
 * @param no 
 */
void imprimeNo(No *no) {
    printf("%d\n", no->dado);
}