#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Kuyruk dolu, eleman eklenemiyor!\n");
        return;
    } else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->data[queue->rear] = item;
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Kuyruk boş, eleman çıkartılamıyor!\n");
        return -1;
    } else if (queue->front == queue->rear) {
        item = queue->data[queue->front];
        queue->front = -1;
        queue->rear = -1;
    } else {
        item = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Kuyruk boş, peek işlemi yapılamaz!\n");
        return -1;
    } else {
        return queue->data[queue->front];
    }
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Kuyruk boş!\n");
        return;
    }
    printf("Kuyruk: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->data[queue->rear]);
}

void freeQueue(Queue* queue) {
    free(queue);
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    printQueue(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);

    printQueue(queue);

    printf("Peek: %d\n", peek(queue));

    freeQueue(queue);

    return 0;
}