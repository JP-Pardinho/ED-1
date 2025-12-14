#include <stdlib.h> 
#include <stdio.h>  

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
