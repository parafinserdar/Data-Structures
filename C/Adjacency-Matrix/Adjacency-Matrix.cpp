#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int matrix[MAX_NODES][MAX_NODES];
    int num_nodes;
} Graph;


Graph* createGraph(int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_nodes = 5;
    Graph* graph = createGraph(num_nodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    free(graph);

    return 0;
}