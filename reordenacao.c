#include <stdio.h>

/*------ função que imprime os vetores -----*/
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* ------------------ Bubble sort -------------- */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* ------------------ Selection sort ------------- */
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

/* ------------------ Quick sort ------------------ */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1), temp;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }

    temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ------------- Main -------------------- */
int main() {
    int rgm[] = {4, 5, 5, 3, 0, 0, 8, 4};
    int n = sizeof(rgm) / sizeof(rgm[0]);

    int arr1[n], arr2[n], arr3[n];

    // Copiar array para cada método
    for (int i = 0; i < n; i++) {
        arr1[i] = rgm[i];
        arr2[i] = rgm[i];
        arr3[i] = rgm[i];
    }

    printf("RGM: ");
    printArray(rgm, n);

    // Bubble Sort e resultados
    bubbleSort(arr1, n);
    printf("Bubble Sort:   ");
    printArray(arr1, n);

    // Selection Sort e resultados
    selectionSort(arr2, n);
    printf("Selection Sort:");
    printArray(arr2, n);

    // Quick Sort e resultados
    quickSort(arr3, 0, n - 1);
    printf("Quick Sort:    ");
    printArray(arr3, n);

    return 0;
}
