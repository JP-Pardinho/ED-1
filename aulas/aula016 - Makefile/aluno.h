#ifndef __ALUNO_H__
#define __ALUNO_H__

/*Inclusão de bibliotecas necessárias para o pacote*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definição de estruturas e declaração de variáveis locais */
typedef struct aluno {
    int id;
    char nome[100];
    char email[200];
    double media;
}Aluno;

/* Cabeçalhos das funções com suas respectivas descrições */

/*
Função: criaAluno
Descrição: Aloca dinamicamente uma estrutura aluno e inicializa os campos com os dados passados como parâmetro.
Entrada:
int id: identificação única do aluno
char *nome: string com o nome do aluno. Tamanho máximo é de 100 caracteres.
char *email: string com o e-mail do aluno. Tamanho máximo é de 200 caracteres.
double media: nota do aluno no semestre.
Saída:
ponteiro para a estrutura Aluno alocada dinâmicamente
*/
Aluno *criaAluno (int id, char *nome, char *email, double media);

/*
Função: destroiAluno
Descrição: libera a memória alocada para a variável passada como parâmetro
Entrada:
a: ponteiro para uma estrutura Aluno
Saída: void
*/
void destroiAluno (Aluno *a);

#endif
