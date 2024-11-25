#include <stdio.h>

/**Junta duas partes do array já ordenadas**/
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    /**Copia as partes do array original**/
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    /**Junta os dois arrays de volta no original**/
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { 
            arr[k] = L[i];
            i++;
        } else { 
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {                                    /**Copia o que sobrou de L[] (se sobrar)**/
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {                                    /**Copia o que sobrou de R[] (se sobrar)**/
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**** divide o array e organiza cada parte ****/
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;             /**Acha o meio**/

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right); 

        merge(arr, left, mid, right);                   /**Junta os dois lados**/
    }
}

int main() {
    int arr[] = {8, 3, 6, 7, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

