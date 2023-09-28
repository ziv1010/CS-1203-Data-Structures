#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent a queue
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Element inserted successfully.\n");
}

// Function to remove an element from the queue
int dequeue(Queue* queue) {
    int value;
    Node* temp;

    value = queue->front->data;
    temp = queue->front;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

// Function to print the elements of the queue
void printQueue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
    } else {
        Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice, value;

    do {
        // Menu options
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Print queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                if (queue.front == NULL) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Deleted element: %d\n", dequeue(&queue));
                }
                break;
            case 3:
                printf("Queue elements: ");
                printQueue(&queue);
                break;
            case 4:
                printf("Exiting the program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

