#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAXIMO 1000

int main() {    
    char *numeroStr = malloc(TAM_MAXIMO*sizeof(char));
    printf("Digite um número natual: ");
    scanf("%s", numeroStr);

    /*** Tarefa 1 ***/
    // Crie um vetor de inteiros (chamado 'numero') que contenha
    // *exatamente* a quantidade de digitos de 'numeroStr'.
    // Você *deve* usar alocação dinâmica para criar o array.

    //int numero = ...

    /*** Tarefa 2 ***/
    // Converta cada dígito do string 'numeroStr' para a posição
    // apropriada em 'numero'. 
    // Por exemplo, se numeroStr = "123", devemos ter numero = [1, 2, 3], ou seja,
    // numero[0] = 1, numero[1] = 2, numero[2] = 3
    // Note que o caractere '1' deve ser armazenado no vetor 'numero' como o número 
    // inteiro 1. O mesmo acontece para os outros dígitos.

    /*** Tarefa 3 ***/
    // Imprima o valor contido no vetor 'numero'. 
    // Ele deve ser equivalente ao valor digitado e armazenado em 'numeroStr'


    /*** Tarefa 4 ***/
    // Faça todas as desalocações necessária para evitar memory leak.
    // Use o valgind para ter certeza que tudo foi desalocado.

    return 0;
}
