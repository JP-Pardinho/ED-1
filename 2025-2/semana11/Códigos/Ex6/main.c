#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arvore.h"
#include "Util.h"
#include "No.h"

int main() {
    Arvore *arvore = criaArvore();
    int valor;
    while(scanf("%d", &valor) == 1) {
        insereArvore(arvore, valor);
    }
    imprimeArvore(arvore);
    printf("Altura: %d\n", alturaArvore(arvore));
    printf("  #Nos: %d\n", numeroNosArvore(arvore));
    liberaArvore(arvore);
    return 0;
}