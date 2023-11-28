//addition of two polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int expo;
	int coeff;
	struct node* next;
};
struct node* insert(struct node* head,int coeff,int expo){
	struct node* temp;
	struct node* newp =  (struct node*)malloc(sizeof(struct node));
	newp->coeff=coeff;
	newp->expo=expo;
	newp->next=NULL;
	
	if(head==NULL || expo > head->expo){
		newp->next = head;
		head=newp;
	}
	else{
		temp=head;
		while(temp->next && temp->next->expo > expo)
			temp=temp->next;
		newp->next=temp->next;
		temp->next=newp;
	}
	return head;
}
struct node* create(struct node* head){
	int n,i;
	int coeff,expo;
	printf("Enter the total numbember of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the coeff of term %d ",i+1);
		scanf("%d",&coeff);
		printf("Enter the expo of term %d ",i+1);
		scanf("%d",&expo);
		head=insert(head,coeff,expo);		
	}
	return head;
}
void print(struct node* head){
	if(head==NULL)
		printf("NO polynomial\n");
	else{
		struct node* temp=head;
		while(temp){
			printf("(%dx^%d)",temp->coeff,temp->expo);
			temp=temp->next;
			if(temp)
				printf("+");
			else
				printf("\n");
		}
	}
}
void polyadd(struct node* head1,struct node* head2){
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* head3=NULL;
	while(ptr1 && ptr2){
		if(ptr1->expo == ptr2->expo){
			head3=insert(head3,ptr1->coeff + ptr2->coeff,ptr1->expo);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->expo > ptr2->expo){
			head3=insert(head3,ptr1->coeff,ptr1->expo);
			ptr1=ptr1->next;
		}
		else if(ptr2->expo > ptr1->expo){
			head3=insert(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->next;
		}
	}
	while(ptr1){
		head3=insert(head3,ptr1->coeff,ptr1->expo);
		ptr1=ptr1->next;
	}
	while(ptr2){
		head3=insert(head3,ptr2->coeff,ptr2->expo);
		ptr2=ptr2->next;
	}
	printf("Added polynomial is : ");
	print(head3);
//	return head3;
}

int main(){
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	printf("Enter the polynomial: ");
	head1=create(head1);
	head2=create(head2);
	polyadd(head1,head2);
	return 0;
	
}
