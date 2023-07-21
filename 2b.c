#include <stdio.h>
#include <stdlib.h>

// Definition of the list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to create a new node with the given data
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in sorted order
void insertInSortedOrder(struct ListNode** head, int data) {
    struct ListNode* newNode = createNode(data);

    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct ListNode* current = *head;

        while (current->next != NULL && data >= current->next->data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the elements of the list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory occupied by the list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* head = NULL;

    // Insert elements in sorted order
    insertInSortedOrder(&head, 20);
    insertInSortedOrder(&head, 40);
    insertInSortedOrder(&head, 10);
    insertInSortedOrder(&head, 50);
    insertInSortedOrder(&head, 30);


    printf("Sorted List: ");
    printList(head);

    // Free the memory
    freeList(head);

    return 0;
}
