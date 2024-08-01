#include <stdio.h>

int count = 0;  // Global variable to keep track of inversions

// Function to merge two halves of the array and count inversions
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } 
        else {
            arr[k++] = R[j++];
            count += (n1 - i);  // Count inversions
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Function to implement merge sort and count inversions
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) 
        min = b;
    if (c < min)
        min = c;
    return min;
}

void printArray(int arr[],int len){
    for (int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 8; //Number of songs
    
    int arr1[] = {4, 3, 2, 1, 5, 6, 8, 7};
    printf("User 1 : ");
    printArray(arr1,n);

    // Reset count before sorting each array
    count = 0;
    mergeSort(arr1, 0, n - 1);
    int a = count;

    int arr2[] = {4, 2, 3, 1, 5, 7, 8, 6};
    printf("User 2 : ");
    printArray(arr2,n);
    
    count = 0;  // Reset count before sorting each array
    mergeSort(arr2, 0, n - 1);
    int b = count;

    int arr3[] = {7, 1, 4, 3, 2, 5, 8, 6};
    printf("User 3 : ");
    printArray(arr3,n);

    count = 0;  // Reset count before sorting each array
    mergeSort(arr3, 0, n - 1);
    int c = count;

    int d = min(a, b, c);

    printf("Minimum Number of inversions: %d\n", d);

    return 0;
}