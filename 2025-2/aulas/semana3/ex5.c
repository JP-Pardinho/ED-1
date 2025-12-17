#include <stdio.h>

void imprime(char s[]){
    if (s[0] == '\0')
        return;
    printf("%c", s[0]);
    imprime(&s[1]);
}

int main() {
    char msg[257];
    fgets(msg, 256, stdin); //ou scanf("%100[^\n]%*c",msg);
    imprime(msg);
    return 0;
}