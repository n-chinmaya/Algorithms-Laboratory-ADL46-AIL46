#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_EDGES 1000

// Define the structure for an edge
typedef struct {
    char src, dest;
    int weight;
} Edge;

// Function to get index from a character (assuming 'a' -> 0, 'b' -> 1, etc.)
int getIndex(char c) {
    return c - 'a';
}

// Bellman-Ford algorithm
void bellmanFord(Edge edges[], int V, int E, char src) {
    int distance[V];
    int srcIndex = getIndex(src);
    
    // Initialize distances from src to all other vertices as INF
    for (int i = 0; i < V; i++)
        distance[i] = INF;
    distance[srcIndex] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = getIndex(edges[j].src);
            int v = getIndex(edges[j].dest);
            int weight = edges[j].weight;
            if (distance[u] != INF && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = getIndex(edges[i].src);
        int v = getIndex(edges[i].dest);
        int weight = edges[i].weight;
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the result
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%c \t\t %d\n", 'a' + i, distance[i]);
}

int main() {
    int V = 6; // Number of vertices in the graph ('a' to 'e' and 't')
    int E = 10; // Number of edges in the graph
    printf("Let the edge 't' be 'f' in our graph.\n\n");
    
    Edge edges[MAX_EDGES] = {
        {'a', 'b', -4},
        {'a', 'f', -3},
        {'b', 'd', -1},
        {'b', 'e', -2},
        {'c', 'b', 8},
        {'c', 'f', 3},
        {'d', 'a', 6},
        {'d', 'f', 4},
        {'e', 'c', -3},
        {'e', 'f', 2}
    };

    char src = 'a';
    bellmanFord(edges, V, E, src);

    return 0;
}