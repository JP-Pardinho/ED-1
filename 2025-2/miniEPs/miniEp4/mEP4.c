#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

Lista *juntaLista(Lista *l1, Lista *l2) {
    Lista *resultado = criaLista();
    /*
     * Sua tarefa é, entre outras, implementar o código dessa função que junta duas listas ordenadas de forma que 
     * a lista resultante ('resultado') esteja ordenada.
     * Os elementos de l1 e l2, se existirem, sempre estarão ordenados (do menor para o maior de acordo com a id do nó).
     *
     * Lembre-se que você não pode fazer alocação dinâmica/estática de novos nós (usando malloc), mas você pode
     * criar novos ponteiros para os nós das listas. Além disso, com exceção da função criaLista, a função
     * juntaLista não pode utilizar/chamar outras funções do TAD Lista, ou seja, todo o código de manipulação dos 
     * elementos da lista devem ser feitos dentro da função juntaLista.
     * 
     * A função deve ter complexidade O(n)
     *  
     * Exemplos de entrada: 
     * l1 = 1->2->5->10 
     * l2 = 3->7->8->11
     * Resultado esperado:
     * resultado = 1->2->3->5->7->8->10->11
    */

    No *aux1 = l1->inicio;
    No *aux2 = l2->inicio;

    if (aux1 == NULL) {
        resultado->inicio = aux2;
        resultado->fim = l2->fim;
        l2->inicio = NULL;
        l2->fim = NULL;
        return resultado;
    }
    if (aux2 == NULL) {
        resultado->inicio = aux1;
        resultado->fim = l1->fim;
        l1->inicio = NULL;
        l1->fim = NULL;
        return resultado;
    }

    if (aux1->id < aux2->id) {
        resultado->inicio = aux1;
        resultado->fim = aux1;
        aux1 = aux1->proximo;
    }
    else {
        resultado->inicio = aux2;
        resultado->fim = aux2;
        aux2 = aux2->proximo;
    }

    while (aux1 != NULL && aux2 != NULL) {
        
        if (aux1->id < aux2->id) {
            resultado->fim->proximo = aux1;
            resultado->fim = aux1;
            aux1 = aux1->proximo;
        } else {
            resultado->fim->proximo = aux2;
            resultado->fim = aux2;
            aux2 = aux2->proximo;
        }
    }   
    
    if (aux1 != NULL) {
        resultado->fim->proximo = aux1;
        resultado->fim = l1->fim; 
    } else {
        resultado->fim->proximo = aux2;
        resultado->fim = l2->fim;
    }

    l1->inicio = NULL;
    l1->fim = NULL;
    l2->inicio = NULL;
    l2->fim = NULL;

    return resultado;
}
