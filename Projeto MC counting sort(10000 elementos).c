#include <stdio.h>

#define RANGE 10000 // Define o alcance dos números a serem ordenados

void countingSort(int arr[], int n) {
    int output[n]; // Array de saída
    int count[RANGE + 1], i;
    for (i = 0; i <= RANGE; ++i)
        count[i] = 0;

    // Conta a frequência de cada elemento
    for (i = 0; i < n; ++i)
        ++count[arr[i]];

    // Atualiza o array de contagem para refletir a posição real dos elementos
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (i = 0; i < n; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // Copia o array de saída para o array original
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}

int main() {
    int arr[10000];
    printf("Insira os 10000 elementos a serem ordenados:\n");
    for (int i = 0; i < 10000; ++i)
        scanf("%d", &arr[i]);

    countingSort(arr, 10000);

    printf("Array ordenado:\n");
    for (int i = 0; i < 10000; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
