#include <stdio.h>

int power(int base, int exp) {
    if (exp == 0) {
        return 1; // Base case: any number to the power of 0 is 1
    }
    return base * power(base, exp - 1); // Recursive case
}

int main() {
    int base, exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);
    
    int result = power(base, exp);
    printf("%d raised to the power of %d is %d\n", base, exp, result);
    return 0;
}
