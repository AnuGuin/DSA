#include <stdio.h>

void linearSearchIterative(int arr[], int n, int target);
int linearSearchRecursive(int arr[], int n, int target, int index);
void binarySearchIterative(int arr[], int n, int target);
int binarySearchRecursive(int arr[], int left, int right, int target);

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100], n, target, choice;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Search (Iterative)\n");
        printf("2. Linear Search (Recursive)\n");
        printf("3. Binary Search (Iterative) [Array will be sorted]\n");
        printf("4. Binary Search (Recursive) [Array will be sorted]\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearSearchIterative(arr, n, target);
                break;

            case 2: {
                int index = linearSearchRecursive(arr, n, target, 0);
                if (index != -1)
                    printf("Element found at index %d (Recursive Linear Search)\n", index);
                else
                    printf("Element not found (Recursive Linear Search)\n");
                break;
            }

            case 3:
                bubbleSort(arr, n);  // Sorting array for binary search
                binarySearchIterative(arr, n, target);
                break;

            case 4: {
                bubbleSort(arr, n);  // Sorting array for binary search
                int index = binarySearchRecursive(arr, 0, n - 1, target);
                if (index != -1)
                    printf("Element found at index %d (Recursive Binary Search)\n", index);
                else
                    printf("Element not found (Recursive Binary Search)\n");
                break;
            }

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}

void linearSearchIterative(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d (Iterative Linear Search)\n", i);
            return;
        }
    }
    printf("Element not found (Iterative Linear Search)\n");
}


int linearSearchRecursive(int arr[], int n, int target, int index) {
    if (index >= n) return -1; 
    if (arr[index] == target) return index; 
    return linearSearchRecursive(arr, n, target, index + 1); 
}


void binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d (Iterative Binary Search)\n", mid);
            return;
        }

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Element not found (Iterative Binary Search)\n");
}


int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) return -1;  
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid; 

    if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target); 
    else
        return binarySearchRecursive(arr, left, mid - 1, target);  
}
