#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for Queue
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if queue is full
int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to add element to the rear of the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0; // If queue is empty, set front to 0
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to remove element from the front of the queue
int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        item = q->items[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        printf("%d dequeued from queue.\n", item);
        return item;
    }
}

// Function to display the elements of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initialize(&q);

    // Enqueue elements
    enqueue(&q, 1);
    enqueue(&q, 0);
    enqueue(&q, 3);

    // Display queue
    display(&q);

    // Dequeue elements
    dequeue(&q);
    dequeue(&q);

    // Display queue after dequeue
    display(&q);

    return 0;
}
