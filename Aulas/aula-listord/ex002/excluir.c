#include <stdio.h>
#include <stdio.h>

typedef struct No
{
    int chave;
    No *prox;
} No;

No *excluir (No *lista){
    No *aux = lista, *pred = NULL, *fix = lista;
    if(lista == NULL) return NULL;
    else{
        while(fix != pred){
            if (fix == aux){
                free(aux);
            }


        }
    }
    
}


int main() {

    return 0;
}