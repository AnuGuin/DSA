#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declaration
int arraySum(int arr[], int n);
void reverseString(char str[], int start, int end);
int isPalindrome(char str[], int start, int end);
int power(int base, int exponent);
void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg);
void permutations(char str[], int l, int r);
void swap(char* a, char* b);

int main() {
    int choice;
    int arr[100];
    int n, base, exponent;
    char str[100];
    
    do {
        printf("\nMenu:\n");
        printf("1. Calculate sum of array\n");
        printf("2. Reverse a string\n");
        printf("3. Check if a string is a palindrome\n");
        printf("4. Calculate power of a number\n");
        printf("5. Solve Tower of Hanoi\n");
        printf("6. Generate permutations of a string\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of elements in array: ");
                scanf("%d", &n);
                printf("Enter %d elements:\n", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Sum of array elements: %d\n", arraySum(arr, n));
                break;
            
            case 2:
                printf("Enter a string: ");
                scanf("%s", str);
                int len = strlen(str);
                reverseString(str, 0, len - 1);
                printf("Reversed string: %s\n", str);
                break;
            
            case 3:
                printf("Enter a string: ");
                scanf("%s", str);
                int length = strlen(str);
                if (isPalindrome(str, 0, length - 1)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            
            case 4:
                printf("Enter base and exponent: ");
                scanf("%d %d", &base, &exponent);
                printf("Result: %d\n", power(base, exponent));
                break;
            
            case 5:
                printf("Enter number of disks: ");
                scanf("%d", &n);
                towerOfHanoi(n, 'A', 'C', 'B');
                break;
            
            case 6:
                printf("Enter a string: ");
                scanf("%s", str);
                permutations(str, 0, strlen(str) - 1);
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

// Recursive function to calculate the sum of array elements
int arraySum(int arr[], int n) {
    if (n <= 0)
        return 0;
    return arraySum(arr, n - 1) + arr[n - 1];
}

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    if (start >= end)
        return;
    swap(&str[start], &str[end]);
    reverseString(str, start + 1, end - 1);
}

// Helper function to swap characters
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to check if a string is a palindrome
int isPalindrome(char str[], int start, int end) {
    if (start >= end)
        return 1;
    if (tolower(str[start]) != tolower(str[end]))
        return 0;
    return isPalindrome(str, start + 1, end - 1);
}

// Recursive function to calculate base raised to the power of exponent
int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else if  (exponent >  0){
        return base * power(base, exponent - 1);
    } else {
        return 1 / power(base, -exponent);
    }
    
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, dest);
        return;
    }
    towerOfHanoi(n - 1, source, aux, dest);
    printf("Move disk %d from peg %c to peg %c\n", n, source, dest);
    towerOfHanoi(n - 1, aux, dest, source);
}

// Recursive function to generate permutations of a string
void permutations(char str[], int l, int r) {
    if (l == r) {
        printf("%s\n", str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(&str[l], &str[i]);
            permutations(str, l + 1, r);
            swap(&str[l], &str[i]); // backtrack
        }
    }
}
