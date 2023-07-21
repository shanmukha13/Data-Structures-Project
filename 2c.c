#include <stdio.h>
#include <stdlib.h>

// Definition of the list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Definition of the deque
struct Deque {
    struct ListNode* front; // Points to the front of the deque
    struct ListNode* rear;  // Points to the rear of the deque
};

// Function to create a new node with the given data
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the deque
void initDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct ListNode* newNode = createNode(data);

    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front = newNode;
    }
}

// Function to delete an element from the rear of the deque
int deleteRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty.\n");
        return -1;
    }

    int data = deque->rear->data;

    if (deque->front == deque->rear) {
        free(deque->rear);
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        struct ListNode* temp = deque->front;
        while (temp->next != deque->rear) {
            temp = temp->next;
        }
        temp->next = NULL;
        free(deque->rear);
        deque->rear = temp;
    }

    return data;
}

// Function to print the elements of the deque
void printDeque(struct Deque* deque) {
    struct ListNode* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory occupied by the deque
void freeDeque(struct Deque* deque) {
    struct ListNode* temp;
    while (deque->front != NULL) {
        temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    deque->rear = NULL;
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    // Insert elements at the front
    insertFront(&deque, 30);
    insertFront(&deque, 20);
    insertFront(&deque, 10);

    printf("Deque after insertion at the front: ");
    printDeque(&deque);

    // Delete elements from the rear
    int rearElement = deleteRear(&deque);
    printf("Deleted element from the rear: %d\n", rearElement);

    printf("Deque after deletion from the rear: ");
    printDeque(&deque);

    // Free the memory
    freeDeque(&deque);

    return 0;
}
