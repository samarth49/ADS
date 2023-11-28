//BFS DFS using list
#include<stdio.h>
#include<stdlib.h>
#define M 100
struct node{
	int data;
	struct node *next;
};
struct Graph{
	int visited[M];
	int no_vertex;
	struct node *adj[M];
};
void init(struct Graph *graph,int vertices){
	graph->no_vertex=vertices;
	int i;
	for(int i=0;i<vertices;i++){
		graph->adj[i]=NULL;
		graph->visited[i]=0;
	}
}
void addedge(struct Graph *graph,int src,int desti){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=desti;
	temp->next=graph->adj[src];
	graph->adj[src]=temp;
}
void BFS(struct Graph *graph,int start){
	int queue[M];
	int rear=0;
	int front=0;
	//make start as visited;
	graph->visited[start]=1;
	queue[rear++]=start;
	while(front<rear){
		int current = queue[front++];
		printf("%d ",current);
		struct node *temp=graph->adj[current];
		while(temp){
			int adjvertex=temp->data;
			if(graph->visited[adjvertex]==0){
				graph->visited[adjvertex]=1;
				queue[rear++]=adjvertex;
			}
			temp=temp->next;
		}
	}
}
void DFS(struct Graph *graph,int start){
	if(graph->visited[start]==0){
		graph->visited[start]=1;
		printf("%d ",start);
		struct node *temp = graph->adj[start];
		while(temp){
			int adjvertex= temp->data;
			if(graph->visited[adjvertex]==0){
				DFS(graph,adjvertex);
			}
			temp=temp->next;
		}
	}
}
int main(){
	struct Graph graph;
	int vertices,edges;
	printf("Enter the vertices: ");
	scanf("%d",&vertices);
	printf("Enter the number of edges: ");
	scanf("%d",&edges);
	init(&graph,vertices);
	int i;
	for(i=0;i<edges;i++){
		int src,desti;
		printf("Enter the src and desti: ");
		scanf("%d%d",&src,&desti);
		addedge(&graph,src,desti);
	}
	BFS(&graph,0);
	printf("\n");
	DFS(&graph,0);
}
