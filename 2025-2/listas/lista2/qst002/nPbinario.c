#include <stdio.h>

void decimalParaBinario(int n) {
    if (n == 0) 
        return;
    
    
    decimalParaBinario(n/2);
    
    printf("%d", n % 2);
}

void imprimirBinario(int n) {
    if (n == 0) {
        printf("O");
        return;
    }

    return decimalParaBinario(n);
}

int main () {
    int x;

    printf("Digite um numero: ");
    scanf("%d", &x);

    printf("O numero em binario é: \n");
    
    imprimirBinario(x);
    printf("\n");

    return 0;
}