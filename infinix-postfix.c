// Write a program along with a proper algorithm to convert infix expression to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initialize(&s);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(&s, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && s.items[s.top] != '(') {
                printf("Invalid Expression!\n");
                exit(EXIT_FAILURE);
            } else {
                pop(&s);
                i++;
            }
        } else {
            while (!isEmpty(&s) && precedence(infix[i]) <= precedence(s.items[s.top])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

