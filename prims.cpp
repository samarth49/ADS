#include<stdio.h>
#include<stdlib.h>
#define V 5
#define MAX 999
int minkey(int key[],bool mst[]){
	int min=MAX;
	int index;
	int v;
	for(int v=0 ;v < V ; v++){
		if(mst[v]==false && key[v]<min){
			min=key[v];
			index=v;
		}
	}
	return index;
}
void print(int parent[],int graph[V][V]){
	printf("Edge\tWeight\n");
	int i;
	for(i=1;i<V;i++){
		printf("%d - %d  %d\n",parent[i],i,graph[i][parent[i]]);
	}
}
void prims(int graph[V][V]){
	int parent[V];
	int key[V];
	bool MST[V];
	//initilize
	for(int i=1;i<V;i++){
		key[i]=MAX;
		MST[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(int count=0;count<V-1;count++){
		int u=minkey(key,MST);
		MST[u]=true;
		for(int v=0 ;v<V ;v++){
			if(graph[u][v] && MST[v]==false && graph[u][v] < key [v]){
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}
	print(parent,graph);
}
int main(){
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
	prims(graph);
	return 0;
}
