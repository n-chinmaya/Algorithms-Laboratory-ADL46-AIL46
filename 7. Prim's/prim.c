#include <stdio.h>
#include <stdbool.h>

// Define a large value as infinity
#define INF 9999999
// Define the number of vertices in the graph
#define V 5

// Define the adjacency matrix for the graph
int G[V][V] = {
    { 0, 4, 0, 8, 0 },
    { 4, 0, 3, 1, 0 },
    { 0, 3, 0, 7, 8 },
    { 8, 1, 7, 0, 3 },
    { 0, 0, 8, 3, 0 },
};

int main() {
    int no_edge = 0;  // Initialize number of edges in MST
    int selected[V] = {0};  // Array to track selected vertices
    selected[0] = 1;  // Start with the first vertex

    printf("Edge : Weight\n");  // Header for the output

    // Continue until we have V-1 edges in the MST
    while (no_edge < V - 1) {
        int min = INF;  // Initialize the minimum weight to infinity
        int x = 0, y = 0;  // Variables to store the indices of the minimum edge

        // Traverse all selected vertices
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                // Check all adjacent vertices
                for (int j = 0; j < V; j++) {
                    // If the vertex is not yet selected and there is an edge
                    if (!selected[j] && G[i][j] && G[i][j] < min) {
                        min = G[i][j];  // Update the minimum weight
                        x = i;  // Store the index of the vertex in the MST
                        y = j;  // Store the index of the vertex not in the MST
                    }
                }
            }
        }
        // Print the selected edge and its weight
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = 1;  // Mark the selected vertex as included in MST
        no_edge++;  // Increment the number of edges in MST
    }
    return 0;
}