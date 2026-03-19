#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
void displayMenu();
char getOperation();
float getNumber(const char *prompt);

// Arithmetic operations
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

// Display menu options
void displayMenu() {
    printf("\n====================================\n");
    printf("       SIMPLE CALCULATOR\n");
    printf("====================================\n");
    printf("Operations:\n");
    printf("  + : Addition\n");
    printf("  - : Subtraction\n");
    printf("  * : Multiplication\n");
    printf("  / : Division\n");
    printf("  c : Clear (start new calculation)\n");
    printf("  q : Quit\n");
    printf("====================================\n");
}

// Get operation from user
char getOperation() {
    char op;
    printf("\nEnter operation (+, -, *, /, c, q): ");
    scanf(" %c", &op);
    return tolower(op);
}

// Get number input from user
float getNumber(const char *prompt) {
    float num;
    printf("%s", prompt);
    while (scanf("%f", &num) != 1) {
        // Clear invalid input
        while (getchar() != '\n');
        printf("Invalid input! Please enter a number: ");
    }
    // Clear newline from buffer
    while (getchar() != '\n');
    return num;
}

// Main calculator function
int main() {
    float result = 0;
    float num = 0;
    char operation;
    int continueCalc = 1;

    displayMenu();

    // Get first number
    result = getNumber("Enter the first number: ");

    while (continueCalc) {
        operation = getOperation();

        switch (operation) {
            case '+':
                num = getNumber("Enter the next number: ");
                result = add(result, num);
                printf("Result: %.2f\n", result);
                break;

            case '-':
                num = getNumber("Enter the next number: ");
                result = subtract(result, num);
                printf("Result: %.2f\n", result);
                break;

            case '*':
                num = getNumber("Enter the next number: ");
                result = multiply(result, num);
                printf("Result: %.2f\n", result);
                break;

            case '/':
                num = getNumber("Enter the next number: ");
                result = divide(result, num);
                printf("Result: %.2f\n", result);
                break;

            case 'c':
                displayMenu();
                result = getNumber("Enter the first number: ");
                break;

            case 'q':
                printf("\nFinal Result: %.2f\n", result);
                printf("Thank you for using the calculator!\n");
                continueCalc = 0;
                break;

            default:
                printf("Invalid operation! Please try again.\n");
                break;
        }
    }

    return 0;
}
