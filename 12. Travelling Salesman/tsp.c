#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define INF 999
#define N 5

int a[N][N] = {
    {INF,  2, INF, 12,  5},
    {  2, INF,  4,  8, INF},
    {INF,  4, INF,  3,  3},
    {12,  8,  3, INF, 10},
    {  5, INF,  3, 10, INF}
};

int min_cost = INT_MAX;
int best_path[N];

bool visited[N];

void TSP(int current_city, int count, int cost, int path[]) {
    if (count == N) {
        if (a[current_city][0] != INF && cost + a[current_city][0] < min_cost) {
            min_cost = cost + a[current_city][0];
            memcpy(best_path, path, N * sizeof(int));
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && a[current_city][i] != INF) {
            visited[i] = true;
            path[count] = i;
            TSP(i, count + 1, cost + a[current_city][i], path);
            visited[i] = false;
        }
    }
}

int main() {
    printf("The cost list is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d   ", a[i][j]);
        }
        printf("\n");
    }

    int path[N];
    path[0] = 0;
    visited[0] = true;
    TSP(0, 1, 0, path);

    printf("\nThe Path is: ");
    for (int i = 0; i < N; i++) {
        printf("%d -> ", best_path[i] + 1);
    }
    printf("1\n");

    printf("\nMinimum cost: %d\n", min_cost);
    return 0;
}