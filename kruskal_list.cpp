#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define I 999

struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
};

struct Vertex {
    struct Edge* head;
};

struct Graph {
    int num_vertex;
    struct Vertex* array;
};

int numvertices = 5;
int cost[5][5] = {{I, 10, I,30,100},
		 {10,I,50,I,I}, 
		 {I,50,I,20,10 },
		 {30,I,20,I,60 },
		 {100,I,10,60,I}};

int parent[5];

struct Edge* createEdge(int vertex, int weight) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->vertex = vertex;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertex = vertices;
    graph->array = (struct Vertex*)malloc(vertices * sizeof(struct Vertex));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Edge* newEdge = createEdge(dest, weight);
    newEdge->next = graph->array[src].head;
    graph->array[src].head = newEdge;

    newEdge = createEdge(src, weight);
    newEdge->next = graph->array[dest].head;
    graph->array[dest].head = newEdge;
}

int findparent(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

int unionn(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n = numvertices;
    int i, j;
    struct Graph graph;
    graph.num_vertex = n;
    graph.array = (struct Vertex*)malloc(n * sizeof(struct Vertex));

    for (i = 0; i < n; i++) {
        graph.array[i].head = NULL;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] != I) {
                addEdge(&graph, i, j, cost[i][j]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    int ne = 1;
    int cost1 = 0;
    while (ne < n) {
        int min = I, a = -1, b = -1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && findparent(i) != findparent(j)) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = findparent(a);
        int v = findparent(b);

        if (unionn(u, v) != 0) {
            printf("%d -> %d\n", a, b);
            cost1 += min;
        }

        cost[a][b] = cost[b][a] = I;
        ne++;
    }
    printf("\nMinimum cost of the tree is %d\n", cost1);

    return 0;
}

