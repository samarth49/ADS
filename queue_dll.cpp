//queue DLL
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct queue{
	struct node *rear;
	struct node *front;
};
void init(struct queue *q){
	q->front=NULL;
	q->rear=NULL;
}
int isEmpty(struct queue *q){
	return (q->front==NULL);
}
void enque(struct queue *q, int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next = NULL;
	newNode->prev=NULL;
	if(isEmpty(q))
	{
		q->front=newNode;
		q->rear=newNode;
	}
	else{
		q->rear->next=newNode;
		newNode->prev=q->rear;
		q->rear=newNode;
	}
}
int deque(struct queue *q){
	if(isEmpty(q)){
		printf("Underflow");
		return -1;
	}
	struct node *popped = q->front;
	int pop=popped->data;
	q->front=popped->next;
	if(q->front){
		q->front->prev=NULL;
	}
	else{
		q->rear=NULL;
	}
	free(popped);
	return pop;
}
void display(struct queue *q){
	struct node* current=q->front;
	printf("Queue: ");
	while(current){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}
int main(){
	struct queue q;
	init(&q);
	enque(&q,1);
	enque(&q,2);
	enque(&q,3);
	enque(&q,4);
	display(&q);
	deque(&q);
	display(&q);
	return 0;
}
