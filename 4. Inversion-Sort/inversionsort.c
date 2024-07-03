#include <stdio.h>
#include <stdlib.h>

int inv_count = 0; // Global variable to store inversion count

void merge_and_count(int arr[], int l, int m, int r) {
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
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inv_count += (n1 - i); // Count inversions
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_and_count(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        // Sort first and second halves
        merge_sort_and_count(arr, l, m);
        merge_sort_and_count(arr, m + 1, r);
        
        // Merge the sorted halves and count inversions
        merge_and_count(arr, l, m, r);
    }
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 3, 2, 1, 5, 6, 8, 7};
    int arrsize = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    print_array(arr, arrsize);

    merge_sort_and_count(arr, 0, arrsize - 1);
    
    printf("Number of inversions: %d\n", inv_count);
    
    printf("Sorted Array: ");
    print_array(arr, arrsize);

    return 0;
}
