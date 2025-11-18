#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct lista {
    No *inicio;
    No *fim;
    int tamanho;
};

Lista *criaLista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim = NULL; 
    lista->tamanho = 0;    
    return lista;
}

void liberaLista(Lista* lista, void(* LiberarCallback )( void *)) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *t = atual->proximo; /* guarda referência para o próximo elemento */
    
        if (atual->dado)
            LiberarCallback(atual->dado);
    
        free(atual);            /* libera a memória apontada por atual */
        atual = t;              /* faz atual apontar para o próximo */
        lista->tamanho--;
    }
    free(lista);
}


void insereInicioLista(Lista *lista, void *elem) {
    /* Insere um novo elemento no inicio da lista
     *
     * Complexidade: O(1) 
     */

    No *novo = malloc(sizeof(No));
    novo->dado = elem;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    // Caso 1: Lista vazia
    if (listaVazia(lista)) {
        lista->inicio = lista->fim = novo;
    }
    // Caso 2: Lista com elementos
    else {
        lista->inicio->anterior = novo;
        lista->inicio = novo;
    }
    lista->tamanho++;
}

void insereFimLista(Lista *lista, void *elem) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(1) 
     */
    /*****************************************/

    No *novo = malloc(sizeof(No));
    novo->dado = elem;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    
    // Caso 1: Lista vazia
    if (listaVazia(lista)) {
        lista->inicio = lista->fim = novo;
    }
    // Caso 2: Lista com elementos
    else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
}

void imprimeLista(Lista *lista, void(* ImprimeCallback )( void *)){
    /* Imprime os elementos da lista. Note que nessa implementação
     * os valores são impressos enquanto não se atinge o nó 'lista->fim'.
     */
    printf("--- INFORMAÇÃO LISTA DUPLAMENTE ENCADEADA ---\n");
    printf("Tamanho: %d\n", tamanhoLista(lista));
    printf("Elementos: ");
    printf("NULL ⇄ ");
    No *atual = lista->inicio;
    // Enquanto não atingirmos o 'fim' da lista, avançamos. 
    while(atual != lista->fim) {
        ImprimeCallback(atual->dado);
        atual = atual->proximo;
    }
    if (atual) //Imprime a informação do último nó, caso ele exista
        ImprimeCallback(atual->dado);
    printf("NULL\n");
    printf("------------------------\n\n");
}


bool listaVazia(Lista *l){
    /* Verifica se a lista está vazia ou não
     *
     * Complexidade: O(1) 
    */
    return (l == NULL || l->inicio == NULL); // ou return l->tamanho == 0;
}

int tamanhoLista(Lista *lista){
    /* Retorna o número de elementos da lista
     *
     * Complexidade: O(1) 
    */
    return lista->tamanho;
}

No* primeiroNoLista(Lista *lista){
    /* Retorna uma referência para o primeiro no da lista
     *
     * Complexidade: O(1) 
     */
    return lista->inicio;
}

No* ultimoNoLista(Lista *lista){
    /* Retorna uma referência para o último no da lista
     *
     * Complexidade: O(1) 
     */
    return lista->fim;
}

No* procuraLista(Lista *lista, void* valor, int (*CompararCallbak)(void *, void *)){
    /* Retorna uma referência para o nó tal que no->dado == valor
     *
     * Complexidade: O(n) 
     */

    // for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
    //     // Complete
    // }
    No *aux = lista->inicio;
    while(aux != NULL) {

        if (CompararCallbak(aux->dado, valor) == 0) 
            return aux;

        aux = aux->proximo;
    }

    return NULL;
}

No* procuraNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó tal que no == p
     *
     * Complexidade: O(n) 
     */
    for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
         if(aux == p)
            return aux;
    }
    return NULL;
}


void removeElementoLista(Lista *lista, void *valor, int (*CompararCallbak)(void *, void *), void (*LiberarCallback)(void *)) {
    /* Remove todos os nós tal que no->dado == valor
     *
     * Complexidade: O(n)
     */
    
    if (listaVazia(lista))
        return;
    No *atual = lista->inicio;
    
    while (atual != NULL) {

        if (CompararCallbak(atual, lista->fim) == 0) {
            // Caso 1: Único elemento na lista
            if (atual == lista->inicio && atual == lista->fim) {
                lista->inicio = lista->fim = NULL;
                LiberarCallback(atual);
                atual = NULL;
            }
            // Caso 2: Remover o primeiro elemento (mas há mais elementos)
            else if (atual == lista->inicio) {
                lista->inicio = atual->proximo;
                lista->inicio->anterior = NULL;
                No *tmp = atual->proximo;
                LiberarCallback(atual);
                atual = tmp;
            }
            // Caso 3: Remover o último elemento (mas há mais elementos)
            else if (atual == lista->fim) {
                lista->fim = atual->anterior;
                lista->fim->proximo = NULL;
                LiberarCallback(atual);
                atual = NULL;
            }
            // Caso 4: Remover elemento do meio
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                No *tmp = atual->proximo;
                LiberarCallback(atual);
                atual = tmp;
            }
            lista->tamanho--;
        }
        else {
            atual = atual->proximo;
        }
    }
}

void removeNoLista(Lista *lista, No* no) {
    /* Remove o nó referenciado por no
     *
     * Complexidade: O(1)
     *
     * Esta é a grande vantagem da lista duplamente encadeada: remoção em O(1) se já temos o nó!
     */
    if (listaVazia(lista) || no == NULL)
        return;

    // Caso 1: Único elemento
    if (lista->inicio == no && lista->fim == no) {
        lista->inicio = lista->fim = NULL;
    }
    // Caso 2: Primeiro elemento
    else if (no == lista->inicio) {
        lista->inicio = no->proximo;
        lista->inicio->anterior = NULL;
    }
    // Caso 3: Último elemento
    else if (no == lista->fim) {
        lista->fim = no->anterior;
        lista->fim->proximo = NULL;
    }
    // Caso 4: Elemento do meio
    else {
        no->anterior->proximo = no->proximo;
        no->proximo->anterior = no->anterior;
    }
    
    free(no);
    lista->tamanho--;
}
