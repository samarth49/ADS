#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
};
struct node* create(int data){
	struct node* newNode =(struct node*)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("\nMemory allocation failedd");
		exit(1);
	}
	newNode->data=data;
	newNode->lchild=newNode->rchild=0;
	return newNode;
}
struct node* insert(struct node* root, int data){
	struct node* newNode = create(data);
	if(root==NULL){
		return newNode;
	}
	struct node* current = root;
	while(1){
		if(current->data > data){
			if(current->lchild==NULL){
				current->lchild=newNode;
				break;
			}
			else{
				current = current->lchild;
			}
		}
		else if ( current->data < data){
			if(current->rchild==NULL){
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
//void preorder(struct node* root){
//	if(root==NULL){
//		return;
//	}
//	struct node* st[100];
//	int top=-1;
//	st[++top]=root;
//	while(top>=0){
//		struct node* current= st[top--];
//		printf("%d ",current->data);
//		if(current->rchild!=NULL){
//			st[++top]=current->rchild;
//		}
//		if(current->lchild!=NULL){
//			st[++top]=current->lchild;
//		}
//	}
//}
//void postorder(struct node* root){
//	if(root==NULL){
//		return ;
//	}
//	struct node* st[100];
//	int top=-1;
//	struct node* current=root;
//	struct node* prev=NULL;
//	do{
//		while(current!=NULL){
//			st[++top]=current;
//			current=current->lchild;
//		}
//		while(current == NULL || top==-1){
//			struct node* temp = st[top];
//			if(temp->rchild==NULL || temp->rchild==prev){
//				printf("%d ",temp->data);
//				top--;
//				prev=temp;
//			}
//			else{
//				current=temp->rchild;
//			}
//		}
//	}while(top !=-1);
//}
int count(struct node* root) {
    if (root == NULL) {
        return 0;
    }

    struct node* st[100];
    int top = -1;
    int cnt = 0;
    struct node* current = root; // Use a temporary pointer

    while (1) {
        while (current != NULL) {
            st[++top] = current;
            current = current->lchild;
        }
        if (top == -1) {
            break;
        }
        current = st[top--];
        cnt++;
        current = current->rchild;
    }
    return cnt;
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

//    printf("Preorder Traversal: ");
//    preorder(root);
//    printf("\n");
//    printf("PostOrder: ");
//    postorder(root);
//    printf("Hello\n ");
    
//    printf("\n");
    int ans = count(root);
    printf("%d\n",ans);
    return 0;
}








