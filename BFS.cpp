//
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;
void enque(int x){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Queue is full ");
		return;
	}
	else{
		temp->data=x;
		temp->next=NULL;
		if(front==NULL){
			front=rear=temp;
		}
		else{
			rear->next=temp;
			rear=temp;
		}
	}
}
int deque(){
	int x=-1;
	struct node *temp;
	if(front==NULL){
		printf("Queue is EMpty ");
	}
	else{
		x=front->data;
		temp=front;
		front=front->next;
		free(temp);
	}
	return x;
}
int isEmpty(){
	return front==NULL;
}

void BFS(int G[][7],int start,int n){
	int visited[7]={0};
	int i=start;
	printf("%d ",i);
	visited[i]=1;
	enque(i);
	
	while(!isEmpty()){
		i =deque();
		for(int j=1;j<n;j++){
			if(G[i][j]==1 && visited[j]==0){
				printf("%d ",j);
				visited[j]=1;
				enque(j);
			}
		}
	}
	
}
void DFS(int G[][7],int start,int n){
	static int visited[7]={0};
	int j;
	if(visited[start]==0){
		printf("%d ",start);
		visited[start]=1;
		for(int j=1;j<n;j++){
			if(G[start][j]==1 && visited[j]==0){
				DFS(G,j,7);
			}
		}
	}
}
int main(){
	int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    printf("BFS : ");
	BFS(G,1,7);
	printf("\n");
	printf("DFS: ");
	DFS(G,1,7);
}

