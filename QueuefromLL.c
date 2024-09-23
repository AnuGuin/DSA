#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
typedef struct queueNode {
    int data;
    struct queueNode* next;
} QueueNode;

// Define a structure for the queue with pointers to the front and rear
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to enqueue (add) an element to the queue
void enqueue(Queue* q, int data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;

    if (q->rear == NULL) {  // If queue is empty
        q->front = q->rear = node;
        printf("%d enqueued\n", data);
        return;
    }

    q->rear->next = node;  // Add the new node at the rear
    q->rear = node;        // Move rear to the new node
    printf("%d enqueued\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(Queue* q) {
    if (q->front == NULL) {  // If the queue is empty
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }

    int dequeuedData = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {  // If the queue becomes empty after dequeue
        q->rear = NULL;
    }

    free(temp);  // Free the memory of the dequeued node
    return dequeuedData;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to peek at the front element of the queue
int peekFront(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty, cannot peek.\n");
        return -1;
    }
    return q->front->data;
}

// Function to print the elements of the queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    QueueNode* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue q = {NULL, NULL};  // Initialize the front and rear of the queue to NULL

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Current Queue: ");
    printQueue(&q);

    printf("Dequeued element: %d\n", dequeue(&q));

    printf("Queue's front element: %d\n", peekFront(&q));

    printf("Current Queue after dequeue: ");
    printQueue(&q);

    return 0;
}
