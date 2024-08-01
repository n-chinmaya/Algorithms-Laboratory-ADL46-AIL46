#include <stdio.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temporary arrays
    int L[n1], R[n2];
    
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1)
        arr[k++] = L[i++];
    
    // Copy the remaining elements of R[], if any
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, arr_size);

    clock_t start, end;
    start = clock();
    mergeSort(arr, 0, arr_size - 1);
    end = clock();

    printf("Time taken by program is : %f seconds\n",((float)(end - start)) / CLOCKS_PER_SEC);

    printArray(arr, arr_size);

    return 0;
}