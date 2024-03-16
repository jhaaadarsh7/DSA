
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix, int A, int B, int C, int D) {
    Stack s;
    initialize(&s);
    int i = 0;
    while (postfix[i] != '\0') {
        if (isalpha(postfix[i])) {
            switch(postfix[i]) {
                case 'A':
                    push(&s, A);
                    break;
                case 'B':
                    push(&s, B);
                    break;
                case 'C':
                    push(&s, C);
                    break;
                case 'D':
                    push(&s, D);
                    break;
                default:
                    printf("Invalid operand!\n");
                    exit(EXIT_FAILURE);
            }
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch(postfix[i]) {
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
        i++;
    }
    return pop(&s);
}

int main() {
    // Provided values
    int A = 5, B = 4, C = 3, D = 7;

    // Evaluate the postfix expression with provided values
    int result = evaluatePostfix("ABCD-*+", A, B, C, D);
    printf("Result of evaluating the expression: %d\n", result);

    return 0;
}
