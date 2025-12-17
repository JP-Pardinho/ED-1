#include <stdio.h>
#include <stdlib.h>
int main() {
    int *x = NULL;
    int i, v, n = 0;
    printf("Escreva varios numeros inteiros (0 encerra)\n");
    scanf("%d", &v);
    while (v) {
        n++;
        x = realloc(x, n * sizeof(int));
        x[n - 1] = v;
        scanf("%d", &v);
    }
    for (i = 0; i < n; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    return 0;
}
