#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

// Creating a Queue
Queue* createqueue(int capacity) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    q->data = (int *)malloc(sizeof(int) * capacity);
    return q;
}

// Queue is full
bool isfull(Queue *q) {
    return q->size == q->capacity;
}

// Queue is empty
bool isempty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int value) {
    if (isfull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *q) {
    if (isempty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a default error value
    }
    int x = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

// Free queue memory
void freeQueue(Queue *q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

// Print the current queue
void printQueue(Queue *q) {
    if (isempty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");
    int count = q->size;
    int i = q->front;
    while (count--) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

// Main function to demonstrate
int main() {
    int capacity = 5;
    Queue *myQueue = createqueue(capacity);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    printQueue(myQueue);

    int dequeued = dequeue(myQueue);
    if (dequeued != -1)
        printf("Dequeued: %d\n", dequeued);

    printQueue(myQueue);

    freeQueue(myQueue);
    return 0;
}
