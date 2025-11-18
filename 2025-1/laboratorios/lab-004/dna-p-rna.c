#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dna {
    char valor;
    struct dna *prox, *ant;
} DNA;

typedef struct rna {
    char trinca[4];
    struct rna *prox, *ant;
} RNA;

DNA *criaNo(char valor){
    DNA *novo = (DNA*)malloc(sizeof(DNA));
    if (novo == NULL){
        printf("\nErro de alocação\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

DNA *criaLista(DNA *l, char valor){
    DNA *novo = criaNo(valor);
    if (l == NULL){
        return novo;
    } 

    DNA *aux = l;

    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
    return l;
}

DNA *trancrever(DNA* l){
    DNA *aux = l;
    
    if (l == NULL){
        return NULL;
    }


    while (aux != NULL) {
        switch (aux->valor) 
        {
            case 'G':
                aux->valor = 'C';
                break;
            
            case 'C':
                aux->valor = 'G';
                break;

            case 'T':
                aux->valor = 'A';
                break;

            case 'A':
                aux->valor = 'U';
                break;
            
            default:
                break;
        }
        aux = aux->prox;
    }
    return l;
}

void imprimeListaDNA(DNA *l){
    if(l == NULL)
        return;
    printf("%c ", l->valor);
    imprimeListaDNA(l->prox);
}

// COISAS DO RNA

RNA *criaRNA(char valor[]){
    RNA *novo = (RNA*)malloc(sizeof(RNA));
    if (novo == NULL){
        printf("Erro novo RNA");
        exit(1);
    }

    strcpy(novo->trinca, valor);
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

RNA *criaListaRNA(RNA *l, char valor[]){
    int i;
    char temp[4];

    if ((strlen(valor)) % 3 != 0){
        printf("\nNumero de trincas invalido\n");
        return NULL;
    }
    for (i=0; valor[i] != '\0'; i+=3){
        
        strncpy(temp, &valor[i], 3);
        temp[3] = '\0';

        RNA *novo = criaRNA(temp);

        if (l == NULL){
            l = novo;
        } else {
            RNA *aux = l;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
            novo->ant = aux;
        }
    } 
    return l;
}

void imprimeListaRNA(RNA *l){
    if(l == NULL)
        return;
    printf("-> %s ", l->trinca);
    imprimeListaRNA(l->prox);
}

int main(){
    DNA *listaDNA = NULL;
    RNA *listaRNA = NULL;
    char seq[300];
    int i;
    char op;

    while (op != '3'){
        printf("\nQual questão deseja testar?\n");
        printf("1 - Transcrever de DNA p/ RNA\n");
        printf("2 - Obter uma cadeia de aminoácidos de um RNA\n");
        printf("3 - SAIR\n");
        printf("\nop: ");
        scanf(" %c", &op);

        switch (op){
            case '1':
                printf("\nInsira uma sequencia de DNA: (EX: GCTA) ");
                scanf("%s", seq);
            
                for(i=0; seq[i] != '\0'; i++){
                    listaDNA = criaLista(listaDNA, seq[i]);
                }
            
            
                printf("DNA: ");
                imprimeListaDNA(listaDNA);
            
                listaDNA = trancrever(listaDNA);

                printf("\nRNA: ");
                imprimeListaDNA(listaDNA);
                printf("\n");

                free(listaDNA);
            break;

            case '2':
                printf("Digite um sequencia de trincas: ");
                scanf("%s", seq);
                listaRNA = criaListaRNA(listaRNA, seq);

                printf("\nRNA ");
                imprimeListaRNA(listaRNA);
                printf("\n");

                free(listaRNA);
            break;

            case '3':
                printf("\nSaindo...\n");
            break;

            default:
                printf("\n\n!!Escolha uma opção válida!!\n\n");
            break;
        }
    }
    return 0;
}