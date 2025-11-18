#include <stdio.h>
#include <stdlib.h>


typedef struct heap{
    int capacidade;
    int tamanho_atual;
    int *vetor;    
} Heap;

Heap *criaHeap(int capacidade){
    Heap *h = (Heap*)malloc(sizeof(Heap));
    if (h == NULL){
        printf("Erro: Heap não alocado\n");
        exit(1);
    }

    h->capacidade = capacidade;
    h->vetor[capacidade + 1];
    h->tamanho_atual = 1;
    return h;
}

void troca (int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void heapfiy(Heap *h, int tamanho, int indice){
    int maior = indice;
    int esq = (2*indice) + 1;
    int dir = (2*indice) + 2;

    if(esq < tamanho && h->vetor[esq] > h->vetor[maior]){
        maior = esq;
    }

     if(dir < tamanho && h->vetor[dir] > h->vetor[esq]){
        maior = dir;
    }

    if (maior != indice){
        troca(h->vetor[])
    }
}

void Inserir(Heap *h, int prioridade){
    if (h->tamanho_atual == 0){
        h->vetor[1] = prioridade;
    }

    for(int i = 1; i < h->capacidade; i++){
        if (h->vetor[i] == NULL){
            h->vetor[i] = prioridade;
            break;
        }
    }
}

int extrairMax(Heap *h){
    
}



int main(){
    return 0;
}