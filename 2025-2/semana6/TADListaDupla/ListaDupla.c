#include <stdio.h>
#include <stdlib.h>

#include "ListaDupla.h"

struct listaDupla {
    No *inicio;
    No *fim;
    int tamanho;
};

ListaDupla *criaListaDupla() {
    ListaDupla *lista = malloc(sizeof(ListaDupla));
    lista->inicio = NULL;
    lista->fim = NULL; 
    lista->tamanho = 0;    
    return lista;
}

void liberaListaDupla(ListaDupla* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* t = atual->proximo; /* guarda referência para o próximo elemento */
        free(atual);            /* libera a memória apontada por atual */
        atual = t;              /* faz atual apontar para o próximo */
    }
    free(lista);
}

void insereInicioListaDupla(ListaDupla *lista, int elem) {
    /* Insere um novo elemento no inicio da lista
     *
     * Complexidade: O(1) 
     */

    // TODO: Complete a inserção
    // Lembre-se de:
    // 1. Tratar o caso de lista vazia
    // 2. Atualizar novo->proximo
    // 3. Atualizar o anterior do antigo primeiro nó
    // 4. Atualizar lista->inicio
    // 5. Incrementar tamanho

    No *novo = malloc(sizeof(No));
    // Complete

    // Caso 1: ListaDupla vazia
    if (listaDuplaVazia(lista)) {
        // Complete
    }
    // Caso 2: ListaDupla com elementos
    else {
        // Complete
    }
    // Complete
}

void insereFimListaDupla(ListaDupla *lista, int elem) {
    /* Insere um novo elemento no fim da lista
     *
     * Complexidade: O(??) 
     */
    /*****************************************/

    // TODO: Implemente (similar ao início, mas ajustando fim)

    No *novo = malloc(sizeof(No));
    // Complete

    // Caso 1: ListaDupla vazia
    if (listaDuplaVazia(lista)) {
        // Complete
    }
    // Caso 2: ListaDupla com elementos
    else {
        // Complete
    }
    // Complete
}

void imprimeListaDupla(ListaDupla *lista){
    /* Imprime os elementos da lista. Note que nessa implementação
     * os valores são impressos enquanto não se atinge o nó 'lista->fim'.
     */
    printf("--- INFORMAÇÃO LISTA DUPLAMENTE ENCADEADA ---\n");
    printf("Tamanho: %d\n", tamanhoListaDupla(lista));
    printf("Elementos: ");
    printf("NULL ⇄ ");
    No *atual = lista->inicio;
    // Enquanto não atingirmos o 'fim' da lista, avançamos. 
    while(atual != lista->fim) {
        printf("%d ⇄ ", atual->dado);
        atual = atual->proximo;
    }
    if (atual) //Imprime a informação do último nó, caso ele exista
        printf("%d ⇄ ", atual->dado);
    printf("NULL\n");
    printf("------------------------\n\n");
}

bool listaDuplaVazia(ListaDupla *l){
    /* Verifica se a lista está vazia ou não
     *
     * Complexidade: O(1) 
    */
    return (l == NULL || l->inicio == NULL); // ou return l->tamanho == 0;
}

int tamanhoListaDupla(ListaDupla *lista){
    /* Retorna o número de elementos da lista
     *
     * Complexidade: O(1) 
    */
    return lista->tamanho;
}

No* primeiroNoListaDupla(ListaDupla *lista){
    /* Retorna uma referência para o primeiro no da lista
     *
     * Complexidade: O(1) 
     */
    return lista->inicio;
}

No* ultimoNoListaDupla(ListaDupla *lista){
    /* Retorna uma referência para o último no da lista
     *
     * Complexidade: O(1) 
     */
    return lista->fim;
}

No* procuraListaDupla(ListaDupla *lista, int valor){
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

No* procuraNoListaDupla(ListaDupla *lista, No *p){
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


void removeElementoListaDupla(ListaDupla *lista, int valor){
    /* Remove todos os nós tal que no->dado == valor
     * Em lista duplamente encadeada, a remoção é mais simples
     * pois não precisamos buscar o nó anterior
     *
     * Complexidade: O(n)
     */
    
    if (listaDuplaVazia(lista))
        return;
    No *atual = lista->inicio;
    
    while (atual != NULL) {
        if (atual->dado == valor) {
            // Caso 1: Único elemento na lista
            if (atual == lista->inicio && atual == lista->fim) {
                //Complete
            }
            // Caso 2: Remover o primeiro elemento (mas há mais elementos)
            else if (atual == lista->inicio) {
                // Complete
            }
            // Caso 3: Remover o último elemento (mas há mais elementos)
            else if (atual == lista->fim) {
                // Complete
            }
            // Caso 4: Remover elemento do meio
            else {
                // Complete
            }
            lista->tamanho--;
        }
        else {
            // Complete
        }
    }
}

void removeNoListaDupla(ListaDupla *lista, No* no) {
    /* Remove o nó referenciado por no
     *
     * Complexidade: O(1)
     *
     * Esta é a grande vantagem da lista duplamente encadeada: remoção em O(1) se já temos o nó!
     */
    if (listaDuplaVazia(lista) || no == NULL)
        return;

    // TODO: Implemente considerando 4 casos:
    
    // 1. Único elemento
    if (lista->inicio == no && lista->fim == no) {
        // Complete
    }
    // 2. Primeiro elemento
    else if (no == lista->inicio) {
        // Complete
    }
    // 3. Último elemento
    else if (no == lista->fim) {
        // Complete
    }
    // 4. Elemento do meio
    else {
        // Complete
    }

    // Complete
}

ListaDupla *filtraListaDupla(ListaDupla *lista, bool (*compara)(int)){
    /* Cria uma nova lista apenas com elementos que satisfazem
     * a condição passada como parâmetro
     * 
     * Perceba que esta função é uma função de alta ordem, ou seja, uma função
     * que recebe função(ões) como parâmetros.
     *
     * Complexidade: O(n)
     */

    ListaDupla* novaLista = criaListaDupla();

    // Complete
    
    return novaLista;
}