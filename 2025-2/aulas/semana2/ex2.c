#include <stdio.h>
#include <stdlib.h>
int main() {
    int *a;
    int n, i;
    scanf("%d", &n);
    a = calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        printf("%p: %d\n", &(a[i]), a[i]);
    }

    free(a);
    return 0;
}
