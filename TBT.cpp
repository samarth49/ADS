#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    int rbit;
    int lbit;
};
struct node *tbt(struct node *head,int data){
	//crete the new Node
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->lbit=temp->rbit=0;
	//check if it is first node that is head-> left is head
	if(head->left==head){
		temp->left=head;
		temp->right=head;
		head->left=temp;
		head->lbit=1;
		return head;
	}
	struct node *p, *q;
	p=head->left;
	//go to that location
	while(1){
		if(data > p->data && p->rbit==1){
			p=p->right;
		}
		else if(data < p->data && p->lbit==1){
			p=p->left;
		}
		else{
			break;
		}
	}
	q=p;
	if(data > q->data){
		temp->right=q->right;
		temp->left=q;
		q->right=temp;
		q->rbit=1;
	}else if  (data < q->data){
		temp->left=q->left;
		temp->right=q;
		q->left=temp;
		q->lbit=1;
	}
	return head;
}
struct node *inorder_succ(struct node *head){
	//assisn temp as head->right
	struct node *temp =head->right;
	//if head -> right is null return temp
	if(head->rbit==0){
		return temp;
	}
	else{
		while(temp->lbit==1){
			temp=temp->left;
		}
		return temp;
	}
}
void inorder(struct node *head){
	//made new t
	struct node *t =head;
	while(1){
		t=inorder_succ(t);
		if(t==head){
			break;
		}
		printf("%d ",t->data);
	}
}
void preorder(struct node *head){
	struct node *temp =head->left;
	while(temp!=head){
		printf("%d ",temp->data);
		if(temp->lbit==1){
			temp=temp->left;
		}
	else if(temp->rbit==1){
			temp=temp->right;
		}else{
			while(temp->rbit==0){
				temp=temp->right;
			}
			temp=temp->right;
		}
	}
}

int main() {
    int n;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->lbit = head->rbit = 1;
    head->left = head->right = head;

    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter the node data: ");
        scanf("%d", &data);
        head = tbt(head, data);
    }

    printf("In-order traversal: ");
    inorder(head);
    printf("\n");
    printf("Pre-oreder traversal: ");
    preorder(head);
    printf("\n");

    return 0;
}

