#include <stdio.h>
#include <stdlib.h>

/* Função 'troca'
 * Recebe o endereço (passagem por referência) de duas variáveis inteiras
 * e efetua a troca dos valores contido em 'x' e 'y'
 * Como é feita uma passagem por referência, a tropa persiste após a execução da função.
 * O mesmo não aconteceria se usássemos passagem por valor.
 */
void troca(int *x, int *y) {
	int tmp = *x;
    *x = *y;
    *y = tmp;
}

/* Função 'inverte'
 * Recebe um vetor de inteiros e seu tamanho.
 * O objetivo da função e inverter a ordem dos elementos. 
 */
void inverte(int v[], int n) {
    /*** TAREFA ***/
    // Sua tarefa é implementar o processo de inversão dos elementos do vetor 'v'
    // usando a técnica conhecida como Two Pointers.
    // Usando essa técnica não precisamos de um vetor auxiliar.
    // Para saber mais: https://www.geeksforgeeks.org/two-pointers-technique/

}

int main() {
    int n = 10;
    int *valores = malloc(n*sizeof(int));
    int inicio = 0, fim = n - 1;
    for (int i = 0; i < n; i++)
        valores[i] = i + 1;

    printf("Antes de inverter o vetor:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", valores[i]);
    printf("\n");

    inverte(valores, n);
    
    printf("Apos inverter o vetor:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", valores[i]);
    printf("\n");

    free(valores);
    return 0;
}