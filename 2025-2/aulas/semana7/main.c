#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Util.h"

#define TESTE(condicao, mensagem)                           \
    if (!(condicao)) {                                      \
        printf("❌ \033[31mFALHOU:\033[0m %s\n", mensagem); \
        printf("   Linha: %d\n", __LINE__);                 \
    }                                                       \
    else {                                                  \
        printf("✅ \033[32mPASSOU:\033[0m %s\n", mensagem); \
    }                                                       \

void testeListaInt() {
    printf("\n\033[44m=== Teste 1: Criando lista de inteiros ===\033[0m\n");

    Lista *listaInt = criaLista();
    TESTE(listaInt != NULL, "Lista criada");
    TESTE(listaVazia(listaInt), "Lista inicialmente vazia");
    TESTE(tamanhoLista(listaInt) == 0, "Tamanho inicial é 0");
    // Inserindo valores no fim
    for (int i = 1; i <= 5; i++) {
        int *valor = (int*)malloc(sizeof(int));
        *valor = i;
        insereInicioLista(listaInt, valor);
    }
    // Inserindo valores no fim
    for (int i = 11; i <= 15; i++) {
        int *valor = (int*)malloc(sizeof(int));
        *valor = i;
        insereFimLista(listaInt, valor);
    }
    TESTE(tamanhoLista(listaInt) == 10, "Tamanho final é 10");
    imprimeLista(listaInt, imprimirInt);

    liberaLista(listaInt, liberarInt);
}

void testeListaString() {
    printf("\n\033[44m=== Teste 2: Criando lista de Strings ===\033[0m\n");

    Lista *listaStr = criaLista();
    // Inserindo valores no fim
    insereFimLista(listaStr, criarString("João Silva"));
    insereFimLista(listaStr, criarString("Maria Santos"));
    insereFimLista(listaStr, criarString("Pedro Oliveira"));
    insereFimLista(listaStr, criarString("Ana Carolina de Souza e Silva"));

    imprimeLista(listaStr, imprimirString);

    liberaLista(listaStr, liberarString);
}

/* Exercício 5 */
void testeListaAluno() {
    printf("\n\033[44m=== Teste 3: Criando lista de Alunos ===\033[0m\n");

    Lista *listaAluno = criaLista();
    // Inserindo valores no fim
    insereFimLista(listaAluno, criarAluno(101, "João Silva", 8.5));
    insereFimLista(listaAluno, criarAluno(102, "Maria Santos", 9.2));
    insereFimLista(listaAluno, criarAluno(103, "Pedro Oliveira", 7.8));
    insereFimLista(listaAluno, criarAluno(104, "Ana Carolina de Souza e Silva", 9.5));

    imprimeLista(listaAluno, imprimirAluno);

    liberaLista(listaAluno, liberarAluno);
}

/* Exercício 6 */
void testeBusca() {
    printf("\n\033[44m=== Teste 4: Buscando elementos na lista ===\033[0m\n");

    Lista *listaInt = criaLista();
    for (int i = 1; i <= 5; i++) {
        int *valor = (int*)malloc(sizeof(int));
        *valor = i;
        insereFimLista(listaInt, valor);
    }
    int valor = 5;
    TESTE(procuraLista(listaInt, &valor, compararInt) !=  NULL, "Busca por elemento presente na listaInt");
    valor = 15;
    TESTE(procuraLista(listaInt, &valor, compararInt) == NULL, "Busca por elemento que não está na listaInt");

    Lista *listaStr = criaLista();
    insereFimLista(listaStr, criarString("João Silva"));
    insereFimLista(listaStr, criarString("Maria Santos"));
    insereFimLista(listaStr, criarString("Pedro Oliveira"));
    insereFimLista(listaStr, criarString("Ana Carolina de Souza e Silva"));
    char *nome = "Maria Santos";
    TESTE(procuraLista(listaStr, nome, compararString) != NULL, "Busca por elemento presente na listaStr");
    nome = "Ana Paula";
    TESTE(procuraLista(listaStr, nome, compararString) == NULL, "Busca por elemento que não está na listaStr");

    Lista *listaAluno = criaLista();
    insereFimLista(listaAluno, criarAluno(101, "João Silva", 8.5));
    insereFimLista(listaAluno, criarAluno(102, "Maria Santos", 9.2));
    insereFimLista(listaAluno, criarAluno(103, "Pedro Oliveira", 7.8));
    insereFimLista(listaAluno, criarAluno(104, "Ana Carolina de Souza e Silva", 9.5));
    Aluno aluno1 = {101, "João Silva", 8.5};
    TESTE(procuraLista(listaAluno, &aluno1, compararString) != NULL, "Busca por elemento presente na listaAluno");
    Aluno aluno2 = {105, "João Paulo", 8.0};
    TESTE(procuraLista(listaAluno, &aluno2, compararString) == NULL, "Busca por elemento que não está na listaAluno");

    liberaLista(listaInt, liberarInt);
    liberaLista(listaStr, liberarString);
    liberaLista(listaAluno, liberarAluno);
}

/* Exercício 7 */
void testeRemocoes() {
    printf("\n\033[44m=== Teste 5: Removendo elementos da lista ===\033[0m\n");

    Lista *listaInt = criaLista();
    for (int i = 1; i <= 5; i++) {
        int *valor = (int*)malloc(sizeof(int));
        *valor = i;
        insereFimLista(listaInt, valor);
    }
    imprimeLista(listaInt, imprimirInt);
    int valor = 5;
    printf("Removendo: %d\n", valor);
    removeElementoLista(listaInt, &valor, compararInt, liberarInt);
    TESTE(tamanhoLista(listaInt) == 4, "Remover um elemento presente na listaInt");
    valor = 15;
    printf("Removendo: %d\n", valor);
    removeElementoLista(listaInt, &valor, compararInt, liberarInt);
    TESTE(tamanhoLista(listaInt) == 4, "Remover um elemento que não está na listaInt");

    Lista *listaStr = criaLista();
    insereFimLista(listaStr, criarString("João Silva"));
    insereFimLista(listaStr, criarString("Maria Santos"));
    insereFimLista(listaStr, criarString("Pedro Oliveira"));
    insereFimLista(listaStr, criarString("Ana Carolina de Souza e Silva"));
    imprimeLista(listaStr, imprimirString);
    char *nome = "Maria Santos";
    printf("Removendo: %s\n", nome);
    removeElementoLista(listaStr, nome, compararString, liberarString);
    TESTE(tamanhoLista(listaStr) == 3, "Remover um elemento presente na listaStr");
    nome = "Ana Paula";
    printf("Removendo: %s\n", nome);
    removeElementoLista(listaStr, nome, compararString, liberarString);
    TESTE(tamanhoLista(listaStr) == 3, "Remover um elemento que não está na listaStr");

    Lista *listaAluno = criaLista();
    insereFimLista(listaAluno, criarAluno(101, "João Silva", 8.5));
    insereFimLista(listaAluno, criarAluno(102, "Maria Santos", 9.2));
    insereFimLista(listaAluno, criarAluno(103, "Pedro Oliveira", 7.8));
    insereFimLista(listaAluno, criarAluno(104, "Ana Carolina de Souza e Silva", 9.5));
    Aluno aluno1 = {101, "João Silva", 8.5};
    printf("Removendo: ");
    imprimirAluno(&aluno1);
    printf("\n");
    removeElementoLista(listaAluno, &aluno1, compararAluno, liberarAluno);
    TESTE(tamanhoLista(listaAluno) == 3, "Remover um elemento presente na listaAluno");
    Aluno aluno2 = {105, "João Paulo", 8.0};
    printf("Removendo: ");
    imprimirAluno(&aluno2);
    printf("\n");
    removeElementoLista(listaAluno, &aluno2, compararAluno, liberarAluno);
    TESTE(tamanhoLista(listaAluno) == 3, "Remover um elemento que não está na listaAluno");

    liberaLista(listaInt, liberarInt);
    liberaLista(listaStr, liberarString);
    liberaLista(listaAluno, liberarAluno);
}

int main() {
    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║   SUITE DE TESTES - LISTAS ENCADEADAS      ║\n");
    printf("╚════════════════════════════════════════════╝\n");

    testeListaInt();
    testeListaString();
    testeListaAluno();
    testeBusca();
    testeRemocoes();


    printf("\n");
    printf("╔════════════════════════════════════════════╗\n");
    printf("║      TODOS OS TESTES EXECUTADOS            ║\n");
    printf("╚════════════════════════════════════════════╝\n");
    printf("\n");
    return 0;
}