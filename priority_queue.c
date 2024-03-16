#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for priority queue
typedef struct {
    int items[MAX_SIZE];
    int priorities[MAX_SIZE];
    int front;
    int rear;
} PriorityQueue;

// Function to initialize priority queue
void initialize(PriorityQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if priority queue is full
int isFull(PriorityQueue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to check if priority queue is empty
int isEmpty(PriorityQueue *q) {
    return q->front == -1;
}

// Function to enqueue element with priority
void enqueue(PriorityQueue *q, int value, int priority) {
    if (isFull(q)) {
        printf("Priority queue is full. Cannot enqueue.\n");
    } else {
        // Find the position to insert based on priority
        int i;
        for (i = q->rear; i >= q->front && priority > q->priorities[i]; i--) {
            q->items[i + 1] = q->items[i];
            q->priorities[i + 1] = q->priorities[i];
        }
        q->items[i + 1] = value;
        q->priorities[i + 1] = priority;
        q->rear++;
        if (q->front == -1) {
            q->front = 0;
        }
        printf("%d enqueued to priority queue with priority %d.\n", value, priority);
    }
}

// Function to dequeue element with highest priority
int dequeue(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; // Reset front and rear if queue becomes empty
        }
        return item;
    }
}

// Function to display priority queue elements
void display(PriorityQueue *q) {
    if (isEmpty(q)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("(%d, %d) ", q->items[i], q->priorities[i]);
        }
        printf("\n");
    }
}

int main() {
    PriorityQueue q;
    initialize(&q);

    // Enqueue elements with priorities
    enqueue(&q, 10, 2);
    enqueue(&q, 20, 1);
    enqueue(&q, 30, 3);

    // Display priority queue
    display(&q);

    // Dequeue elements
    int dequeued = dequeue(&q);
    printf("Dequeued item with highest priority: %d\n", dequeued);

    // Display priority queue after dequeue
    display(&q);

    return 0;
}
