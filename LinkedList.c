//DSA Assignment1: LinekdList
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void insertNode(Node** head, int value);
void deleteNode(Node** head, int value);
void displayList(Node* head);
void reverseList(Node** head);
int searchNode(Node* head, int value);
void menu();
void createListFromUserInput(Node** head);

// Main function
int main() {
    Node* head = NULL;  // Initialize the head to NULL
    int choice, value;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                reverseList(&head);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                int index = searchNode(head, value);
                if (index != -1) {
                    printf("Value found at index: %d\n", index);
                } else {
                    printf("Value not found in the list.\n");
                }
                break;
            case 7:
                createListFromUserInput(&head);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Display menu options
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert a node at the end of the list\n");
    printf("2. Delete a node by value\n");
    printf("3. Display the list\n");
    printf("4. Reverse the list\n");
    printf("5. Search for a node\n");
    printf("6. Exit the program\n");
    printf("7. Create a linked list from user input\n");
}

// Insert a new node with the given value at the end of the linked list
void insertNode(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Delete the node with the given value from the linked list
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the elements of the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse the order of the nodes in the linked list
void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Search for a node with the given value in the linked list and return its position (index)
int searchNode(Node* head, int value) {
    Node* temp = head;
    int val = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            return val;
        }
        temp = temp->next;
        val++;
    }

    return -1; // Value not found
}

// Create a linked list from user input
void createListFromUserInput(Node** head) {
    int numNodes, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (int i = 0; i < numNodes; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertNode(head, value);
    }
}
