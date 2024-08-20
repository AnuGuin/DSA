#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void normalizeString(char* str);
int isPalindromeRec(char* str, int start, int end);

int main() {
    char str[1000];

    // Input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Normalize the string
    normalizeString(str);

    // Calculate the length of the normalized string
    int length = strlen(str);

    // Check if the string is a palindrome
    if (length > 0 && isPalindromeRec(str, 0, length - 1)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

// Function to normalize the string: remove non-alphanumeric characters and convert to lowercase
void normalizeString(char* str) {
    char temp[1000];
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (isalnum((unsigned char)str[i])) {
            temp[j++] = tolower((unsigned char)str[i]);
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Recursive function to check if a string is a palindrome
int isPalindromeRec(char* str, int start, int end) {
    // Base case: if the string has zero or one character, it is a palindrome
    if (start >= end) {
        return 1;
    }

    // Check if the current characters are the same
    if (str[start] != str[end]) {
        return 0;
    }

    // Recursively check the next pair of characters
    return isPalindromeRec(str, start + 1, end - 1);
}
