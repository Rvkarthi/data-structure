#include <stdio.h>
#define MAX 100  // Maximum size of the queue

// Queue variables
int queue[MAX];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0;  // Set front to 0 if it's the first element
    }
    rear++;
    queue[rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {  // Reset the queue if it becomes empty
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    printf("%d dequeued from the queue.\n", value);
    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Testing the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
