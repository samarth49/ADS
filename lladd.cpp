//addition of linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node*create(int data){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
void insert(struct node** head,int data){
	struct node* newNode = create(data);
	if(*head==NULL){
		*head = newNode;
	}
	else{
		struct node* temp = *head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newNode;
	}

}
struct node* addLL(struct node* l1,struct node* l2){
	struct node* result=NULL;
	struct node* current = NULL;
	int carry=0;
	while(l1 || l2 || carry){
		int sum = carry + (l1 ? l1->data : 0 ) + (l2 ? l2->data : 0);
		carry =  sum/10;
		struct node* newNode = create(sum%10);
		if(result==NULL){
			result=newNode;
			current=result;
		} 
		else{
			current->next=newNode;
			current=current->next;
		}
		if(l1) l1=l1->next;
		if(l2) l2=l2->next;
	}
	return result;
}
void display(struct node* head){
	struct node* temp=head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	struct node*l1=NULL;
	struct node*l2=NULL;
	insert(&l1,2);
	insert(&l1,6);
	insert(&l1,8);
	display(l1);
	printf("\n");
	insert(&l2,1);
	insert(&l2,3);
	insert(&l2,5);
	display(l2);
	printf("\n");
	struct node* result = addLL(l1,l2);
	display(result);
}
