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
        printf("\n");
        printf("%d ", aux->expoente);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){

    int n, m;
    int i = 0;
    No *lista1 = NULL;
    No *lista2 = NULL;

    for (i = 0; i < 5; i++){
        printf("Digite a base: ");
        scanf("%d ", &n);
        printf("Digite a expoente: ");
        scanf("%d ", &m);
        insereDecrescente(lista1, n, m);
    }
    
    for (i = 0; i < 5; i++){
        printf("Digite a base: ");
        scanf("%d ", &n);
        printf("Digite a expoente: ");
        scanf("%d ", &m);
        insereDecrescente(lista2, n, m);
    }
    
    No *soma = somaPolinomios(lista1, lista2);

    imprimeLista(soma);

    return 0;
}