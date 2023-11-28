//two queues
//enque1 enque2 dequq1 dequq1
#include<stdio.h>
#include<stdlib.h>
#define max 10
struct queue{
	int front1;
	int rear1;
	int front2;
	int rear2;
	int arr[max];
};
void init(struct queue *q){
		q->front1=-1;
		q->rear1=-1;
		q->front2=q->rear2=max;
}
void enque1(struct queue *q,int data){
	if(q->front1==-1)
		q->front1++;
	if(q->rear1<q->rear2-1){
		q->arr[++q->rear1]=data;
	}else{
		printf("Overflow\n");
	}
}
void enque2(struct queue *q,int data){
	if(q->front2==max)
		q->front2=max-1;
	if(q->rear1 <  q->rear2-1){
		q->arr[--q->rear2]=data;
	
	}
	else{
		printf("Overflow\n");
	}
}
int pop1(struct queue *q){
	int item=-1;
	if(q->front1<q->rear1){
		item=q->arr[q->front1];
		q->front1=q->front1+1;
	}
	else{
		printf("underflow\n");
	}
	return item;
}
int pop2(struct queue *q){
	int item=-1;
	if(q->front2 > q->rear2){
		item=q->arr[q->front2];
		q->front2--;
	}else{
		printf("Underflow");
	}
	return item;
}
void display(struct queue *q){
	printf("Queue 1: ");
	for(int i=q->front1;i<= q->rear1;i++){
		printf("%d ",q->arr[i]);
	}
	printf("\nQueue 2: ");
	for(int i=q->front2;i>=q->rear2;i--){
		printf("%d ",q->arr[i]);
	}
	printf("\n");
}
int main(){
	struct queue q;
	init(&q);
	enque1(&q,1);
	enque1(&q,2);
	enque2(&q,3);
	enque2(&q,4);
	display(&q);
	
	pop1(&q);
	pop2(&q);
	display(&q);
	
	
}
