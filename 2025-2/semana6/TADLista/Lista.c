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

void liberaLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* t = atual->proximo; /* guarda referência para o próximo elemento */
        free(atual);            /* libera a memória apontada por atual */
        atual = t;              /* faz atual apontar para o próximo */
    }
    free(lista);
    lista = NULL;
}

void insereInicioLista(Lista *lista, int elem) {
    /* Insere um novo elemento no inicio da lista
     *
     * Complexidade: O(1) 
     */
    No *no = malloc(sizeof(No));
    no->dado = elem;
    no->proximo = lista->inicio;
    if(listaVazia(lista))
        lista->fim = no;   
    lista->inicio = no;
    lista->tamanho++; 
}

void insereFimLista(Lista *lista, int elem) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(1) 
     */
    /*****************************************/
    No *novo = malloc(sizeof(No));
    novo->dado = elem;
    novo->proximo = NULL;
    if(listaVazia(lista)) {
        lista->inicio = lista->fim = novo;
    }
    else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
}

void imprimeLista(Lista *lista){
    /* Imprime os elementos da lista. Note que nessa implementação
     * os valores são impressos enquanto não se atinge o nó 'lista->fim'.
     */
    printf("--- INFORMAÇÃO LISTA ---\n");
    printf("Tamanho: %d\n", tamanhoLista(lista));
    printf("Elementos: ");
    No *atual = lista->inicio;
    // Enquanto não atingirmos o 'fim' da lista, avançamos. 
    while(atual != lista->fim) {
    	printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    if (atual) //Imprime a informação do último nó, caso ele exista
        printf("%d -> ", atual->dado);
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

No* procuraLista(Lista *lista, int valor){
    /* Retorna uma referência para o nó tal que no->dado == valor
     *
     * Complexidade: O(n) 
     */
    for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
         if(aux->dado == valor)
            return aux;
    }
    return NULL;
}

No* procuraNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó tal que no == p
     *
     * Complexidade: O(??) 
     */
    for(No *aux = lista->inicio; aux != NULL; aux = aux->proximo) {
         if(aux == p)
            return aux;
    }
    return NULL;
}

No* n_esimo(Lista *lista, int n) {
    /* Retorna uma referência para o n-esimo nó da lista
     *
     * Complexidade: O(n) 
     */
    No *p = lista->inicio;
    int j=1;
    while (p->proximo && j < n) {  
	    p = p->proximo;
        j++;
    }
    if (j == n) 
	    return p;
    else 
        return NULL;
}

No* proximoNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó posterior àquele referenciado por p
     *
     * Complexidade: O(n) 
     */
    if (listaVazia(lista))
        return NULL;

    /* Como não há garantia que o nó esteja na lista, devemos fazer uma busca pelo nó */
    /* Você deve utilizar a função procuraNoLista */
    No *atual = procuraNoLista(lista, p);
    if (atual == NULL) { // Nó não encontrado
        return NULL;
    }
    return atual->proximo;
}

No* anteriorNoLista(Lista *lista, No *p){
    /* Retorna uma referência para o nó anterior àquele referenciado por p
     *
     * Complexidade: O(n) 
     */
    if (listaVazia(lista))
        return NULL;
    No *aux = lista->inicio;
    No *anterior = NULL;
    while (aux != p) {
        anterior = aux;
        aux = aux->proximo;
    }
    return anterior;
}

void removeElementoLista(Lista *lista, int valor){
    /* Remove todos os nós tal que no->dado == valor
     *
     * Complexidade: O(n) 
     */
    if (listaVazia(lista))
        return;
    No *atual = lista->inicio;
    No *anterior = NULL;
    while(atual != NULL){
        if(atual->dado == valor) {
            // Caso 1: único elemento
            if (atual == lista->inicio && atual == lista->fim) { 
                free(atual);
                lista->inicio = NULL;
                lista->fim = NULL;
                atual = NULL;
            }
            // Caso 2: primeiro elemento
            else if(atual == lista->inicio) {
                lista->inicio = atual->proximo;
                free(atual);
            }
            // Caso 3: último elemento
            else if (atual == lista->fim) {
                lista->fim = anterior;
                anterior->proximo = NULL;
                free(atual);
            }
            // Caso 4: elemento do meio
            else { // O elemento está no meio da lista
                anterior->proximo = atual->proximo;
                free(atual);
                atual = anterior->proximo;
            }
            lista->tamanho--; 
        }
        else{
            anterior = atual;
            atual = atual->proximo;
        }
    } 
}

void removeNoLista(Lista *lista, No* p) {
    /* Remove o nó referenciado por p
     *
     * Note que precisamos encontrar o nó anterior para conseguirmos remover o nó passado como parâmetro
     * Complexidade: O(n)
     */
    if (listaVazia(lista))
        return;
    No *atual = lista->inicio;
    No *anterior = NULL;
    while (atual && atual != p){
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) { // Nó não encontrado
        return;
    }
    if (atual == lista->inicio && atual == lista->fim) {
        lista->inicio = lista->fim = NULL;
        free(atual);
    }
    else if (atual == lista->inicio) { // Nó 'p' é o primeiro
        lista->inicio = atual->proximo;
        free(atual);
    }
    else if (atual == lista->fim) { // Nó 'p' é o último
        anterior->proximo = NULL;
        lista->fim = anterior;
        free(atual);
    }
    else { // Nó 'p' é um nó intermediário
        anterior->proximo = atual->proximo;
        free(atual);
    }
    lista->tamanho--; 
}

bool removePorPosicaoLista(Lista *lista, int pos) {
    /* Remove o elemento na posição 'pos' (começando de 1)
     * Retorna true se conseguiu remover, false caso contrário
     *
     * Complexidade: O(??)
     */

    // Valida se a posição é válida
    if (listaVazia(lista) || pos < 1 || pos > lista->tamanho)
        return false;
    
    No *atual = lista->inicio;
    No *anterior = NULL;
    int contador = 1;
    
    /*
    // Percorre até a posição desejada
    //Complete
    
    // Remove o nó na posição encontrada
    // Caso 1: único elemento (pos == 1 e tamanho == 1)
    if (atual == lista->inicio && atual == lista->fim) {
        // Complete
    }
    // Caso 2: primeiro elemento
    else if (atual == lista->inicio) {
        // Complete
    }
    // Caso 3: último elemento
    else if (atual == lista->fim) {
        // Complete
    }
    // Caso 4: elemento do meio
    else
        // Complete

    // Complete

    return true;
    */
}
