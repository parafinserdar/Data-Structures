#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int data[MAX_VERTICES];
    int top;
} Stack;


void stack_init(Stack *s) {
    s->top = -1;
}

int stack_is_empty(Stack *s) {
    return (s->top == -1);
}

void stack_push(Stack *s, int value) {
    if (s->top == MAX_VERTICES - 1) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int stack_pop(Stack *s) {
    if (stack_is_empty(s)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

typedef struct {
    int vertices;
    int **adj_matrix;
    int *visited;
} Graph;

Graph* create_graph(int vertices) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    graph->adj_matrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adj_matrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    graph->visited = (int*)calloc(vertices, sizeof(int));

    return graph;
}

void add_edge(Graph *graph, int src, int dest) {
    graph->adj_matrix[src][dest] = 1;
    // Eğer yönlü değilse dest -> src de 1 olmalı
    // graph->adj_matrix[dest][src] = 1;
}

void depth_first_search(Graph *graph, int start_vertex) {
    Stack stack;
    stack_init(&stack);

    stack_push(&stack, start_vertex);
    graph->visited[start_vertex] = 1;

    while (!stack_is_empty(&stack)) {
        int current_vertex = stack_pop(&stack);
        printf("%d ", current_vertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adj_matrix[current_vertex][i] == 1 && graph->visited[i] == 0) {
                stack_push(&stack, i);
                graph->visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges;
    printf("Grafın düğüm sayısını girin: ");
    scanf("%d", &vertices);
    printf("Grafın kenar sayısını girin: ");
    scanf("%d", &edges);

    Graph *graph = create_graph(vertices);

    printf("Kenarları girin (örn. 0 1, 1 2 gibi):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(graph, src, dest);
    }

    int start_vertex;
    printf("Başlangıç düğümünü girin: ");
    scanf("%d", &start_vertex);

    printf("Depth First Search (DFS) sonucu:\n");
    depth_first_search(graph, start_vertex);

    return 0;
}