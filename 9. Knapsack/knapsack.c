#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printknapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int M[n+1][W + 1];
    
    for (w = 0; w <= W; w++)
        M[0][w] = 0;
    for (i = 0; i <= n; i++)
        M[i][0] = 0;
        
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            if (wt[i] > w) {
                M[i][w] = M[i - 1][w];
            } else {
                M[i][w] = max(M[i - 1][w], val[i] + M[i - 1][w - wt[i]]);
            }
        }
    }
    printf("Knapsack Result: %d\n", M[n][W]);
    
    printf("Knapsack Items : ");
    i = n;
    int k = W;
    while (i > 0 && k > 0) {
        if (M[i][k] != M[i - 1][k]) {
            printf("%d\t", i);
            k -= wt[i];
        }
        i--;
    }
    printf("\n");
}

int main() {
    int val[] = { 0, 10, 4, 9, 11 };
    int wt[] = { 0, 3, 5, 6, 2 };
    int W = 7;
    int n = sizeof(val) / sizeof(val[0]) - 1;
    
    printknapSack(W, wt, val, n);
    
    return 0;
}