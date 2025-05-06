#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vet = NULL;
    int tam_vet;
    int i, aux;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam_vet);

    vet = (int *)malloc(tam_vet *sizeof(int));

    for(i=0; i<tam_vet; i++){
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &vet[i]);
    }

    for(i=0; i<tam_vet; i++){
        if 
        }
    }

    for(i=0; i<tam_vet; i++){
        printf("%d\n", vet[i]);
    }
    
    
    free(vet);
    return 0;
}       