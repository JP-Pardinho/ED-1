#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main() {
    /** Exercício 1 **/
    printf("** Exercício 1 **\n");
    Lista *lista1 = criaLista();
    imprimeLista(lista1);
    insereInicioLista(lista1, 1);
    printf("Primeiro elemento da lista1: %d\n", primeiroNoLista(lista1)->dado);
    printf("Último elemento da lista1: %d\n", ultimoNoLista(lista1)->dado);
    imprimeLista(lista1);
    insereInicioLista(lista1, 2);
    imprimeLista(lista1);
    insereInicioLista(lista1, 1);
    imprimeLista(lista1);
    printf("Primeiro elemento da lista1: %d\n", primeiroNoLista(lista1)->dado);
    printf("Último elemento da lista1: %d\n", ultimoNoLista(lista1)->dado);
    printf("Tamanho da lista: %d\n\n", tamanhoLista(lista1));
    liberaLista(lista1);
    /*****************/

    /** Exercicio 2 **/
    // printf("** Exercício 2 **\n");
    // Lista *lista2 = criaLista();
    // insereFimLista(lista2, 3);
    // imprimeLista(lista2);
    // insereFimLista(lista2, 4);
    // imprimeLista(lista2);
    // insereFimLista(lista2, 5);
    // imprimeLista(lista2);
    // printf("Primeiro elemento da lista2: %d\n", primeiroNoLista(lista2)->dado);
    // printf("Último elemento da lista2: %d\n", ultimoNoLista(lista2)->dado);
    // printf("Tamanho da lista: %d\n\n", tamanhoLista(lista2));
    // liberaLista(lista2);
    /*****************/


    /** Exercicio 3 **/
    // printf("** Exercício 3 **\n");
    // Lista *lista3 = criaLista();
    // insereInicioLista(lista3, 1);
    // insereInicioLista(lista3, 2);
    // insereInicioLista(lista3, 3);
    // insereInicioLista(lista3, 3);
    // insereInicioLista(lista3, 3);
    // insereInicioLista(lista3, 4);
    // insereInicioLista(lista3, 5);
    // imprimeLista(lista3);
    // No *no4 = n_esimo(lista3, 1);
    // if (no4 /* no4 != NULL */) { 
    //     printf("Primeiro elemento: %d\n", no4->dado);
    // }
    // no4 = n_esimo(lista3, 4);
    // if (no4 /* no4 != NULL */) { 
    //     printf("Quarto elemento: %d\n", no4->dado);
    // }
    // no4 = n_esimo(lista3, 10);
    // if (no4) {
    //     printf("Decimo elemento: %d\n\n", no4->dado);
    // }
    // else {
    //     printf("Não existe o decimo elemento\n\n");
    // }
    // liberaLista(lista3);
    /*****************/

    /** Exercicio 4 **/
    // printf("** Exercício 4 **\n");
    // Lista *lista4 = criaLista();
    // imprimeLista(lista4);
    // printf("Removendo os nós com valor 4 de uma lista vazia\n");
    // removeElementoLista(lista4, 4);
    // printf("Inserindo um nó com valor 4 na lista\n");
    // insereInicioLista(lista4, 4);
    // imprimeLista(lista4);
    // printf("Removendo os nós com valor 4\n");
    // removeElementoLista(lista4, 4);
    // imprimeLista(lista4);
    // liberaLista(lista4);

    // lista4 = criaLista();
    // insereInicioLista(lista4, 1);
    // insereInicioLista(lista4, 2);
    // insereInicioLista(lista4, 3);
    // insereInicioLista(lista4, 3);
    // insereInicioLista(lista4, 3);
    // insereInicioLista(lista4, 4);
    // insereInicioLista(lista4, 5);
    // printf("\nRemoção de elementos de 'lista5'\n");
    // imprimeLista(lista4);
    // printf("Tamanho da lista: %d\n", tamanhoLista(lista4));
    // printf("Removendo os nós com valor 357\n");
    // removeElementoLista(lista4, 357);
    // imprimeLista(lista4);
    // printf("Removendo os nós com valor 3\n");
    // removeElementoLista(lista4, 3);
    // imprimeLista(lista4);
    // printf("Removendo os nós com valor 5\n");
    // removeElementoLista(lista4, 5);
    // imprimeLista(lista4);
    // printf("Removendo os nós com valor 1\n");
    // removeElementoLista(lista4, 1);
    // imprimeLista(lista4);
    // printf("Tamanho da lista: %d\n", tamanhoLista(lista4));
    // liberaLista(lista4);
    /*****************/
  

    /** Exercício 5 **/
    // printf("** Exercício 5 **\n");
    // Lista *lista5 = criaLista();
    // insereMisteriosoLista(lista5, 1);
    // insereMisteriosoLista(lista5, 5);
    // insereMisteriosoLista(lista5, 0);
    // insereMisteriosoLista(lista5, 10);
    // insereMisteriosoLista(lista5, 2);
    // insereMisteriosoLista(lista5, 7);
    // insereMisteriosoLista(lista5, 3);
    // imprimeLista(lista5);
    // liberaLista(lista5);
    /*****************/

    /** Exercício 6 - Desafio **/
    // printf("** Exercício 6 **\n");
    // Lista *lista6 = criaLista();
    // insereInicioLista(lista6, 1);
    // insereInicioLista(lista6, 2);
    // insereInicioLista(lista6, 3);
    // insereInicioLista(lista6, 3);
    // insereInicioLista(lista6, 4);
    // insereInicioLista(lista6, 5);
    // Lista *copia = copiaLista(lista6); //Deve ser *independente* da 'lista8'
    // insereFimLista(copia, 123);
    // insereFimLista(copia, 456);
    // insereFimLista(copia, 789);
    // printf("Lista original: ");
    // imprimeLista(lista6);
    // printf("Tamanho da lista original: %d\n", tamanhoLista(lista6));
    // printf(" Lista copiada: ");
    // imprimeLista(copia);
    // printf("Tamanho da lista copiada: %d\n", tamanhoLista(copia));
    // printf("Removendo alguns elementos da lista copiada...\n");
    // removeNoLista(copia, primeiroNoLista(copia));
    // removeNoLista(copia, ultimoNoLista(copia));
    // imprimeLista(copia);
    // printf("Tamanho da lista copiada: %d\n", tamanhoLista(copia));

    // printf("\nLista original: ");
    // imprimeLista(lista6);
    // printf("Tamanho da lista original: %d\n", tamanhoLista(lista6));
    // liberaLista(lista6);
    // liberaLista(copia);
    /*****************/

    return 0;
}