#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool ehPalindromo(char str[], int inicio, int fim) {
    if (strlen(str) == 0 || strlen(str) == 1)
        return false;
    
    if (str[inicio] != str[fim])
        return false;

    if (inicio >= fim)
        return true;

    return ehPalindromo(str, inicio + 1, fim - 1);
}


int main() {
    char p[30];
    int tam = 0;

    printf("Digite uma palavra: ");
    scanf("%s", p);

    tam = strlen(p) - 1;

    printf("Sua palavra: %d\n", ehPalindromo(p, 0, tam));

    return 0;
}