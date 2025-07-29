#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
   int dado;
   struct no *prox;
   struct no *ant;
}No;

No* criaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Alocação mal sucedida!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox =NULL;
    
    return novo;
}

No *busca(No *lista, int dado){
    No* aux = lista;
    while(aux != NULL && dado != aux->dado){
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

No *insereNoInicio(No *lista, int valor){
    No *aux = lista;
    No *novo = criaNo(valor);
    if(aux == NULL) lista = novo;
    else {
        novo->prox = lista;
        lista = novo;
    }
    return lista;
    
}

int retirar_retorna(No *lista, int i){
    No *aux = lista;
    No *pred = NULL;
    int cont = 0;
    if(aux == NULL){
        return -1;
    } else{
        while(aux != NULL && cont < i){
            pred = aux;
            aux = aux->prox;
            cont++;
        }
        if(aux == NULL){
            return -1;
        }else{
            pred->prox = aux->prox;
            aux->prox->ant = pred;
            i = aux->dado;
            free(aux);
        }
    }
    return i;
}
void imprimeLista(No* lista){
    if(lista == NULL) return;
    printf("%d ", lista->dado);
    imprimeLista(lista->prox);
}


int main(){
    No *lista = NULL;
    int indice, qnt, dado, retirado; 

    printf("Digite o tamanho da lista: ");
    scanf("%d", &qnt);
    for (int i=0; i<qnt; i++){
        printf("Digite o elemento %d: ", i+1);
        scanf("%d", &dado);
        lista = insereNoInicio(lista, dado);
    }

    printf("Qual posição da lista você quer retirar: ");
    scanf("%d", &indice);

    retirado = retirar_retorna(lista, indice);
    printf("\nRetirado = %d\n", retirado);

    imprimeLista(lista);
    printf("\n");
    
    return 0;
}