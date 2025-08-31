#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// PONTO 1: A função AGORA RECEBE o tamanho 'tam' do heap.
// O nome também foi corrigido de "maxHeapfiy" para "heapify".
void heapify(int heap[], int tam, int i) {
    int maior = i;
    int esquerda = (2 * i) + 1;
    int direita = (2 * i) + 2;

    // A variável 'tam' não é mais calculada aqui dentro. Usamos o parâmetro.
    // PONTO 2: A condição foi corrigida de '<=' para '<'.
    if (esquerda < tam && heap[esquerda] > heap[maior]) {
        maior = esquerda;
    }

    if (direita < tam && heap[direita] > heap[maior]) {
        maior = direita;
    }

    if (maior != i) {
        trocar(&heap[i], &heap[maior]);
        // A chamada recursiva também precisa passar o tamanho 'tam'.
        heapify(heap, tam, maior);
    }
}

// PONTO 3: A função AGORA RECEBE o tamanho 'n' do array.
// O tipo de retorno foi mudado para void, pois ela não retorna um valor.
void heapSort(int heap[], int n) {
    // A variável 'n' não é mais calculada aqui. Usamos o parâmetro.

    // Fase 1: Construção do Max Heap.
    // A chamada para heapify agora passa 'n' como o tamanho.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }

    // Fase 2: Extração e Ordenação.
    for (int i = n - 1; i > 0; i--) {
        trocar(&heap[0], &heap[i]);

        // PONTO 4: Na ordenação, o tamanho do heap diminui.
        // Por isso, passamos 'i' como o novo tamanho para o heapify.
        heapify(heap, i, 0);
    }
}

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int meu_array[] = {4, 10, 3, 5, 1, 8, 22};
    
    // O cálculo de 'n' aqui está perfeito!
    int n = sizeof(meu_array) / sizeof(meu_array[0]);

    printf("Array original: ");
    imprimirArray(meu_array, n);

    // PONTO 5: Agora passamos 'n' para a função heapSort.
    heapSort(meu_array, n);

    printf("Array ordenado: ");
    imprimirArray(meu_array, n);

    return 0;
}
