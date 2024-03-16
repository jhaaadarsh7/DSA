#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include string.h for strlen function

#define MAX_SIZE 100

// Structure for Stack
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push element onto stack
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++s->top] = value;
    } else {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to pop element from stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to evaluate prefix expression
int evaluatePrefix(char *prefix) {
    Stack s;
    initialize(&s);
    int i = 0;
    // Start scanning from left to right
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            // Convert character digit to integer value and push onto stack
            push(&s, prefix[i] - '0');
        } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            // Pop two operands from stack
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            // Perform the operation and push the result onto stack
            switch (prefix[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    // Return the result (the top element of the stack)
    return pop(&s);
}

int main() {
    // Evaluate the prefix expression
    int result = evaluatePrefix("+*543");
    printf("Result of evaluating the expression: %d\n", result);
    return 0;
}
