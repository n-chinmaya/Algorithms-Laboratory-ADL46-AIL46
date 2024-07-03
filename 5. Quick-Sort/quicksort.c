#include <stdio.h>

void swap(int *a, int *b){
    int t = *a; 
    *a = *b; 
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[++i], &arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void main() {
    int arr[] = {10, 7, 8, 9, 1, 5}, n = 6;
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}