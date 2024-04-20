#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int items[MAX_SIZE];
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
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1)
        printf("\nKuyruk dolu!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("\nKuyruk bos!");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

typedef struct Graph {
    int numVertices;
    int** adjMatrix;
    int* visited;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    graph->visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++)
        graph->visited[i] = 0;

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void BFS(Graph* graph, int startVertex) {
    Queue* queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf(" %d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !graph->visited[i]) {
                graph->visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("BFS sonucu: ");
    BFS(graph, 0);

    return 0;
}