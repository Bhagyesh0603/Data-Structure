#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If the character is a digit, push it to the stack
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to integer
        } 
        // If the character is an operator, pop two elements, perform the operation, and push the result
        else {
            int operand2 = pop();
            int operand1 = pop();
            switch (ch) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    // The result of the expression will be at the top of the stack
    return pop();
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+): ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
