#include <stdlib.h> 
#include <stdio.h>  
#include <string.h>
#include <ctype.h> // Para usar a função ispunct

#include "Util.h"


/* Fonte:  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html */
void *mallocSafe(size_t nbytes) {
    void *ptr;

    ptr = malloc(nbytes);
    if (ptr == NULL) {
        ERRO(Socorro !malloc devolveu NULL !);
        exit(EXIT_FAILURE);
    }

    return ptr;
}

/**
 * @brief Remove possiveis pontuações de uma palavra
 * 
 * @param str 
 */
void removePontuacao(String str) {
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (!ispunct(str[i]) || str[i] == '-' || str[i] == '/')
            str[count++] = str[i];
    str[count] = '\0';
}
