#include <stdio.h>
#include <stdlib.h>

#include "ListaDupla.h"

#define TESTE(condicao, mensagem)                           \
    if (!(condicao)) {                                      \
        printf("❌ \033[31mFALHOU:\033[0m %s\n", mensagem); \
        printf("   Linha: %d\n", __LINE__);                 \
    }                                                       \
    else {                                                  \
        printf("✅ \033[32mPASSOU:\033[0m %s\n", mensagem); \
    }                                                       \

void testeCriacaoELiberacao() {
    printf("\n\033[44m=== Teste: Criação e Liberação ===\033[0m\n");

    ListaDupla *lista = criaListaDupla();
    TESTE(lista != NULL, "Lista criada");
    TESTE(listaDuplaVazia(lista), "Lista inicialmente vazia");
    TESTE(tamanhoListaDupla(lista) == 0, "Tamanho inicial é 0");
    
    liberaListaDupla(lista);
    printf("Lista liberada com sucesso\n");
}

void testeInsercoes() {
    printf("\n\033[44m=== Teste: Inserções ===\033[0m\n");

    ListaDupla *lista = criaListaDupla();
    
    // Testa inserção no início
    insereInicioListaDupla(lista, 10);
    TESTE(tamanhoListaDupla(lista) == 1, "Tamanho após 1 inserção");
    TESTE(primeiroNoListaDupla(lista)->dado == 10, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(lista)->dado == 10, "Último elemento correto");
    
    insereInicioListaDupla(lista, 20);
    insereInicioListaDupla(lista, 30);
    TESTE(tamanhoListaDupla(lista) == 3, "Tamanho após 3 inserções");
    TESTE(primeiroNoListaDupla(lista)->dado == 30, "Ordem de inserção no início");
    
    // Testa inserção no fim
    ListaDupla *lista2 = criaListaDupla();
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 2);
    insereFimListaDupla(lista2, 3);
    TESTE(tamanhoListaDupla(lista2) == 3, "Inserções no fim");
    TESTE(ultimoNoListaDupla(lista2)->dado == 3, "Último elemento no fim");

    No *ultimo = ultimoNoListaDupla(lista2);
    TESTE(ultimo->anterior->dado == 2, "Navegação reversa");

    liberaListaDupla(lista);
    liberaListaDupla(lista2);
}

void testeRemocoes() {
    printf("\n\033[44m=== Teste: Remoções ===\033[0m\n");

    ListaDupla *lista = criaListaDupla();
    
    // Remove de lista vazia
    removeElementoListaDupla(lista, 10);
    TESTE(listaDuplaVazia(lista), "Remover de lista vazia não causa erro");
    
    // Remove único elemento
    insereInicioListaDupla(lista, 10);
    removeElementoListaDupla(lista, 10);
    TESTE(listaDuplaVazia(lista), "Remove único elemento");
    TESTE(tamanhoListaDupla(lista) == 0, "Tamanho 0 após remover único");
    
    // Remove primeiro de vários
    insereFimListaDupla(lista, 1);
    insereFimListaDupla(lista, 2);
    insereFimListaDupla(lista, 3);
    removeElementoListaDupla(lista, 1);
    TESTE(primeiroNoListaDupla(lista)->dado == 2, "Remove primeiro elemento");
    
    // Remove último
    removeElementoListaDupla(lista, 3);
    TESTE(ultimoNoListaDupla(lista)->dado == 2, "Remove último elemento");
    TESTE(tamanhoListaDupla(lista) == 1, "Tamanho correto após remoções");

    // Remove todos os nós
    ListaDupla *lista2 = criaListaDupla();
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 1);
    removeElementoListaDupla(lista2, 1);
    TESTE(tamanhoListaDupla(lista2) == 0, "Tamanho correto após remoções de todos elementos");

    // Remove nó no meio
    insereFimListaDupla(lista2, 2);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 2);
    insereFimListaDupla(lista2, 3);
    insereFimListaDupla(lista2, 2);
    removeElementoListaDupla(lista2, 2);
    TESTE(primeiroNoListaDupla(lista2)->dado == 1, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(lista2)->dado == 3, "Último elemento correto");
    TESTE(tamanhoListaDupla(lista2) == 2, "Tamanho correto após remoções");

    // Remove nó específico usando a função removeNoListaDupla
    insereFimListaDupla(lista2, 2);
    insereFimListaDupla(lista2, 1);
    insereFimListaDupla(lista2, 2);
    No* no = procuraListaDupla(lista2, 2);
    removeNoListaDupla(lista2, no);
    TESTE(primeiroNoListaDupla(lista2)->dado == 1, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(lista2)->dado == 2, "Último elemento correto");
    TESTE(tamanhoListaDupla(lista2) == 4, "Tamanho correto após remoções");

    // Remove o primeiro nó da lista
    removeNoListaDupla(lista2, primeiroNoListaDupla(lista2));
    TESTE(primeiroNoListaDupla(lista2)->dado == 3, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(lista2)->dado == 2, "Último elemento correto");
    TESTE(tamanhoListaDupla(lista2) == 3, "Tamanho correto após remoções");

    liberaListaDupla(lista);
    liberaListaDupla(lista2);
}

// Critérios diferentes
bool ehPar(int n) {
    return n % 2 == 0;
}

bool ehPositivo(int n) {
    return n > 0;
}

bool ehMaiorQueCinco(int n) {
    return n > 5;
}

void testeFuncoesCallback(){
    printf("\n\033[44m=== Teste: Funções Callback ===\033[0m\n");

    ListaDupla *lista = criaListaDupla();
    insereFimListaDupla(lista, -5);
    insereFimListaDupla(lista, 2);
    insereFimListaDupla(lista, -4);
    insereFimListaDupla(lista, 8);
    insereFimListaDupla(lista, 10);
    insereFimListaDupla(lista, 3);
    insereFimListaDupla(lista, 15);
    insereFimListaDupla(lista, -11);
    insereFimListaDupla(lista, 12);
    imprimeListaDupla(lista);

    ListaDupla *listaPar = filtraListaDupla(lista, ehPar);
    imprimeListaDupla(listaPar);
    TESTE(primeiroNoListaDupla(listaPar)->dado == 2, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(listaPar)->dado == 12, "Último elemento correto");
    TESTE(tamanhoListaDupla(listaPar) == 5, "Tamanho correto com a filtragem");

    ListaDupla *listaPositivos = filtraListaDupla(lista, ehPositivo);
    imprimeListaDupla(listaPositivos);
    TESTE(primeiroNoListaDupla(listaPositivos)->dado == 2, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(listaPositivos)->dado == 12, "Último elemento correto");
    TESTE(tamanhoListaDupla(listaPositivos) == 6, "Tamanho correto com a filtragem");

    ListaDupla *listaMaior5 = filtraListaDupla(lista, ehMaiorQueCinco);
    imprimeListaDupla(listaMaior5);
    TESTE(primeiroNoListaDupla(listaMaior5)->dado == 8, "Primeiro elemento correto");
    TESTE(ultimoNoListaDupla(listaMaior5)->dado == 12, "Último elemento correto");
    TESTE(tamanhoListaDupla(listaMaior5) == 4, "Tamanho correto com a filtragem");

    printf("\n");
    TESTE(primeiroNoListaDupla(lista)->dado == -5, "Primeiro elemento da lista original correto");
    TESTE(ultimoNoListaDupla(lista)->dado == 12, "Último elemento da lista original correto");
    TESTE(tamanhoListaDupla(lista) == 9, "Tamanho correto da lista original após as filtragens");

    liberaListaDupla(lista);
    liberaListaDupla(listaPar);
    liberaListaDupla(listaPositivos);
    liberaListaDupla(listaMaior5);
}

int main() {
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   SUITE DE TESTES - LISTAS ENCADEADAS      ║\n");
    printf("╚════════════════════════════════════════════╝\n");

    testeCriacaoELiberacao();
    // testeInsercoes();
    // testeRemocoes();
    // testeFuncoesCallback();

    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║      TODOS OS TESTES EXECUTADOS            ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("\n");
    return 0;
}