#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
}*root=NULL;
struct node *create(int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
struct node *insert(struct node *root,int key){
	struct node *newNode=create(key);
	if(root==NULL){
		return newNode;
	}
	struct node *current = root;
	while(1){
		if(current->data  > key){
			if(current->left==NULL){
				current->left=newNode;
				break;
			}
			current=current->left;
		}
		else if(current->data < key){
			if(current->right==NULL){
				current->right=newNode;
				break;
			}
			current=current->right;
		}
		else{
			free(newNode);
			break;
		}
	}
	return root;
}
void inorder(struct node *root){
	struct node *temp=root;
	if(temp){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
void post(struct node *root){
	struct node *current =root;
	struct node *stack[100];
	int top=-1;
	struct node *prev =NULL;
	do{
		//go to last
		while(current){
			st[++top]=current;
			current=current->left;
		}
		if(top!=-1){
			struct node *temp = st[top];
			if(temp->right && temp->right!=prev){
				current=temp->right;
			}
			else{
				printf("%d ",temp->data);
				prev=temp;
				top--;
			}
		}
	}while(current || top !=-1);
	
}

int main(){
	root = insert(root,30);
	root = insert(root,10);
	root = insert(root,60);
	root = insert(root,50);
	inorder(root);
}
