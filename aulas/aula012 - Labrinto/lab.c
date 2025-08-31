#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char dado;

    struct no *prox;
    struct no *ultimo;
} No;

typedef struct coordenada {
    int x;
    int y;
} C;



No *criaNo(char valor){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("\nErro novo nó\n");
        exit(1);
    }

    strcpy(novo->dado, valor);
    novo->prox = NULL;
    novo->ultimo = NULL;
    return novo;
}

No *insereFinal(No *l, char valor){
    No *novo = criaNo; 
    if (l == NULL){
        l->ultimo = novo;
        return novo;
    }

    l->ultimo->prox = novo;
    l->ultimo = novo;

    return l;
}

char removeInicio(No *l){
    if(l == NULL){
        return NULL;
    }

    char dado = l->dado;
    No *aux = l;
    l = l->prox;
    free(aux);

    return dado;
}

void verificaCaminho(char planta[1000][1000], int n, int m){
    int visitado[1000][1000] = {0};
    int tamCaminho = 0;
    int caminhoValido = 0; //Não tem caminho valido (0) se tem caminho valido (1)
    int i, j;

    No *fila = NULL;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if (planta[i][j] == 'A' && !(visitado[i][j])){
                
            }
        }
    }



}


int main() {

    return 0;
}
