#include <stdio.h>
/****Primeira parte - Troca de valores atraves do metodo swap****/
void swap (int *a,int *c){
    int temp = *a;
    *a = *c;
    *c = temp;
}
/***Depois disso a gente faz a partição atravez do pivo***/
int partition (int arr[], int low, int high){
    int pivo = arr[high];                       /**vamos fazer um pivo começando do ultimo indice**/
    int i = low - 1;
    
    for (int j = low; j < high; j++){               /**troca posição de valores e percorre o array**/
        if (arr[j] < pivo){
        i++;
        swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);                 /**colocamos o pivo na sua posição correta**/
    return i+1;
}

    void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);     /**Particiona e organiza a direita e esquerda**/
        quicksort(arr, low, pi - 1);        
        quicksort(arr, pi + 1, high);       
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

    quicksort(arr, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
