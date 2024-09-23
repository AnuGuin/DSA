#include <stdio.h>
#include <stdlib.h>

// Define the stackNode structure using typedef
typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

// Function to push an element into the stack
void stackPush(StackNode** top, int x) {
    StackNode* element = (StackNode*)malloc(sizeof(StackNode));
    element->data = x;
    element->next = *top;
    *top = element;
    printf("Element pushed: %d\n", x);
}

// Function to pop an element from the stack
int stackPop(StackNode** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int topData = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    printf("Popped element: %d\n", topData);
    return topData;
}

// Function to check if the stack is empty
int stackIsEmpty(StackNode* top) {
    return top == NULL;
}

// Function to peek the top element of the stack
int stackPeek(StackNode* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Function to print the elements of the stack
void printStack(StackNode* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Menu function to display options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Push an element\n");
    printf("2. Pop an element\n");
    printf("3. Peek the top element\n");
    printf("4. Check if stack is empty\n");
    printf("5. Print stack elements\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    StackNode* top = NULL;  // Stack initialized to be empty
    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                stackPush(&top, value);
                break;
            case 2:
                stackPop(&top);
                break;
            case 3:
                value = stackPeek(top);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                if (stackIsEmpty(top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 5:
                printStack(top);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    // Free memory for remaining stack nodes
    while (top != NULL) {
        StackNode* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}
