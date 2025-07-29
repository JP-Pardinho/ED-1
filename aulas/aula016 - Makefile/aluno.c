#include "aluno.h"

Aluno *criaAluno (int id, char *nome, char *email, double media){
    Aluno *novo = (Aluno *) malloc (sizeof(Aluno));
    if (!novo) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    novo->id = id;
    strcpy(novo->nome, nome);
    strcpy(novo->email, email);
    novo->media = media;

    return novo;
}

void destroiAluno (Aluno *a){
    free(a);
}
