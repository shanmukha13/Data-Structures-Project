#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
struct GraphNode {
    int vertex;
    struct GraphNode* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct GraphNode* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Function to create a new graph node
struct GraphNode* createNode(int v) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Depth-First Search traversal
void DFS(struct Graph* graph, int vertex) {
    struct GraphNode* adjList = graph->adjLists[vertex];
    struct GraphNode* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited vertex: %d\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }

        temp = temp->next;
    }
}

int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);

    printf("Depth-First Traversal (starting from vertex 0):\n");
    DFS(graph, 0);

    return 0;
}
