#include <stdio.h>

int fibo(int n) {
    int a = 0;
    int b = 1;
    int resultado = 0;

    for (int i = 0; i < n; i++) {
        printf("%d", a);
        resultado = a + b;
        a = b;
        b = resultado;
    }

    
}

int main() {

    return 0;
} 