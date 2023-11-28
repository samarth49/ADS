//Dijstras
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//3 functions 
//int min
//void print
//void dij
#define V 9
int min(int dist[],bool sptset[]){
	int min=INT_MAX;
	int index;
	for(int i=0;i<V;i++){
		if(sptset[i]==false && dist[i] <= min){
			min=dist[i];
			index=i;
		}
	}
	return index;
}
void print(int parent[]){
	printf("Vertex \t dist from src\n");
	
	for(int i=0;i<V;i++){
		printf("%d \t\t%d\n",i,parent[i]);	
	}
}
void dij(int graph[][V],int src){
	int dist[V];
	bool sptset[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		sptset[i]=false;
	}
	dist[0]=0;
	int count=0;
	for(count=0;count<V-1;count++){
		int u=min(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<V;v++){
			if(graph[u][v] && !sptset[v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] <dist[v]){
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	print(dist);
}
int main(){
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dij(graph,0);
}
