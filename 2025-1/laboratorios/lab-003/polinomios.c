#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int base;
    int expoente;
    struct No *prox;
} No;

No *criaNo(int valorBase, int valorExp)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro: Alocação deu errado!\n");
        exit(1);
    }
    else
    {
        novo->base = valorBase;
        novo->expoente = valorExp;
        novo->prox = NULL;
        return novo;
    }
}

No *insereDecrescente(No *lista, int valorBase, int valorExp)
{
    No *aux = lista, *pred = NULL;
    No *novo = criaNo(valorBase, valorExp);
    if (lista == NULL)
    {
        lista = novo;
        return lista;
    }
    else
    {
        while (aux != NULL && valorExp < aux->expoente && valorBase != 0)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL)
        {
            novo->prox = aux;
            lista = novo;
        }
        else
        {
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return lista;
}

No *somaPolinomios(No *lista1, No *lista2)
{
    No *aux1 = lista1;
    No *aux2 = lista2;
    No *resultado = NULL;
    int soma = 0;

    if (aux1 == NULL)
    {
        resultado = lista2;
        return resultado;
    }
    else if (aux2 == NULL)
    {
        resultado = lista1;
        return resultado;
    }
    else
    {
        while (aux1 != NULL || aux2 != NULL)
        {
            if (aux1 != NULL && (aux2 == NULL || aux1->expoente > aux2->expoente))
            {
                insereDecrescente(resultado, aux1->base, aux1->expoente);
                aux1 = aux1->prox;
            }
            else if (aux2 != NULL && (aux1 == NULL || aux2->expoente > aux1->expoente))
            {
                insereDecrescente(resultado, aux2->base, aux2->expoente);
                aux2 = aux2->prox;
            }
            else
            {
                soma = aux1->base + aux2->base;
                if (soma != 0)
                {
                    resultado = insereDecrescente(resultado, soma, aux1->expoente);
                }
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
        }
    }
    return resultado;
}

No *subtraiPolinomios(No *lista1, No *lista2)
{
    No *aux1 = lista1;
    No *aux2 = lista2;
    No *resultado = NULL;
    int sub = 0;

    if (aux1 == NULL)
    {
        resultado = lista2;
        return resultado;
    }
    else if (aux2 == NULL)
    {
        resultado = lista1;
        return resultado;
    }
    else
    {
        while (aux1 != NULL || aux2 != NULL)
        {
            if (aux1 != NULL && (aux2 == NULL || aux1->expoente > aux2->expoente))
            {
                resultado = insereDecrescente(resultado, aux1->base, aux1->expoente);
                aux1 = aux1->prox;
            }
            else if (aux2 != NULL && (aux1 == NULL || aux2->expoente > aux1->expoente))
            {
                resultado = insereDecrescente(resultado, -aux2->base, aux2->expoente);
                aux2 = aux2->prox;
            }
            else
            {
                sub = aux1->base - aux2->base;
                if (sub != 0)
                {
                    resultado = insereDecrescente(resultado, sub, aux1->expoente);
                }
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
        }
    }
    return resultado;
}

void imprimeLista(No *lista)
{
    No *aux = lista;
    while (aux != NULL)
    {
        printf("%dx^%d ", aux->base, aux->expoente);
        if (aux->prox != NULL)
        {
            printf("+ ");
        }
        aux = aux->prox;
    }
    printf("\n\n");
}

No *multiplicarPolinomios(No *lista1, No *lista2)
{
    No *aux1 = lista1;
    No *aux2 = lista2;
    No *resultado = NULL;
    int mult = 0, soma = 0;

    if (aux1 == NULL)
    {
        return 0;
    }
    else if (aux2 == NULL)
    {
        return 0;
    }
    else
    {
        while (aux1 != NULL)
        {
            aux2 = lista2;
            while (aux2 != NULL)
            {
                if (aux1->base != 0 && aux2->base != 0)
                {
                    mult = aux1->base * aux2->base;
                    soma = aux1->expoente + aux2->expoente;
                    resultado = insereDecrescente(resultado, mult, soma);
                    ;
                    aux2 = aux2->prox;
                }
                aux1 = aux1->prox;
            }
        }
    }
    return resultado;
}

void liberaLista(No *lista)
{
    No *aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

int main()
{
    int base, expo, op, qnt;
    int i = 0;
    No *lista1 = NULL;
    No *lista2 = NULL;
    No *resultado = NULL;

    do
    {
        printf("Escolha o que gostaria de fazer: \n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicação\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nSomando: \n");
            printf("A lista 1 tem quantos elementos: ");
            scanf("%d", &qnt);
            for (i = 0; i < qnt; i++)
            {
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite a expoente: ");
                scanf("%d", &expo);
                lista1 = insereDecrescente(lista1, base, expo);
            }
            printf("A lista 2 tem quantos elementos: ");
            scanf("%d", &qnt);
            for (i = 0; i < qnt; i++)
            {
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite a expoente: ");
                scanf("%d", &expo);
                lista2 = insereDecrescente(lista2, base, expo);
            }

            printf("\nResoltado soma: \n");
            resultado = somaPolinomios(lista1, lista2);
            imprimeLista(resultado);

            liberaLista(lista1);
            liberaLista(lista2);
            liberaLista(resultado);
            lista1 = lista2 = resultado = NULL;
            break;

        case 2:
            printf("\nSubtraindo: \n");
            printf("A lista 1 tem quantos elementos: ");
            scanf("%d", &qnt);
            for (i = 0; i < qnt; i++)
            {
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente: ");
                scanf("%d", &expo);
                lista1 = insereDecrescente(lista1, base, expo);
            }
            printf("A lista 2 tem quantos elementos: ");
            scanf("%d", &qnt);
            for (i = 0; i < qnt; i++)
            {
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente: ");
                scanf("%d", &expo);
                lista2 = insereDecrescente(lista2, base, expo);
            }
            printf("\nResultado subtrabção: \n");
            resultado = subtraiPolinomios(lista1, lista2);
            imprimeLista(resultado);

            liberaLista(lista1);
            liberaLista(lista2);
            liberaLista(resultado);
            lista1 = lista2 = resultado = NULL;
            break;

        case 3:
            printf("\nMultiplicando: \n");
            printf("A lista 1 tem quantos elementos: ");
            scanf("%d", &qnt);

            for (i = 0; i < qnt; i++)
            {
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente: ");
                scanf("%d", &expo);
                lista1 = insereDecrescente(lista1, base, expo);
            }
            printf("A lista 2 tem quantos elementos: ");
            scanf("%d", &qnt);

            for (i = 0; i < qnt; i++)
            {
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente: ");
                scanf("%d", &expo);
                lista2 = insereDecrescente(lista2, base, expo);
            }
            resultado = multiplicarPolinomios(lista1, lista2);
            imprimeLista(resultado);

            liberaLista(lista1);
            liberaLista(lista2);
            liberaLista(resultado);
            lista1 = lista2 = resultado = NULL;
            break;

        case 4:
            break;

        default:
            break;
        }

    } while (op != 4);

    free(lista1);
    free(lista2);
    free(resultado);
    return 0;
}