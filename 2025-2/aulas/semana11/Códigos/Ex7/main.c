#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arvore.h"
#include "Util.h"
#include "No.h"

int main() {
    Arvore *arvore = criaArvore();
    char palavra[128];
    while(scanf("%s", palavra) == 1) {
        removePontuacao(palavra);
        insereArvore(arvore, palavra);
    }
    imprimeArvore(arvore);
    No *no = palavraMaisFrequente(arvore);
    printf("Altura: %d\n", alturaArvore(arvore));
    printf("  #Nos: %d\n", numeroNosArvore(arvore));
    printf("A palavra '%s' foi a mais frequente, aparecendo %d vezes\n", no->palavra, no->quantidade);
    liberaArvore(arvore);
    return 0;
}