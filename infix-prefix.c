#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for Stack
typedef struct {
    char items[MAX_SIZE];
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
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->items[++s->top] = c;
    } else {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to pop element from stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to get precedence of operator
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char *infix, char *prefix) {
    // Step 1: Reverse the infix expression
    strrev(infix);
    
    Stack s;
    initialize(&s);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i++];
        } else if (infix[i] == ')') {
            push(&s, infix[i++]);
        } else if (infix[i] == '(') {
            while (!isEmpty(&s) && s.items[s.top] != ')') {
                prefix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.items[s.top] != ')') {
                printf("Invalid Expression!\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&s);
                i++;
            }
        } else {
            while (!isEmpty(&s) && precedence(infix[i]) < precedence(s.items[s.top])) {
                prefix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        }
    }
    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    // Step 4: Reverse the resulting expression to get prefix
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
