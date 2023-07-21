#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Queue implementation for BFS
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Graph implementation
typedef struct {
    int vertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void breadthFirstSearch(Graph* g, int startVertex) {
    bool visited[MAX_NODES] = { false };
    Queue q;
    initQueue(&q);

    visited[startVertex] = true;
    printf("Visited vertex: %d\n", startVertex);
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                printf("Visited vertex: %d\n", i);
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    // Create a graph with 6 vertices
    Graph graph;
    int vertices = 6;
    initGraph(&graph, vertices);

    // Add edges between vertices
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5);

    int startVertex = 0;
    printf("BFS Traversal starting from vertex %d:\n", startVertex);
    breadthFirstSearch(&graph, startVertex);

    return 0;
}
