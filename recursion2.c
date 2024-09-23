#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Function Declaration
int calculateLength(Node* head);
Node* searchElement(Node* head, int target);
Node* mergeSortedLists(Node* list1, Node* list2);
Node* reverseList(Node* head);
Node* findMiddleNode(Node* head);


// Function declaration for parentheses balancing
int isOpenParenthesis(const char* str, int index, int length);
int isBalanced(const char* str, int index);

// Utility functions
Node* createNode(int data);
void append(Node** head, int data);
void printList(Node* head);
void freeList(Node* head);

int main() {
    int choice;
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* mergedList = NULL;
    Node* reversedList = NULL;
    Node* middleNode = NULL;
    int value, length, target;
    char str[100];
    
    do {
        printf("\nMenu:\n");
        printf("1. Calculate the length of a linked list\n");
        printf("2. Search for an element in a linked list\n");
        printf("3. Merge two sorted linked lists\n");
        printf("4. Reverse a linked list\n");
        printf("5. Find the middle node of a linked list\n");
        printf("6. Check if parentheses are balanced\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of nodes in the linked list: ");
                scanf("%d", &length);
                for (int i = 0; i < length; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list1, value);
                }
                printf("The length of the linked list is: %d\n", calculateLength(list1));
                freeList(list1);
                list1 = NULL;
                break;
                
            case 2:
                printf("Enter the number of nodes in the linked list: ");
                scanf("%d", &length);
                for (int i = 0; i < length; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list1, value);
                }
                printf("Enter value to search: ");
                scanf("%d", &target);
                Node* result = searchElement(list1, target);
                if (result) {
                    printf("Element %d found in the linked list.\n", target);
                } else {
                    printf("Element %d not found in the linked list.\n", target);
                }
                freeList(list1);
                list1 = NULL;
                break;
                
            case 3:
                printf("Enter the number of nodes in the first sorted linked list: ");
                scanf("%d", &length);
                for (int i = 0; i < length; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list1, value);
                }
                printf("Enter the number of nodes in the second sorted linked list: ");
                scanf("%d", &length);
                for (int i = 0; i < length; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list2, value);
                }
                mergedList = mergeSortedLists(list1, list2);
                printf("Merged sorted linked list: ");
                printList(mergedList);
                freeList(mergedList);
                list1 = NULL;
                list2 = NULL;
                break;
                
            case 4:
                printf("Enter the number of nodes in the linked list: ");
                scanf("%d", &length);
                for (int i = 0; i < length; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list1, value);
                }
                reversedList = reverseList(list1);
                printf("Reversed linked list: ");
                printList(reversedList);
                freeList(reversedList);
                list1 = NULL;
                break;
                
            case 5:
                printf("Enter the number of nodes in the linked list: ");
                scanf("%d", &length);
                for (int i = 0; i < length; i++) {
                    printf("Enter value for node %d: ", i + 1);
                    scanf("%d", &value);
                    append(&list1, value);
                }
                middleNode = findMiddleNode(list1);
                if (middleNode) {
                    printf("The middle node value is: %d\n", middleNode->data);
                } else {
                    printf("The list is empty.\n");
                }
                freeList(list1);
                list1 = NULL;
                break;
                
            case 6:
                printf("Enter a string containing parentheses: ");
                scanf("%s", str);
                if (isBalanced(str, 0)) {
                    printf("The parentheses are balanced.\n");
                } else {
                    printf("The parentheses are not balanced.\n");
                }
                break;
                
            case 7:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}

// Recursive function to calculate the length of the linked list
int calculateLength(Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + calculateLength(head->next);
}

// Recursive function to search for an element in the linked list
Node* searchElement(Node* head, int target) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == target) {
        return head;
    }
    return searchElement(head->next, target);
}

// Recursive function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    if (list1->data < list2->data) {
        list1->next = mergeSortedLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedLists(list1, list2->next);
        return list2;
    }
}

// Recursive function to reverse the linked list
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Recursive function to find the middle node of the linked list
Node* findMiddleNode(Node* head) {
    static Node* slow = NULL;
    static Node* fast = NULL;
    
    if (head == NULL) {
        Node* middle = slow;
        slow = fast = NULL;
        return middle;
    }
    
    if (fast == NULL) {
        slow = head;
        fast = head;
        return findMiddleNode(head->next);
    }
    
    fast = fast->next;
    if (fast != NULL) fast = fast->next;
    if (fast == NULL) return slow;
    
    return findMiddleNode(head->next);
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the linked list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the linked list memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Mutually recursive functions to check if parentheses are balanced
int isOpenParenthesis(const char* str, int index, int length) {
    if (index >= length) {
        return 1;
    }
    if (str[index] == '(') {
        return isBalanced(str, index + 1);
    }
    return isOpenParenthesis(str, index + 1, length);
}

int isBalanced(const char* str, int index) {
    if (str[index] == '\0') {
        return 1;
    }
    if (str[index] == '(') {
        return isOpenParenthesis(str, index + 1, strlen(str));
    }
    return isBalanced(str, index + 1);
}
