#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main() {
    /** Exercício 1 **/
    printf("\033[42m***************** Exercício 1 *****************\033[0m\n");
    Lista *lista1 = criaLista();
    insereFimLista(lista1, 1);
    printf("\033[31mRemovendo um elemento que não está na lista\033[0m\n");
    removeElementoLista(lista1, 2);
    imprimeLista(lista1);
    printf("\033[31mRemovendo o único lista\033[0m\n");
    removeElementoLista(lista1, 1);
    imprimeLista(lista1);
    printf("\033[34mInserindo vários elementos na lista\033[0m\n");
    insereFimLista(lista1, 7);
    insereFimLista(lista1, 1);
    insereFimLista(lista1, 2);
    insereFimLista(lista1, 1);
    insereFimLista(lista1, 1);
    insereFimLista(lista1, 3);
    insereFimLista(lista1, 4);
    insereFimLista(lista1, 1);
    insereFimLista(lista1, 1);
    insereFimLista(lista1, 5);
    imprimeLista(lista1);

    printf("\033[31mRemovendo o primeiro elemento da lista\033[0m\n");
    removeElementoLista(lista1, 7);
    imprimeLista(lista1);

    printf("\033[31mRemovendo o último elemento da lista\033[0m\n");
    removeElementoLista(lista1, 5);
    imprimeLista(lista1);

    printf("\033[31mRemovendo os elemento com valor '1' da lista\033[0m\n");
    removeElementoLista(lista1, 1);
    imprimeLista(lista1);

    liberaLista(lista1);
    /*****************/

    /** Exercicio 2 **/
    // printf("\033[42m***************** Exercício 2 *****************\033[0m\n");
    // Lista *lista2 = criaLista();
    // for(int i = 1; i < 11; i++)
    //     insereFimLista(lista2, i);
    // imprimeLista(lista2);
    // printf("\033[31mRemovendo o 1º nó no da lista\033[0m\n");
    // removePorPosicaoLista(lista2, 1);
    // imprimeLista(lista2);
    // printf("\033[31mRemovendo o 9º nó no da lista\033[0m\n");
    // removePorPosicaoLista(lista2, 9);
    // imprimeLista(lista2);
    // printf("\033[31mRemovendo o 5º nó no da lista\033[0m\n");
    // removePorPosicaoLista(lista2, 5);
    // imprimeLista(lista2);
    // liberaLista(lista2);
    /*****************/

    return 0;
}