//two stack using array
#include<stdio.h>
#include<stdlib.h>
#define max 10
struct st{
	int top1;
	int top2;
	int arr[max];
};
void init(struct st *s){
	s->top1=-1;
	s->top2=max;
}
void push1(struct st *s,int value){
	if(s->top1 < s->top2-1){
		s->arr[++s->top1]=value;
	}
	else{
		printf("Overflow");
	}
}
void push2(struct st *s,int value){
	if(s->top1 < s->top2-1){
		s->arr[--s->top2]=value;
	}
	else{
		printf("Overflow");
	}
}
int pop1(struct st *s){
	if(s->top1>=0){
		int value =  s->arr[s->top1];
		s->top1--;
		return value;
	}
	else{
		printf("Stak underflow...\n");
		return -1;
	}
}
int pop2(struct st *s){
	if(s->top2<max){
		int value = s->arr[s->top2];
		s->top2++;
		return value;
	}else{
		printf("Stack underflow..");
		return -1;
	}
}
void display(struct st *s){
	printf("Stack1: ");
	for(int i=0;i<=s->top1;i++){
		printf("%d ",s->arr[i]);
	}
	printf("\nStack2: ");
	for(int i=max-1;i>=s->top2;i--){
		printf("%d ",s->arr[i]);
	}
	printf("\n");
}
int main(){
	struct st s;
	init(&s);
	
    push1(&s, 1);
    push1(&s, 2);
    push2(&s, 3);
    push2(&s, 4);

    display(&s);

    pop1(&s);
    pop2(&s);

    display(&s);
}

