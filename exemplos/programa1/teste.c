#include <stdio.h>
#include <string.h>

int ehAbertura (char c) {
    return c == '(' || c == '[' || c == '{'; 
}

int main () {
    char tagAbertura[10] = "{a[c(b)]}";

    // scanf("%c", &tagAbertura);
    
    
    for (int i = 0; i < strlen(tagAbertura); i++)
    {
        int teste = ehAbertura(tagAbertura[i]);
        
        if (teste){
            printf("%c É abertura\n", tagAbertura[i]);
        } else {
            printf("%c É letra\n", tagAbertura[i]);
        }
    }
    
    return 0;
}