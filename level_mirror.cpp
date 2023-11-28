//level wise traversal 
//mirror image
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
void levelWise(struct node* root){
	if(root==NULL){
		return;
	}
	struct node* queue[100];
	int front=0;
	int rear=0;
	queue[rear++]=root;
	while(front<rear){
		struct node* current = queue[front++];
		printf("%d ",current->data);
		if(current->lchild!=NULL){
			queue[rear++]=current->lchild;
		}
		if(current->rchild!=NULL){
			queue[rear++]=current->rchild;
		}
	}
}
void mirrorImg(struct node* root){
	if (root==NULL){
		return;
	}
	struct node* queue[100];
	int front=0;
	int rear=0;
	queue[rear++]=root;
	while(front<rear){
		struct node*current = queue[front++];
		
		//swap
		struct node*temp=current->lchild;
		current->lchild = current->rchild;
		current->rchild=temp;
		if(current->lchild!=NULL){
			queue[rear++]=current->lchild;
		}
		if(current->rchild!=NULL){
			queue[rear++]=current->rchild;
		}
	}
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

    printf("Level Wise display: ");
    levelWise(root);
    printf("\nMirror image: ");
    mirrorImg(root);
    levelWise(root);
    return 0;
}
