#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the first N elements of the linked list
void reverseFirstN(struct Node** head, int N) {
    if (*head == NULL || N <= 1) {
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    int count = 0;

    while (current != NULL && count < N) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    *head = prev;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the linked list
    insertNode(&head, 6);
    insertNode(&head, 5);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);

    int N = 3;

    printf("Linked List before reversing first %d elements: ", N);
    printList(head);

    reverseFirstN(&head, N);

    printf("Linked List after reversing first %d elements: ", N);
    printList(head);

    return 0;
}
