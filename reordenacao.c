#include <stdio.h>
#include <time.h>

/* -------- função que imprime um array -------- */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* --------- Registro de Métricas --------- */
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
            temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp;
            (*passos)++; // troca
        }
    }

    temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp;
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

/* ------------------ MAIN ------------------ */
int main() {
    int rgm[] = {4, 5, 5, 3, 0, 0, 8, 4};
    int n = sizeof(rgm) / sizeof(rgm[0]);

    int arr1[n], arr2[n], arr3[n];

    /* Copiar array rgm para cada método */
    for (int i = 0; i < n; i++) {
        arr1[i] = rgm[i];
        arr2[i] = rgm[i];
        arr3[i] = rgm[i];
    }

    printf("RGM: ");
    printArray(rgm, n);

    /* -------- Executar os algoritmos com métricas -------- */
    Metricas mBubble = bubbleSort(arr1, n);
    Metricas mSelect = selectionSort(arr2, n);
    Metricas mQuick  = quickSort(arr3, n);

    /* -------- Exibir resultados -------- */
    printf("\n===== RESULTADOS ==============\n");

    printf("\nBubble Sort:\n");
    printArray(arr1, n);
    printf("Passos: %lld | Tempo: %.3f ms\n", mBubble.passos, mBubble.tempo_ms);

    printf("\nSelection Sort:\n");
    printArray(arr2, n);
    printf("Passos: %lld | Tempo: %.3f ms\n", mSelect.passos, mSelect.tempo_ms);

    printf("\nQuick Sort:\n");
    printArray(arr3, n);
    printf("Passos: %lld | Tempo: %.3f ms\n", mQuick.passos, mQuick.tempo_ms);

    printf("\n===============================\n");

    return 0;
}
