#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {
    int n, m;
    int op, a, b;
    ll x;

    scanf("%d %d", &n, &m);

    ll *v = calloc((n + 1), sizeof(ll));

    for (int i = 0; i < m; i++) {
        scanf("%d", &op);

        if (op == 1) {        
            scanf("%d %d %lld", &a, &b, &x);
            for (int j = a; j <= b; j++) {
                v[j] += x;
            }
        }

        if (op == 2) {
            scanf("%d %d %lld", &a, &b, &x);
            for (int j = a; j <= b; j++) {
                v[j] -= x;
            }
        }
        
        if (op == 3) {
            scanf("%d", &a);
            printf("%lld\n", v[a]);
        }
    }

    free(v);

    return 0;
}