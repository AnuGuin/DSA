#include<stdio.h>
#include<string.h>
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }
    // Swap characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    // Recursively reverse the substring
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);
    reverseString(str, 0, len - 1);
    printf("Reversed string: %s\n", str);
    return 0;
}
