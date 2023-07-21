#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
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

// Function to compare two edges by weight
int compareEdges(const void* a, const void* b) {
    struct GraphEdge* edgeA = *(struct GraphEdge**)a;
    struct GraphEdge* edgeB = *(struct GraphEdge**)b;
    return edgeA->weight - edgeB->weight;
}

// Function to find the set of a vertex
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(struct Graph* graph) {
    int numVertices = graph->numVertices;
    struct GraphEdge* result[MAX_VERTICES];
    int e = 0; // Index for result[] array
    int i = 0; // Index for sorted edges array

    // Sort all edges in non-decreasing order of their weight
    qsort(graph->edges, graph->numEdges, sizeof(struct GraphEdge*), compareEdges);

    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));

    // Initialize subsets
    for (int v = 0; v < numVertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Process all edges in sorted order
    while (e < numVertices - 1 && i < graph->numEdges) {
        struct GraphEdge* nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge->src);
        int y = find(subsets, nextEdge->dest);

        // Include the edge in the result if it doesn't create a cycle
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int j = 0; j < e; j++) {
        printf("%d - %d : %d\n", result[j]->src, result[j]->dest, result[j]->weight);
    }

    free(subsets);
}

int main() {
    int numVertices = 6;
    int numEdges = 7;
    struct Graph* graph = createGraph(numVertices);

    graph->edges[0] = createEdge(0, 1, 4);
    graph->edges[1] = createEdge(0, 2, 3);
    graph->edges[2] = createEdge(1, 2, 1);
    graph->edges[3] = createEdge(1, 3, 2);
    graph->edges[4] = createEdge(2, 3, 4);
    graph->edges[5] = createEdge(3, 4, 2);
    graph->edges[6] = createEdge(4, 5, 6);

    graph->numEdges = numEdges;

    printf("Minimum Spanning Tree:\n");
    kruskalMST(graph);

    return 0;
}
