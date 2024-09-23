#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the queue

// Queue array and front, rear variables
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty()
{
    return (front == -1);
}

// Function to check if the queue is full
int isFull()
{
    return (rear == MAX_SIZE - 1);
}

// Function to add an element to the queue (enqueue)
void enqueue(int element)
{
    if (isFull())
    {
        printf("Queue is full! Cannot enqueue %d\n", element);
        return;
    }

    if (isEmpty())
    {
        front = 0; // Initialize front when the first element is enqueued
    }

    rear++;
    queue[rear] = element;
    printf("%d enqueued to the queue.\n", element);
}

// Function to remove an element from the queue (dequeue)
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    int dequeuedElement = queue[front];

    if (front == rear)
    {
        // Reset the queue if it's the last element
        front = rear = -1;
    }
    else
    {
        front++;
    }

    printf("%d dequeued from the queue.\n", dequeuedElement);
    return dequeuedElement;
}

// Function to display the elements of the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main()
{
    // Part 2: Queue Operations

    // Enqueue some elements into the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    // Display the queue
    display();

    // Dequeue elements from the queue
    dequeue();
    dequeue();

    // Display the queue after dequeue operations
    display();

    // Check if the queue is empty
    if (isEmpty())
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("The queue is not empty.\n");
    }

    // Enqueue additional elements into the queue
    enqueue(60);
    enqueue(70); // This should fail since the queue is full

    // Display the updated queue
    display();

    return 0;
}
