#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* -------- Função para imprimir array -------- */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* --------- Registro de métricas --------- */
typedef struct {
    long long passos;
    double tempo_ms;
} Metricas;

/* ------------------ Bubble Sort ------------------ */
Metricas bubbleSort(int arr[], int n) {
    Metricas m = {0, 0};
    int temp;
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            m.passos++; // comparação
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                m.passos++; // troca
            }
        }
    }

    m.tempo_ms = (double)(clock() - inicio) * 1000.0 / CLOCKS_PER_SEC;
    return m;
}

/* ------------------ Selection Sort ------------------ */
Metricas selectionSort(int arr[], int n) {
    Metricas m = {0, 0};
    int minIndex, temp;
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            m.passos++; // comparação
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        m.passos++; // troca
    }

    m.tempo_ms = (double)(clock() - inicio) * 1000.0 / CLOCKS_PER_SEC;
    return m;
}

/* ------------------ Quick Sort ------------------ */
int partition(int arr[], int low, int high, long long *passos) {
    int pivot = arr[high];
    int i = (low - 1), temp;

    for (int j = low; j < high; j++) {
        (*passos)++; // comparação
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            (*passos)++; // troca
        }
    }

    temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    (*passos)++; // troca final

    return (i + 1);
}

void quickSortRec(int arr[], int low, int high, long long *passos) {
    if (low < high) {
        int pi = partition(arr, low, high, passos);
        quickSortRec(arr, low, pi - 1, passos);
        quickSortRec(arr, pi + 1, high, passos);
    }
}

Metricas quickSort(int arr[], int n) {
    Metricas m = {0, 0};
    clock_t inicio = clock();

    quickSortRec(arr, 0, n - 1, &m.passos);

    m.tempo_ms = (double)(clock() - inicio) * 1000.0 / CLOCKS_PER_SEC;
    return m;
}

/* -------- Função para gerar vetor aleatório -------- */
void gerarVetor(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;  // valores entre 0 e 99999
}

/* -------- Função para testar para vários N -------- */
void testarN(int N) {
    int *v1 = malloc(N * sizeof(int));
    int *v2 = malloc(N * sizeof(int));
    int *v3 = malloc(N * sizeof(int));

    gerarVetor(v1, N);

    for (int i = 0; i < N; i++) {
        v2[i] = v1[i];
        v3[i] = v1[i];
    }

    printf("\n===============================\n");
    printf("      TESTANDO N = %d\n", N);
    printf("===============================\n");

    Metricas mBubble = bubbleSort(v1, N);
    Metricas mSelect = selectionSort(v2, N);
    Metricas mQuick  = quickSort(v3, N);

    printf("\nBubble Sort:    passos = %lld   tempo = %.3f ms\n", mBubble.passos, mBubble.tempo_ms);
    printf("Selection Sort: passos = %lld   tempo = %.3f ms\n", mSelect.passos, mSelect.tempo_ms);
    printf("Quick Sort:     passos = %lld   tempo = %.3f ms\n", mQuick.passos, mQuick.tempo_ms);

    free(v1);
    free(v2);
    free(v3);
}

/* ------------------ Main ------------------ */
int main() {
    srand(time(NULL));

    int rgm[] = {4, 5, 5, 3, 0, 0, 8, 4};
    int n = sizeof(rgm) / sizeof(rgm[0]);

    int arr1[n], arr2[n], arr3[n];

    for (int i = 0; i < n; i++) {
        arr1[i] = rgm[i];
        arr2[i] = rgm[i];
        arr3[i] = rgm[i];
    }

    printf("RGM: ");
    printArray(rgm, n);

    Metricas mBubble = bubbleSort(arr1, n);
    Metricas mSelect = selectionSort(arr2, n);
    Metricas mQuick  = quickSort(arr3, n);

    printf("\n===== RESULTADOS ==============\n");

    printArray(arr1, n);

    printf("\nBubble Sort:\nPassos: %lld | Tempo: %.3f ms\n", mBubble.passos, mBubble.tempo_ms);
    printf("\nSelection Sort:\nPassos: %lld | Tempo: %.3f ms\n", mSelect.passos, mSelect.tempo_ms);
    printf("\nQuick Sort:\nPassos: %lld | Tempo: %.3f ms\n", mQuick.passos, mQuick.tempo_ms);

    printf("\n===============================\n\n\n");
    
    printf("\nVETORES ALEATORIOS: \n");

    /* ------- NOVOS TESTES PARA N GRANDES ------- */
    testarN(100);
    testarN(1000);
    testarN(10000);

    return 0;
}
