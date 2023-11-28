//counting leaf nodes
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
}*root=NULL;
struct node* create(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("\nMemory allocation failed");
		exit(1);
	}
	temp->data=data;
	temp->rchild=temp->lchild=NULL;
	return temp;
}
struct node* insert(struct node* root, int data){
	struct node* newNode = create(data);
	if(root == NULL){
		return newNode;
	}
	struct node *current = root;
	while(1){
		if(current->data > data){
			if(current->lchild == NULL){
				current->lchild = newNode;
				break;
			}
			else{
				current=current->lchild;
			}
		}
		else if(current->data < data){
			if(current->rchild == NULL){
				current->rchild=newNode;
				break;
			}
			else{
				current=current->rchild;
			}
		}
		else{
			free(newNode);
			break;
		}
	}
	return root;
}
struct node *inpre(struct node *root){
	while(root && root->lchild){
		root=root->lchild;
	}
	return root;
}
struct node *insucc(struct node *root){
	while(root && root->rchild){
		root=root->rchild;
	}
	return root;
}
struct node *deletee(struct node *p,int key){
	struct node *q;
	if(p==NULL){
		return p;
	}
	if(key < p->data){
		p->lchild=deletee(p->lchild,key);
	}
	else if(key > p->data){
		p->rchild=deletee(p->rchild,key);
	}
	else{
		//node with only one child or no child
		if(p->lchild==NULL){
			struct node *temp=p->rchild;
			free(p);
			return temp;
		}
		else if(p->rchild==NULL){
			struct node *temp=p->lchild;
			free(p);
			return temp;
		}
		struct node *temp = inpre(p->lchild);
		p->data=temp->data;
		p->lchild=deletee(p->lchild,temp->data);
	}
	return p;
}
int countLeaf(struct node* root){
	if(root==NULL){
		return 0;
	}
	struct node* st[100];
	int top=-1;
	int cnt=0;
	st[++top]=root;
	while(top>=0){
		struct node* current=st[top--];
		if(current->lchild==NULL && current->rchild==NULL){
			cnt++;
		}
		if(current->rchild){
			st[++top]=current->rchild;
		}
		if(current->lchild){
			st[++top]=current->lchild;
		}
	}
	return cnt;
}
void inorder(struct node* root){
	struct node* st[100];
	int top=-1;

	struct node* current= root;
	while(current  || top >=0){
		while(current){
			st[++top] = current;
			current=current->lchild;
		}
		current=st[top--];
		printf("%d ",current->data);
		current=current->rchild;
	}
}
int main(){
	
	root = insert(root,30);
	root = insert(root,10);
	root = insert(root,60);
	root = insert(root,50);
	inorder(root);
	int ans =  countLeaf( root);
	printf("%d ",ans);
	struct node *temp = deletee(root,30);
	printf("\n%d is deleted",temp->data);
	inorder(root);
	return 0;
}








