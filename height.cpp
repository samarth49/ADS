//binary tree height
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
};
struct node* create(int data){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("\nMemory allocation failed");
		exit(1);
	}
	temp->data=data;
	temp->lchild=temp->rchild=NULL;
	return temp;
}
struct node* insert(struct node* root,int data){
	struct node* newNode =create(data);
	if(root==NULL){
		return newNode;
	}
	struct node* current = root;
	while(1){
		if(current->data > data){
			if(current->lchild ==NULL){
				current->lchild = newNode;
				break;
			}
			else{
				current = current->lchild;
			}
		}
		else if(current->data < data){
			if(current->rchild ==NULL){
				current->rchild=newNode;
				break;
			}
			else{
				current=current->rchild;
			}
		}
		else if(current->data == data){
			free(newNode);
			break;
		}
		
	}
	return root;
}
int height(struct node* root){
	if(root==NULL){
		return 0;
	}
	struct node* st[100];
	int height[100];
	int top=-1;
	int max_height = 0;
	st[++top]=root;
	height[top]=1;
	while(top>=0){
		struct node* current = st[top];
		int current_height = height[top];
		top--;
		if(current->lchild == NULL && current->rchild==NULL){
			max_height = (current_height > max_height) ? current_height : max_height;
		}
		if(current->lchild!=NULL){
			st[++top]=current->lchild;
			height[top]=current_height+1;
		}
		if(current->rchild !=NULL){
			st[++top]=current->rchild;
			height[top]=current_height + 1;
		}
	}
	return max_height;
}
int main(){
	struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    int heightt= height(root);
    printf("Height of the tree: %d\n", heightt);
    return 0;
}









