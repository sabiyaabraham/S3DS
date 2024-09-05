#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the deque

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Function prototypes
void init(Deque *dq);
int isFull(Deque *dq);
int isEmpty(Deque *dq);
void insertFront(Deque *dq, int data);
void insertRear(Deque *dq, int data);
void deleteFront(Deque *dq);
void deleteRear(Deque *dq);
void display(Deque *dq);

// Initialize deque
void init(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}

// Check if deque is full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// Check if deque is empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Insert an element at the front of the deque
void insertFront(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }

    if (dq->front == -1) {  // First element
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {  // Wrap around
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = data;
    dq->size++;
    printf("Inserted %d at the front\n", data);
}

// Insert an element at the rear of the deque
void insertRear(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }

    if (dq->rear == -1) {  // First element
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {  // Wrap around
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = data;
    dq->size++;
    printf("Inserted %d at the rear\n", data);
}

// Delete an element from the front of the deque
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted %d from the front\n", dq->arr[dq->front]);
    
    if (dq->front == dq->rear) {  // Only one element was present
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {  // Wrap around
        dq->front = 0;
    } else {
        dq->front++;
    }

    dq->size--;
}

// Delete an element from the rear of the deque
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deleted %d from the rear\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {  // Only one element was present
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {  // Wrap around
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }

    dq->size--;
}

// Display the elements in the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque contents: ");
    
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) {
            break;
        }
        i = (i + 1) % MAX;  // Wrap around logic
    }
    printf("\n");
}

// Main function to demonstrate deque operations
int main() {
    Deque dq;
    init(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    display(&dq);  // Output: 5 10 20

    deleteFront(&dq);
    display(&dq);  // Output: 10 20

    deleteRear(&dq);
    display(&dq);  // Output: 10

    insertFront(&dq, 15);
    display(&dq);  // Output: 15 10

    return 0;
}
