#include <stdio.h>
# include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;    
} No;

No *criaNo(int valor){
    No *novo = (No *)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de alocação de memória\n");
        exit(1);
    } else{
        novo->dado = valor;
        novo->prox = NULL;
        return novo; 
    }
}

No *insereOrd(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L, *pred = NULL;
    if(L == NULL) L = novo;
    else {
        while(aux != NULL && valor > aux->dado){
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL){
            novo->prox = aux;
            L = novo;
        }
        else {
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return L;
}

void imprimeLista(No *L){
    No *aux = L;
    while (aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int buscaChave(No *L, int valor){
    int cont = 0;
    No *aux = L;
    if(L == NULL){
        return 0;
    } else {
        while (aux != NULL){
            if (aux->dado != valor){
                cont ++;
                aux = aux -> prox;
            } else{
                break;
            }
        }
        if (aux == NULL){
            return 0;
        }
        return cont;
    }

}

int main(){
    No *L = NULL;
    No *aux;
    int i = 0;
    int buscar, teste;



    criaNo(10);

    for(i=20; i<40; i++){
        L = insereOrd(L, i);
    }
    for(i=0; i<20; i++){
        L = insereOrd(L, i);
    }


    imprimeLista(L);

    printf("Digite o numeo que voce quer inserir? ");
    scanf("%d", &buscar);

    teste = insereOrd(L, teste);
    printf("Teste = %d\n", teste);

    while (L != NULL){
        aux = L;;
        L = L->prox;
        free(aux);
    }
    free(L);
    return 0;
}