#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    ll n, k, *v;
    ll soma = 0;

    scanf("%lld", &n);
    
    ll inicio = 0, fim = (n - 1);

    v = (ll *)malloc(n * sizeof(ll));

    if (v == NULL) {
        exit(1);
    } 

    for (int i = 0; i < n; i++) {
        scanf("%lld", &v[i]);
    }

    scanf("%lld", &k);
    
    while (inicio != fim) {
        soma = v[inicio] + v[fim];
        
        if (soma == k) {
            printf("SIM\n");
            printf("%lld %lld\n", (inicio + 1), (fim + 1));
            break;
        } 
        
        if (soma < k)
            inicio++;
        else 
            fim--;
    }

    if (inicio == fim){
        printf("NAO\n");
    }
    
    free(v);
    return 0;
}