Copy code
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

// Function to insert a node at the end of the list
void insertAtEnd(struct ListNode** head, int data) {
    struct ListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to concatenate two lists into one big list
struct ListNode* concatenateLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct ListNode* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = list2;

    return list1;
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
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    // Insert elements into list1
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    // Insert elements into list2
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 5);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Concatenate lists
    struct ListNode* concatenatedList = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    printList(concatenatedList);

    // Free the memory
    freeList(concatenatedList);

    return 0;
}
