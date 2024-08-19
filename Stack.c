#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}
int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1; // Return -1 or some error value
    } else {
        return stack[top--];
    }
}
bool isEmpty() {
    return top < 0;
}
bool isFull() {
    return top >= MAX_SIZE - 1;
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
int main() {
    // Create an empty stack
    printf("Initial stack:\n");
    display();

    // Push some integer values onto the stack
    push(10);
    push(20);
    push(30);
    push(40);

    // Print the elements of the stack
    printf("Stack after pushing elements:\n");
    display();

    // Pop elements from the stack and print the popped elements
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    // Print the stack after popping elements
    printf("Stack after popping elements:\n");
    display();

    // Check if the stack is empty and print the result
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    // Push additional elements onto the stack and print the updated stack
    push(50);
    push(60);
    printf("Stack after pushing additional elements:\n");
    display();

    return 0;
}
