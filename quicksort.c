#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // Move `i` until you find an element greater than or equal to the pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        // Move `j` until you find an element smaller than or equal to the pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        // Swap if `i` is still less than `j`
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with the element at index `j`
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);  // Left partition
        quickSort(arr, pIndex + 1, high); // Right partition
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
