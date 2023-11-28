//circular queue
#include<stdio.h>
#include<stdlib.h>
#define M 100
struct cq{
	int front,rear;
	int arr[M];
};
//initialize
void init(struct cq *q){
	q->front=q->rear=-1;
}
int isEmpty(struct cq *q){
	return (q->front==-1 && q->rear==-1);
}
int isFull(struct cq *q){
	return ((q->rear+1)%M == q->front);
}
void addF(struct cq *q , int data){
	if(isFull(q)){
		printf("Queue is full...");
		return;
	}
	if(isEmpty(q)){
		q->front=0;
		q->rear=0;
	}else{
		q->front=(q->front-1+M)%M;
	}
	q->arr[q->front]=data;
}
void addR(struct cq *q,int data){
	if(isFull(q)){
		printf("Queue is FUll...");
		return ;
	}
	if(isEmpty(q)){
		q->front=0;
		q->rear=0;
	}else{
		q->rear=(q->rear+1)%M;
	}
	
	q->arr[q->rear]=data;
}
void RF(struct cq *q){
	int x;
	if(isEmpty(q)){
		printf("Queue is EMpty...");
		return ;
	}
	printf("Removed %d from the front...", q->arr[q->front] );
	if(q->rear==q->front){
		init(q);
	}
	else{
		q->front=(q->front+1)%M;
	}
}
void RR(struct cq *q){
	if(isEmpty(q)){
		printf("Queue is Empty....");
		return ;
	}
	printf("Removed %d from rear..",q->arr[q->rear] );
	if(q->rear==q->front){
		init(q);
	}
	else{
		q->rear=(q->rear-1+M)%M;
	}
}
void display(struct cq *q ){
	if(isEmpty(q))
	{
		printf("Queue is Empty...");
		return;
	}
	int i=q->front;
	do{
		printf("%d ",q->arr[i]);
		i=(i+1)%M;
	}while(i!=(q->rear+1)%M);
}
int main(){
	struct cq q;
	init(&q);
	addF(&q,20);
	addF(&q,30);
	addF(&q,40);
	addR(&q,4);
	display(&q);
	RF(&q);
	RR(&q);
	printf("\n");
	display(&q);
}
