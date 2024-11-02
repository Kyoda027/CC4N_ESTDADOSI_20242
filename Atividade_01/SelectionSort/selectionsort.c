//Aluno: Estevão
#include <stdio.h>
#define R 50

void printArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[R] = {89, 12, 45, 67, 23, 10, 9, 35, 70, 56,
                     78, 34, 25, 14, 90, 87, 65, 44, 13, 48,
                     66, 28, 15, 3, 97, 54, 36, 27, 19, 41,
                     64, 31, 26, 5, 43, 99, 75, 50, 6, 84,
                     72, 16, 21, 33, 53, 18, 38, 24, 11, 77};

    selectionSort(arr, R);

    printf("Array ordenado:\n");
    printArray(arr, R);

    return 0;
}

