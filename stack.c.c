#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    if (stack->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

// Function to add an item to the top of the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->items[stack->top] = item;
        printf("Pushed: %d\n", item);
    }
}

// Function to remove an item from the top of the stack
int pop(struct Stack* stack) {
    int item;

    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        item = stack->items[stack->top];
        stack->top--;
        printf("Popped: %d\n", item);
        return item;
    }
}

// Function to display the items in the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack items:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    display(stack);

    pop(stack);
    pop(stack);

    display(stack);

    push(stack, 50);
    push(stack, 60);

    display(stack);

    return 0;
}
