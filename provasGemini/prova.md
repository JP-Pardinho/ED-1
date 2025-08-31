# Exercícios de Revisão - Estrutura de Dados 1

## Prova 1: TADs, Listas e Árvores

### Questão 1: Inversor de Sequências com Pilha

**Problema:** Você foi contratado para desenvolver um módulo para um processador de texto que precisa inverter palavras ou frases específicas. Para fazer isso de forma eficiente, você deve usar o conceito de um TAD Pilha (`Stack`).

**Implementação:**
Crie um programa em C/C++ que leia uma string (uma sequência de caracteres) e a imprima na ordem inversa.

1.  **TAD Pilha:** Implemente um TAD Pilha usando uma **lista simplesmente encadeada** como estrutura de dados base. A pilha deve ser dinâmica, ou seja, alocar memória para cada novo nó. O `struct No` deve conter um `char` e um ponteiro para o próximo. Sua pilha deve ter as seguintes funções:
    * `Pilha* criar_pilha();`
    * `void empilhar(Pilha* p, char valor);` (push)
    * `char desempilhar(Pilha* p);` (pop)
    * `int esta_vazia(Pilha* p);`
    * `void liberar_pilha(Pilha* p);`

2.  **Lógica Principal:**
    * Leia uma string do usuário.
    * Itere por cada caractere da string e empilhe-o na sua pilha.
    * Após empilhar todos os caracteres, desempilhe-os um por um e imprima-os na tela até que a pilha esteja vazia.

**Ponto-chave:** Esta questão testa seu domínio sobre a criação de um TAD sobre outra estrutura (Pilha sobre Lista Simplesmente Encadeada) e a propriedade fundamental de uma pilha: LIFO (Last-In, First-Out), que é perfeita para inversões.

---

### Questão 2: Verificador de Árvore AVL

**Problema:** Nem toda Árvore Binária de Busca (ABB) é uma Árvore AVL. Uma árvore é considerada AVL se, para **todos** os seus nós, a diferença de altura entre a sub-árvore da esquerda e a sub-árvore da direita (o fator de balanceamento) for de, no máximo, 1 (em módulo).

**Implementação:**
Escreva um programa que, dada uma raiz de uma Árvore Binária **já existente**, determine se ela atende aos critérios para ser uma árvore AVL.

1.  **Estrutura Base:** Considere o `struct No` de uma árvore binária padrão:
    ```c
    struct No {
        int chave;
        struct No* esquerda;
        struct No* direita;
    };
    ```

2.  **Funções a serem criadas:**
    * `int max(int a, int b);` (Função auxiliar que retorna o maior de dois inteiros).
    * `int altura(No* no);` (Função **recursiva** que calcula a altura de um nó. A altura de uma folha é 0, e a de um nó nulo é -1).
    * `int obter_fator_balanceamento(No* no);` (Calcula a diferença `altura(no->esquerda) - altura(no->direita)`).
    * `bool eh_avl(No* raiz);` (Função principal, **recursiva**, que percorre a árvore. Para cada nó, ela verifica se seu fator de balanceamento é válido (`-1`, `0` ou `1`) E se suas sub-árvores esquerda E direita também são AVL).

**Ponto-chave:** O segredo aqui é a recursão. Você precisa entender que a propriedade AVL deve ser válida para todos os nós. A função `eh_avl` deve, portanto, garantir a condição no nó atual e chamar a si mesma para os filhos. Calcular a altura de forma recursiva é a base para resolver o problema.

---
---

## Prova 2: Heaps e Árvores Avançadas

### Questão 1: Simulador de Fila de Prioridade (Heap)

**Problema:** Você precisa implementar o sistema de gerenciamento de tarefas de um processador, onde tarefas com maior prioridade devem ser executadas primeiro. A estrutura de dados ideal para isso é uma Fila de Prioridades, implementada com um **Max-Heap**.

**Implementação:**
Crie um programa que simule a inserção e execução de tarefas. As tarefas são representadas por um `int` que indica seu nível de prioridade (quanto maior o número, maior a prioridade).

1.  **TAD Max-Heap:** Implemente um TAD Max-Heap usando um **vetor (array dinâmico)**. O Heap deve conter o vetor, o tamanho atual e a capacidade máxima.
    * `Heap* criar_heap(int capacidade);`
    * `void inserir(Heap* h, int prioridade);` (Insere um novo elemento e "sobe" ele (`swim` ou `heapify_up`) para manter a propriedade do heap).
    * `int extrair_max(Heap* h);` (Remove e retorna o elemento de maior prioridade (a raiz), substitui pela última folha e "desce" o novo elemento (`sink` ou `heapify_down`) para restaurar a propriedade).
    * `void liberar_heap(Heap* h);`

2.  **Lógica Principal:**
    * Crie um heap com capacidade para 10 tarefas.
    * Insira as seguintes prioridades na ordem: `15, 40, 30, 10, 80, 50`.
    * Extraia e imprima a tarefa de maior prioridade por 3 vezes seguidas.

**Ponto-chave:** O desafio é implementar corretamente os algoritmos `heapify_up` (após inserção) e `heapify_down` (após extração). Lembre-se das fórmulas para encontrar pai (`(i-1)/2`) e filhos (`2*i + 1` e `2*i + 2`) em um vetor que representa a árvore.

---

### Questão 2: Dicionário com Árvore Rubro-Negra

**Problema:** Diferente de uma ABB comum, uma Árvore Rubro-Negra (RB-Tree) garante que as operações de inserção, busca e remoção tenham complexidade O(log n) no pior caso. Você deve usar essa estrutura para criar um dicionário de sinônimos simples.

**Implementação:**
Implemente a função de **inserção** de uma Árvore Rubro-Negra que armazena pares de palavras (palavra-chave e sinônimo). A árvore deve ser ordenada pela palavra-chave.

1.  **Estrutura do Nó:**
    ```c
    enum Cor { VERMELHO, PRETO };
    struct NoRB {
        char* palavra_chave;
        char* sinonimo;
        enum Cor cor;
        struct NoRB *pai, *esquerda, *direita;
    };
    ```

2.  **Funções a serem criadas:**
    * `NoRB* inserir(NoRB* raiz, NoRB* novo_no);` (Função principal que chama a inserção de ABB e depois a correção).
    * `NoRB* inserir_abb(NoRB* raiz, NoRB* novo_no);` (Realiza a inserção padrão de uma árvore binária de busca).
    * `void corrigir_insercao(NoRB** raiz, NoRB* novo_no);` (Esta é a função mais importante. Ela deve verificar a cor do pai e do tio do novo nó e aplicar as recolorações e rotações (esquerda/direita) necessárias para resolver as violações, conforme os casos da Rubro-Negra).
    * `void rotacao_esquerda(NoRB** raiz, NoRB* x);`
    * `void rotacao_direita(NoRB** raiz, NoRB* x);`

**Ponto-chave:** O foco é a função `corrigir_insercao`. Implemente a lógica dos 3 casos de inserção (Tio Vermelho; Tio Preto e forma de Triângulo; Tio Preto e forma de Linha). Esta é uma das questões mais complexas de Estrutura de Dados 1 e demonstra um domínio profundo do assunto.

---
---

## Prova 3: Aplicações de Listas e Árvores

### Questão 1: Playlist de Músicas com Lista Circular

**Problema:** Inspirado no problema de Josephus, você deve criar um sistema de playlist que toca músicas em loop. Quando a playlist chega ao fim, ela deve recomeçar automaticamente da primeira música. Além disso, o usuário pode pular para a "próxima" ou voltar para a música "anterior".

**Implementação:**
Use uma **Lista Duplamente Encadeada Circular** para gerenciar a playlist.

1.  **TAD Playlist:** O nó da lista deve armazenar o nome da música. Crie as seguintes funções:
    * `Playlist* criar_playlist();`
    * `void adicionar_musica(Playlist* pl, char* nome_musica);` (Insere no final da lista, mantendo a circularidade).
    * `void tocar_musica_atual(Playlist* pl);`
    * `void proxima_musica(Playlist* pl);` (Avança o ponteiro "atual" para o próximo nó).
    * `void musica_anterior(Playlist* pl);` (Retrocede o ponteiro "atual" para o nó anterior).
    * `void exibir_playlist(Playlist* pl);`

2.  **Lógica Principal:**
    * Crie uma playlist e adicione 3 músicas: "Musica A", "Musica B", "Musica C".
    * Mostre a música atual.
    * Avance para a próxima 4 vezes, mostrando a música atual a cada passo (para provar que a lista dá a volta).
    * Volte para a anterior 2 vezes, mostrando a música atual a cada passo.

**Ponto-chave:** A maior dificuldade é o gerenciamento correto dos ponteiros `prox` e `ant` na inserção para garantir que o último elemento aponte para o primeiro e vice-versa, fechando o círculo.

---

### Questão 2: Comparador de Árvores Binárias

**Problema:** Em otimização de algoritmos, às vezes é necessário verificar se duas estruturas de dados são funcionalmente idênticas. Sua tarefa é determinar se duas árvores binárias são estruturalmente e numericamente idênticas.

**Implementação:**
Escreva uma função que receba as raízes de duas árvores binárias e retorne `true` se elas forem idênticas, e `false` caso contrário.

1.  **Definição de Identidade:** Duas árvores são idênticas se:
    * A raiz de ambas não é nula e o valor de suas chaves é o mesmo.
    * A sub-árvore da esquerda da primeira árvore é idêntica à sub-árvore da esquerda da segunda.
    * A sub-árvore da direita da primeira árvore é idêntica à sub-árvore da direita da segunda.

2.  **Função a ser criada:**
    * `bool sao_identicas(No* raiz1, No* raiz2);`

**Ponto-chave:** Esta é uma questão clássica de recursão em árvores. A solução é elegante e compacta. Você deve tratar os casos base: ambas as raízes são nulas (são idênticas), apenas uma é nula (não são idênticas), ou os valores das chaves são diferentes (não são idênticas). Depois, a chamada recursiva resolve o problema para os filhos.