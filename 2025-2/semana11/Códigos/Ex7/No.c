#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "No.h"
#include "Util.h"

/**
 * @brief Cria um nó
 * 
 * @param palavra 
 * @return No* 
 */
No *criaNo(String palavra) {
    No *no = mallocSafe(sizeof(No));
    AVISO(No.c: ainda não completei a função 'criaNo');
    return no;
}

/**
 * @brief Faz a desalocação de memória usada pelo nó
 * 
 * @param no 
 */
void liberaNo(No *no) {
    if (no) {
        free(no->palavra);
        free(no);
    }
}

/**
 * @brief Imprime a informação contida no nó
 * 
 * @param no 
 */
void imprimeNo(No *no) {
    printf("(%s, %d)\n", no->palavra, no->quantidade);
}