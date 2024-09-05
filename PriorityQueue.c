#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX];
    int size;
} PriorityQueue;

// Function prototypes
void init(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
int isFull(PriorityQueue *pq);
void enqueue(PriorityQueue *pq, int data, int priority);
int dequeue(PriorityQueue *pq);
void display(PriorityQueue *pq);

// Function to initialize the priority queue
void init(PriorityQueue *pq) {
    pq->size = 0;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Function to check if the priority queue is full
int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

// Function to add an element to the priority queue
void enqueue(PriorityQueue *pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full!\n");
        return;
    }

    int i = pq->size++;
    pq->elements[i].data = data;
    pq->elements[i].priority = priority;

    // Sort the queue based on priority (lower value means higher priority)
    while (i > 0 && pq->elements[i].priority < pq->elements[i - 1].priority) {
        Element temp = pq->elements[i];
        pq->elements[i] = pq->elements[i - 1];
        pq->elements[i - 1] = temp;
        i--;
    }

    printf("Enqueued: %d with priority %d\n", data, priority);
}

// Function to remove and return the element with the highest priority
int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int data = pq->elements[0].data;

    // Shift all elements to the left
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }

    pq->size--;
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to display the elements of the priority queue
void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue contents:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Item: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}

// Main function to demonstrate the priority queue operations
int main() {
    PriorityQueue pq;
    init(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    display(&pq);

    dequeue(&pq);
    display(&pq);

    return 0;
}
