#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
// Define a structure for the queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->rear == -1;
}

// Function to check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}
// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
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

// Function to reverse the elements in a queue
void reverse_queue(Queue* q) {
    int temp[MAX_SIZE];
    int top = -1;
    while (!isEmpty(q)) {
        temp[++top] = dequeue(q);
    }

    while (top != -1) {
        enqueue(q, temp[top--]);
    }
}
// Function to display the elements in the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
         for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Main function to test the program
int main() {
    Queue* q = createQueue();

    // Add elements to the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    // Display the elements in the queue
    printf("Queue elements are:\n");
    display(q);
    // Reverse the elements in the queue
    printf("Reverse Queue, elements are:\n");
    reverse_queue(q);
    // Display the elements in the reversed queue
    display(q);
    enqueue(q, 100);
    enqueue(q, 200);
    printf("Add two elements to the said queue:\n");
    printf("Queue elements are:\n");
    display(q);
    // Reverse the elements in the queue
    printf("Reverse Queue, elements are:\n");
    reverse_queue(q);
    display(q);
    return 0;
}
