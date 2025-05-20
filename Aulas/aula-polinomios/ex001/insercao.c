#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int base;
    int expoente;
    struct No *prox; 
} No;

No *criaNo(int valorBase, int valorExp){
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro: Alocação deu errado!\n");
        exit(1);
    } else{
        novo->base = valorBase;
        novo->expoente = valorExp;
        novo->prox = NULL;
        return novo;
    }
}

No *insereDecrescente(No *lista, int valorBase, int valorExp){
    No *aux = lista, *pred = NULL;
    No *novo = criaNo(valorBase, valorExp);
    if (lista == NULL){
        lista = novo;
        return lista;
    } else{
        while (aux != NULL && valorExp < aux->expoente){
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            novo->prox = aux;
            lista = novo;
        } else {
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return lista;
}

No *somaPolinomios(No *lista1, No *lista2){
    No *aux1 = lista1;
    No *aux2 = lista2;
    No *resultado = NULL;

    if (aux1 == NULL){
        resultado = lista2;
        return resultado;
    } else{
        resultado = lista1;
        return resultado;
    }

    if(aux1->expoente > aux2->expoente){
        resultado = criaNo(aux1->base,aux1->expoente);
    } else{
        resultado = criaNo(aux2->base,aux2->expoente);
    }

    while(aux1 != NULL || aux2 != NULL){

        if(aux1->expoente == aux2->expoente){          
            if (!(aux1->base + aux2->base) == 0){
                insereDecrescente(resultado, (aux1->base + aux2->base), aux1->expoente);
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        } else {
            if(aux1->expoente > aux2->expoente){
                insereDecrescente(resultado, aux1->base, aux1->expoente);
            } else {
                insereDecrescente(resultado, aux2->base, aux2->expoente);
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
    }
    return resultado;
}

No *subtraiPolinomios(No *lista1, No *lista2){
    No *aux1 = lista1;
    No *aux2 = lista2;
    No *resultado = NULL;

    if (aux1 == NULL){
        resultado = lista2;
        return resultado;
    } else{
        resultado = lista1;
        return resultado;
    }

    if(aux1->expoente > aux2->expoente){
        resultado = criaNo(aux1->base,aux1->expoente);
    } else{
        resultado = criaNo(aux2->base,aux2->expoente);
    }

    while(aux1 != NULL || aux2 != NULL){

        if(aux1->expoente == aux2->expoente){          
            if (!(aux1->base - aux2->base) == 0){
                insereDecrescente(resultado, (aux1->base - aux2->base), aux1->expoente);
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        } else {
            if(aux1->expoente > aux2->expoente){
                insereDecrescente(resultado, aux1->base, aux1->expoente);
            } else {
                insereDecrescente(resultado, aux2->base, aux2->expoente);
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
    }
    return resultado;
}

void imprimeLista(No *lista){
    No *aux = lista;
    while (aux != NULL){
        printf("%d ", aux->base);
        printf("%d \n", aux->expoente);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    int base, expo, op;
    int i = 0;
    No *lista1 = NULL;
    No *lista2 = NULL;
    No *resultado = NULL;

    
    do
    {
        printf("Escolha o que gostaria de fazer: \n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        
        switch (op){
            case 1:
                printf("Somando: \n");
                printf("Lista 1: \n");
                for (i = 0; i < 5; i++){
                    printf("Digite a base: ");
                    scanf("%d", &base);
                    printf("Digite a expoente: ");
                    scanf("%d", &expo);
                    lista1 = insereDecrescente(lista1, base, expo);
                }
                printf("\n");    
                printf("Lista 2: \n");
                for (i = 0; i < 5; i++){
                    printf("Digite a base: ");
                    scanf("%d", &base);
                    printf("Digite a expoente: ");
                    scanf("%d", &expo);
                    lista2 = insereDecrescente(lista2, base, expo);
                }

                resultado = somaPolinomios(lista1, lista2);
                imprimeLista(resultado);
            break;
        
        case 2:
            printf("Subtraindo: \n");
            for (i=0; i<5; i++){
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente: ");
                scanf("%d", &expo);
                lista1 = insereDecrescente(lista1, base, expo);
            }
            printf("\n");
            for(i=0; i<5; i++){
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente: ");
                scanf("%d", &expo);
                lista1 = insereDecrescente(lista1, base, expo);
            }
            
            resultado = subtraiPolinomios(lista1, lista2);
            imprimeLista(resultado);
            break;

        case 3:
            printf("Saindo...\n");
            break;

        default:
            break;
        }
        
    } while (op != 3);

    return 0;
}