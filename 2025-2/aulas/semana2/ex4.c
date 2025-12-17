#include <stdio.h>
#include <stdlib.h>

int main() {
    int *x;
    int i = 0;
    while(1) {
        printf("%d ", i++);
        x = malloc(1000000*sizeof(int));
        if (x == NULL){
            break;
        }
    }

    free(x);
    return 0;
}
