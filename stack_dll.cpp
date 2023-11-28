//stack using DLL
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct stack{
	struct node* top;
};
void init(struct stack *st){
	st->top=NULL;
}
int isEmpty(struct stack *st){
	return (st->top==NULL);
}
void push(struct stack *st,int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=st->top;
	newNode->prev=NULL;
	if(st->top){
		st->top->prev=newNode;
	}
	st->top=newNode;
}
int pop(struct stack *st){
	 if (isEmpty(st)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1; // Return a sentinel value indicating an error
    }
	struct node* popped =st->top;
	int pop=popped->data;
	st->top=popped->next;
	if(st->top)
		st->top->prev=NULL;
	free(popped);
	return pop;
}
void display(struct stack *st){
	struct node*current=st->top;
	printf("Stack: ");
	while(current){
		printf("%d ",current->data);
		current=current->next;
	}
	printf("\n");
}
int main(){
	struct stack st;
	init(&st);
	push(&st,1);
	push(&st,2);
	push(&st,3);
	display(&st);
	pop(&st);
	display(&st);
	return 0;
}
