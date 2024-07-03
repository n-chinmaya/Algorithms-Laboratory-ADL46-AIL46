#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // For INT_MAX

#define MAX_NODES 5

// Adjacency matrix representing the directed weighted graph
int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 2, 1},
    {1, 0, 2, 0, 1},
    {0, 1, 1, 1, 0},
};

void DFS(int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            DFS(i, visited);
        }
    }
}

int main() {
    int source = 0; // Source node (starting node)
    bool visited[MAX_NODES] = {false}; // Initialize all nodes as not visited

    printf("Nodes reachable from node %d are: ", source);
    DFS(source, visited);
    printf("\n");

    return 0;
}