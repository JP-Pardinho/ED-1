#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq;
    struct no *dir;
} No;

No *criaNo(int ch)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("\nErro: Nó não alocado");
        exit(1);
    }
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *buscaOrd(No *A, int ch)
{
    No *aux = A;
    if (aux == NULL)
        return NULL;

    if (aux->chave == ch)
        return aux;

    if (aux->chave < ch)
        return (buscaOrd(aux->esq, ch));

    else
        return (buscaOrd(aux->dir, ch));
}

No *insereArvore(No *A, int ch)
{
    if (A == NULL)
    {
        No *novo = criaNo(ch);
        A = novo;
        return A;
    }

    if (A->chave == ch)
    {
        return A;
    }

    if (A->chave < ch)
    {
        A->esq = insereArvore(A->esq, ch);
    }

    else
    {
        A->dir = insereArvore(A->dir, ch);
    }
    return A;
}

void imprimeArvore(No *A, int nivel)
{
    int i = 0;
    if (A == NULL)
        return;

    printf("%d\n", A->chave);

    for (i = 0; i < nivel; i++)
    {
        printf("%d * \t", nivel);
    }
}

int main()
{
    No *arvore = NULL;
    int i = 0;
    int nivel = 5;

    for (i = 0; i < 10; i++)
    {
        arvore = insereArvore(arvore, i);
    }

    imprimeArvore(arvore, nivel);

    return 0;
}