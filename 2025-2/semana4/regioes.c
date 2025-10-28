//Semelhante ao do labrinto, mas caminha nos # marcando toda uma
//região cercada por "água", simbolizada por '.'
//
//Diferenças principais:
// - só para o backtracking depois de marcar todos espaços contíguos de uma região
// - a função principal marca e conta todas as regiões
/*
Exemplo:
Tamanho do mapa: 7 8
..#...#.
..#####.
#...#...
##......
###...#.
.....###
..#...#.
Número de regiões: 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int qtRegioes;
char **mapa;
int nl, nc;

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


// Função recursiva que percorre (por backtracking) uma região de '#'s
void caminha(int l, int c) {
    // Verificar se está fora dos limites da matriz
    if (l < 0 || c < 0 || l >= nl || c >= nc)
        return;

    // Verificar se a posição atual não é '#' (ou já foi visitada)
    if (mapa[l][c] != '#' ) {
        return;
    }

    // TODO: 3. Marcar a posição atual como visitada (por exemplo, colocar 'o')
    mapa[l][c] = 'o';

    // TODO: 4. Chamar recursivamente a função para as 4 direções
    caminha(l, c + 1);
    caminha(l, c - 1);
    caminha(l + 1, c);
    caminha(l - 1, c);
}

int main() {
    scanf("%d %d", &nl, &nc);
    mapa = alocaMatriz(nl, nc + 1);
    for(int i = 0; i < nl; i++) {
        scanf("%s", mapa[i]);
    }

    for(int i = 0; i < nl; i++) {         //Procura região ainda não vista
        for(int j = 0; j < nc; j++) 
            if (mapa[i][j] == '#') {    //Se achou uma região ainda não vista
                qtRegioes++;
                printf("Encontrada regiao %d\n", qtRegioes);
                caminha(i, j);     //Visita a região toda, por backtracking
                printf("Regiao %d marcada\n", qtRegioes);
                imprime(mapa, nl, nc);
                printf("\n");
            }
        }   


    printf("Total de regiões: %d\n", qtRegioes);

    liberaMatriz(mapa, nl);
    return 0;
}
