#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

// Structure to represent a graph edge
struct GraphEdge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int numVertices, numEdges;
    struct GraphEdge* edges[MAX_EDGES];
};

// Function to create a graph edge
struct GraphEdge* createEdge(int src, int dest, int weight) {
    struct GraphEdge* newEdge = (struct GraphEdge*)malloc(sizeof(struct GraphEdge));
    newEdge->src = src;
    newEdge->dest = dest;
    newEdge->weight = weight;
    return newEdge;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->numEdges = 0;

    for (int i = 0; i < MAX_EDGES; i++) {
        graph->edges[i] = NULL;
    }

    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct GraphEdge* newEdge = createEdge(src, dest, weight);
    graph->edges[graph->numEdges] = newEdge;
    graph->numEdges++;
}

// Function to print the shortest path from the source vertex to all other vertices
void printShortestPath(int dist[], int numVertices) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Function to perform the Bellman-Ford algorithm
void bellmanFord(struct Graph* graph, int src) {
    int numVertices = graph->numVertices;
    int numEdges = graph->numEdges;
    int dist[MAX_VERTICES];

    // Initialize distances from the source vertex to all other vertices as infinite
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
    }

    // Distance from the source vertex to itself is 0
    dist[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= numVertices - 1; i++) {
        for (int j = 0; j < numEdges; j++) {
            int u = graph->edges[j]->src;
            int v = graph->edges[j]->dest;
            int weight = graph->edges[j]->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < numEdges; i++) {
        int u = graph->edges[i]->src;
        int v = graph->edges[i]->dest;
        int weight = graph->edges[i]->weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    printShortestPath(dist, numVertices);
}

int main() {
    int numVertices = 5;
    int numEdges = 8;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    printf("Shortest Paths from Source Vertex 0:\n");
    bellmanFord(graph, 0);

    return 0;
}
