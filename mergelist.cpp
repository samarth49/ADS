#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* create(int data){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
void insert(struct node** head,int data){
	struct node* newNode=create(data);
	if(*head==NULL){
		*head=newNode;
	}
	else{
		struct node* temp = *head;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
	}
}
struct node* merge(struct node* l1,struct node* l2){
	if(l1==NULL)
	return l2;
	if(l2==NULL){
		return l1;
	}
	struct node* merged=NULL;
	struct node* tail =NULL;
	while(l1 && l2){
		if(l1->data <= l2->data){
			if(merged==NULL){
				merged=l1;
				tail=l1;
			}
			else{
				tail->next=l1;
				l1->prev=tail;
				tail=l1;
			}
			l1=l1->next;
		}
		else{
			if(merged==NULL){
				merged=l2;
				tail=l2;
			}
			else{
				tail->next=l2;
				l2->prev=tail;
				tail=l2;
			}
			l2=l2->next;
		}
	}
	if(l1){
		tail->next=l1;
		l1->prev=tail;
	}
	else{
		tail->next=l2;
		l2->prev=tail;
	}
	return merged;
}
void display(struct node*head){
	struct node *temp=head;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	struct node* l1=NULL;
	struct node*l2=NULL;
//	printf("Enter the list one element: ");
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
	struct node *merged=merge(l1,l2);
	display(merged);
	return 0;
}
