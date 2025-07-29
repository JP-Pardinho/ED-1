#include "aluno.h"

int main() {
    int identidade;
    char nome[100], email[200];
    double media;
    Aluno *a1 = NULL;
    printf("Digite o id do aluno: ");
    scanf("%d", &identidade);
    printf("Digite o nome do aluno: ");
    getc(stdin);
    scanf("%[^\n]", nome);
    printf("Digite o e-mail do aluno: ");
    getc(stdin);
    scanf("%[^\n]", email);
    printf("Digite a media do aluno: ");
    scanf("%lf", &media);
    a1 = criaAluno(identidade, nome, email, media);
    printf("id: %d\nnome: %s\ne-mail: %s\nmedia: %lf\n", a1->id, a1->nome, a1->email, a1->media);
    destroiAluno(a1);
    printf("\nFim do programa\n");
    return 0;
}