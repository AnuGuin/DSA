#include <stdio.h>

#define MAX_SIZE 5

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
    return ((rear + 1) % MAX_SIZE == front);
}

// Function to add an element to the circular queue (enqueue)
void enqueue(int element)
{
    if (isFull())
    {
        printf("Queue is full! Cannot enqueue %d\n", element);
        return;
    }

    if (isEmpty())
    {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = element;
    printf("%d enqueued to the queue.\n", element);
}

// Function to remove an element from the circular queue (dequeue)
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
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }

    printf("%d dequeued from the queue.\n", dequeuedElement);
    return dequeuedElement;
}

// Function to display the elements of the circular queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
