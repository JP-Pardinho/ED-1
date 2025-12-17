#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool achouSaida = false;
char **mapa;
int nl, nc, qtCaminhos = 0;

char **alocaMatriz(int linhas, int colunas){
    char **matriz = malloc(linhas * sizeof(char *)); 
    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(char)); 
    }
    return matriz;
}

void imprime(char **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%c", matriz[i][j]);
        printf("\n");
    }
}

void liberaMatriz(char **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}

void caminha(int l, int c) {

    // Verifica se 'l' e 'c' são valores válidos
    if(l < 0 || c < 0 || l >= nl || c >= nc)
        return;

    // Verifica se a posição não é caminho válido
    if (mapa[l][c] != '.')
        return;

    // Verifica se chegou em uma das extremidades do mapa.
    // Se chegou, achou a saída.
    if(l == 0 || c == 0 || l == nl - 1 || c == nc - 1) {
        // achouSaida = true;
        mapa[l][c] = 'v';
        qtCaminhos++;
        return;
    }

    
    // Se não retornou ainda, é porque o processo deve continuar
    mapa[l][c] = 'v';
    caminha(l, c - 1);
    caminha(l, c + 1);
    caminha(l - 1, c);
    caminha(l + 1, c);

}

int main() {
    scanf("%d %d", &nl, &nc);
    mapa = alocaMatriz(nl, nc + 1);
    for(int i = 0; i < nl; i++) {
        scanf("%s", mapa[i]);
    }
    int li, ci;
    scanf("%d %d", &li, &ci);

    imprime(mapa, nl, nc);

    caminha(li - 1, ci - 1);

    printf("Quantidade de caminhos: %d\n", qtCaminhos);

    liberaMatriz(mapa, nl);
    return 0;
}