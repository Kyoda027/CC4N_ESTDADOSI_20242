#include <stdio.h>

/**Função para organizar o array com base nos gaps**/
void shellSort(int arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {                  /**Começa com um gap grande e vai diminuindo**/
      
        for (int i = gap; i < n; i++) {                       /**Percorre o array**/
            int temp = arr[i]; // guarda o valor atual
            int j;

            /**Reorganiza os valores baseados no gap**/
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];    /**Move o maior pra frente**/
            }

            arr[j] = temp;                /**Coloca o valor no lugar certo**/
        }
    }
}

int main() {
    int arr[] = {45, 23, 12, 89, 34, 90, 11, 78, 67, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    shellSort(arr, n);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

