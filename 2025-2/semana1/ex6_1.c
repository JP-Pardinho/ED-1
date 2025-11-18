#include <stdio.h>

void adicionaX1(int x, int b) {
    printf("Dentro de 'adicionaX1'\n");
    printf("End. de 'b': %p\n\n", &b);
    b = b + x;
}
void adicionaX2(int x, int *b) {
    printf("Dentro de 'adicionaX2'\n");
    printf("End. apontado por 'b': %p\n\n", b);
    *b = *b + x;
}
int main() {
    printf("Dentro de 'main'\n");
    int a = 0;
    printf("End. de 'a': %p\n", &a);
    printf("a = %d\n\n", a);

    adicionaX1(10, a);

    printf("De volta a 'main'\n");
    printf("a = %d\n\n", a);
    
    adicionaX2(10, &a);

    printf("De volta a 'main'\n");
    printf("a = %d\n", a);
    return 0;
}