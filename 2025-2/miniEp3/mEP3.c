#include <stdio.h>
#include <stdlib.h>

char **mapa;
int nl, nc;
int menorCaminho;

char **alocaMatriz(int l, int c) {
    char **matriz = (char **)malloc(l * sizeof(char *));
    if (matriz == NULL)
        exit(1);

    for (int i = 0; i < l; i++) {
        matriz[i] = (char *)malloc(c * sizeof(char));
        if (matriz[i] == NULL)
            exit(1);
    }
    return matriz;
}

void liberaMatriz(char **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}

void caminha(int l, int c, int passos) {
    if (l < 0 || c < 0 || l >= nl || c >= nc)
        return;

    if (mapa[l][c] == '#' || mapa[l][c] == 'v')
        return;

    if (menorCaminho != -1 && passos >= menorCaminho)
        return;

    if (mapa[l][c] == 'E') {
        if (menorCaminho == -1 || passos < menorCaminho)
            menorCaminho = passos;
        return;
    }

    char celulaAtual = mapa[l][c];
    mapa[l][c] = 'v';

    caminha(l, c + 1, passos + 1);
    caminha(l, c - 1, passos + 1);
    caminha(l + 1, c, passos + 1);
    caminha(l - 1, c, passos + 1);
 
    mapa[l][c] = celulaAtual;
}

int main() {
    scanf("%d %d", &nl, &nc);
    mapa = alocaMatriz(nl, nc + 1);

    for (int i = 0; i < nl; i++) {
        scanf("%s", mapa[i]);
    }

    int inicioL = -1;
    int inicioC = -1;

    for (int i = 0; i < nl; i++) {
        for (int j = 0; j < nc; j++) {
            if (mapa[i][j] == 'S') {
                inicioL = i;
                inicioC = j;
                break;
            }
        }
        if (inicioL != -1)
            break;
    }

    menorCaminho = -1;
    
    if (inicioL != -1) {
        caminha(inicioL, inicioC, 0);
    }

    if (menorCaminho == -1) {
        printf("Sem solucao\n");
    } else {
        printf("%d\n", menorCaminho);
    }

    liberaMatriz(mapa, nl);
    return 0;
}