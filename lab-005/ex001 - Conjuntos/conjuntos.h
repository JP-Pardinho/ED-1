#ifndef CONJUNTOS_H 
#define CONJUNTOS_H

typedef struct no{
    int dado;
    struct no *prox;

} No;

No *crarConjunto(int valor);
// Criar um conjunto

No *inserirElemento(No *conjunto, int valor);
// Inserir um elemento (recebe um conjunto e o elemento a ser inserido)

No *removerElemento(No *conjunto, int valor);
//Remover um elemento (recebe um conjunto e o elemento a ser removido)

void imprimirConjunto(No *conjunto);
// Imprimir os elementos de um conjunto (recebe o conjunto a ser impresso)

No *esvaziarConjunto(No *conjunto);
// Esvaziar o conjunto (recebe o conjunto a ser esvaziado) 

int verificaVazio(No *conjunto);
// Verificar se o conjunto é vazio (recebe um conjunto e retorna 1 caso seja vazio e 0, caso contrário)

int verificaElemento(No conjunto, int valor);
// Verificar se um elemento pertence a um conjunto (recebe um conjunto e um elemento)

int verificaContindo(No conjunto1, No conjunto2);
//Verificar se um conjunto está contido em outro conjunto (recebe dois conjuntos)

int verificaIgual(No conjunto1, No conjunto2);
// Verificar se dois conjuntos são iguais (recebe dois conjuntos)

int verificaSubconjunto(No conjunto1, No conjunto2);
// Verificar se um conjunto é subconjunto de outro conjunto (recebe dois conjuntos e retorna 1 em caso positivo e 0, caso contrário)

No *uniaoConjuntos(No conjunto1, No conjunto2);
//Fazer a união de dois conjuntos (recebe dois conjuntos e retorna um terceiro conjunto com a união das cópias dos elementos dos dois conjuntos passados)

No *intersecaoConjuntos(No conjunto1, No conjunto2);
// Fazer a interseção de dois conjuntos (recebe dois conjuntos e retorna um terceiro conjunto com a interseção das cópias dos elementos dos dois conjuntos passados)

No *realizarComplemento(No conjuntoA, No conjuntoB);

#endif