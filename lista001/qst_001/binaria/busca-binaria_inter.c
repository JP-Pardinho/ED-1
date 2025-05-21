#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscaBinaria (int vet[], int numProcurado, int tam_vet){
    int inicio = 0, meio, fim = tam_vet;

    if (vet == NULL){
        printf("Vetor vazio\n");
        return 1;
    } else {
        while (fim >= inicio){
            meio =  inicio + (fim-inicio)/2;

            if(vet[meio] == numProcurado) {
                return meio;
            }
            if(numProcurado < vet[meio]){
                fim = meio - 1;
            }

            if(numProcurado > vet[meio]){
                inicio = meio + 1;
            
            } else {
                printf("Estou aqui\n");
            }
        }
    }
    return 999;
}

int main() {
    int *vet = NULL;
    int tam_vet, i;
    int num, resultado;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam_vet);

    vet = (int *)malloc(tam_vet *sizeof(int));

    for(i=0; i<tam_vet; i++){
        printf("Digite o %dº numero: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("Qual o numero que voce quer procurar? ");
    scanf("%d", &num);

    resultado = buscaBinaria(vet, num, tam_vet);
    
    printf("Resultado = %d\n", resultado);
    
    free(vet);
    return 0;
}       