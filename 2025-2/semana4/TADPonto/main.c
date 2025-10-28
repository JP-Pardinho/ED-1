#include <stdio.h>
#include <stdlib.h>

#include "Ponto.h"
#include "Ponto.h"

int main() {
    Ponto *a = criaPonto(0, 0);
    Ponto *b = criaPonto(3, 4);
    printf("Distância: %.2f\n", distancia(a, b));
    free(a);
    free(b);
    return 0;
}