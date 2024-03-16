#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure for a node in the linked list
typedef struct {
    int data;
    int next; // Index of the next node in the array
} Node;

// Function to initialize the linked list
void initialize(Node *list) {
    // Initialize all next pointers to -1 (indicating end of list)
    for (int i = 0; i < MAX_NODES; i++) {
        list[i].next = -1;
    }
}

// Function to insert a new node with data at the end of the list
int insert(Node *list, int data) {
    // Find the first available slot in the array
    int index = 0;
    while (list[index].next != -1) {
        index++;
        if (index >= MAX_NODES) {
            printf("List is full. Cannot insert.\n");
            return -1; // List is full
        }
    }

    // Insert data into the new node
    list[index].data = data;
    list[index].next = -1; // Set next pointer to indicate end of list

    return index; // Return the index of the newly inserted node
}

// Function to display the linked list
void display(Node *list) {
    int index = 0;
    printf("Linked List: ");
    while (index != -1) {
        printf("%d ", list[index].data);
        index = list[index].next;
    }
    printf("\n");
}

int main() {
    Node list[MAX_NODES];
    initialize(list);

    // Insert elements into the linked list
    int index1 = insert(list, 10);
    int index2 = insert(list, 20);
    int index3 = insert(list, 30);

    // Display the linked list
    display(list);

    return 0;
}
