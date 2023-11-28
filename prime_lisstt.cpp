#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define I 999
struct Edge{
	int weight;
	int vertex;
	struct Edge *next;
};
struct Vertex{
	struct Edge *head;
};
struct Graph{
	int num_vertex;
	struct Vertex *array;
};
//function to createEdge
struct Edge *createEdge(int vertex,int weight){
	struct Edge *newEdge = (struct Edge*)malloc(sizeof(struct Edge));
	newEdge->vertex=vertex;
	newEdge->weight=weight;
	newEdge->next=NULL;
	return newEdge;
}
//function to create the graph
struct Graph *creategraph(int vertices){
	struct Graph* graph =(struct Graph*)malloc(sizeof(struct Graph));
	graph->num_vertex=vertices;
	graph->array =(struct Vertex*)malloc(vertices * sizeof(Vertex));
	int i;
	for(i=0;i<vertices;i++){
		graph->array[i].head=0;
	}
	return graph;
}
//function to add the edge to graph
void addEdge(struct Graph*graph,int src,int desti,int weight){
	struct Edge* newEdge =createEdge(src,weight);
	newEdge->next = graph->array[desti].head;
	graph->array[desti].head=newEdge;
	
	newEdge = createEdge(desti,weight);
	newEdge->next = graph->array[src].head;
	graph->array[src].head=newEdge;
}
void primeMST(struct Graph *graph){
	int vertices = graph->num_vertex;
	int parent[graph->num_vertex];
	int key[graph->num_vertex];
	bool mst[graph->num_vertex];
	int i,j,v;
	for(i=0;i<graph->num_vertex;i++){
		key[i]=INT_MAX;
		mst[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	int count;
	for(count=0;count<graph->num_vertex-1;count++){
		int u;
		int minkey=I;
		for(v=0;v<vertices;v++){
			if(mst[v]==false && key[v] < minkey){
				minkey=key[v];
				u=v;
			}
		}
		mst[u]=true;
		struct Edge *current = graph->array[u].head;
		while(current){
			int v = current->vertex;
			int weight = current->weight;
			if(mst[v]==false && weight < key[v]){
				parent[v]=u;
				key[v]=weight;
			}
			current=current->next;
		}
	
	}
		for(i=1;i<graph->num_vertex ;i++){
			printf("Edge: %d -> %d (weight: %d)\n",parent[i],i,key[i]);
		}
}
int main() {
    int numVertices = 7;

    struct Graph* graph = creategraph(numVertices);

    int cost[][8] = {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 15, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I}
    };

    for (int i = 1; i <= numVertices; i++) {
        for (int j = i; j <= numVertices; j++) {
            if (cost[i][j] != I) {
                addEdge(graph, i - 1, j - 1, cost[i][j]);
            }
        }
    }

    printf("Minimum Spanning Tree (Prim's algorithm):\n");
    primeMST(graph);

    return 0;
}










