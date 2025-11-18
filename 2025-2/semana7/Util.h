#ifndef __UTIL_H_
#define __UTIL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*-------------- INTEIROS --------------*/
// Função para comparar inteiros
int compararInt(void *a, void *b) {
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa - *pb);
}

// Função para imprimir inteiros
void imprimirInt(void *dado) {
    int *valor = (int*)dado;
    printf("%d ⇄ ", *valor);
}

// Função para liberar inteiros
void liberarInt(void *dado) {
    free(dado);
}

/*-------------- STRING --------------*/

// Função para alocar strings
char *criarString(char *str){
    char *palavra = (char *)malloc(strlen(str) + 1);
    strcpy(palavra, str);
    return palavra;
}

// Função para comparar strings
int compararString(void *a, void *b) {
    char *sa = (char*)a;
    char *sb = (char*)b;
    return strcmp(sa, sb);
}

// Função para imprimir strings
void imprimirString(void *dado) {
    char *str = (char*)dado;
    printf("\"%s\" ⇄ ", str);
}

// Função para liberar strings
void liberarString(void *dado) {
    free(dado);
}

/*-------------- ALUNO --------------*/

// Definição de um struct Aluno com nome dinâmico
typedef struct {
    int matricula;
    char *nome;  // Ponteiro para string alocada dinamicamente
    double nota;
} Aluno;

// Função auxiliar para criar um aluno
Aluno* criarAluno(int matricula, const char *nome, double nota) {
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    if (aluno == NULL) {
        return NULL;
    }
    
    aluno->matricula = matricula;
    
    // Aloca memória para o nome
    aluno->nome = (char*)malloc(strlen(nome) + 1);
    if (aluno->nome == NULL) {
        free(aluno);
        return NULL;
    }
    strcpy(aluno->nome, nome);
    
    aluno->nota = nota;
    return aluno;
}

// Função para comparar alunos por matrícula
int compararAluno(void *a, void *b) {
    Aluno *pa = (Aluno*)a;
    Aluno *pb = (Aluno*)b;
    return pa->matricula - pb->matricula;
}

// Função para imprimir alunos
void imprimirAluno(void *dado) {
    Aluno *aluno = (Aluno*)dado;
    printf("\n\t{Mat: %d, Nome: %s, Nota: %.2lf} ⇄ ", aluno->matricula, aluno->nome, aluno->nota);
}

// Função para liberar alunos (libera o nome E o struct)
void liberarAluno(void *dado) {
    if (dado == NULL) {
        return;
    }
    
    Aluno *aluno = (Aluno*)dado;
    
    // Primeiro libera o nome (alocado dinamicamente)
    if (aluno->nome != NULL) {
        free(aluno->nome);
    }
    
    // Depois libera o struct do aluno
    free(aluno);
}

#endif
