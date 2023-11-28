//temp
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* lchild;
	struct node* rchild;
};
//create function
struct node* create(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->lchild=temp->rchild=0;
	return temp;
}
struct node*insert(struct node* root,int data){
	struct node* newNode = create(data);
	if(root==NULL)
		return newNode;
	struct node* current=root;
	while(1){
		if(current->data > data){
			if(current->lchild==NULL){
				current->lchild=newNode;
				break;
			}else{
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
		else if (current->data==data){
			free(newNode);
			break;
		}
	}
	return root;
}
void preorder(struct node*root){
	struct node* current =root;
	struct node*st[100];
	int top=-1;
	st[++top]=current;
	while(top>=0){
		current=st[top--];
		printf("%d ",current->data);
		if(current->rchild){
			st[++top] =current->rchild;		
		}
		
		if(current->lchild)
			st[++top]=current->lchild;
	}
	
}
void inorder(struct node* root){
	struct node* current =root;
	struct node* st[100];
	int top=-1;
	while(current || top>=0){
		while(current){
			st[++top]=current;
			current=current->lchild;
		}
		current=st[top--];
		printf("%d ",current->data);
		current=current->rchild;
	}
	
}
void postorder(struct node* root) {
    struct node* current = root;
    struct node* st[100];
    int top = -1;
    struct node* prev = NULL;
    do {
        while (current) {
            st[++top] = current;
            current = current->lchild;
        }
        if (top != -1) {
            struct node* temp = st[top];
            if (temp->rchild && temp->rchild != prev) {
                current = temp->rchild;
            } else {
                printf("%d ", temp->data);
                prev = temp;
                top--;
            }
        }
    } while (current || top != -1);
}
int no_nodes(struct node*root){
	struct node* current=root;
	struct node* st[100];
	int top=-1;
	int cnt=0;
	st[++top]=current;
	while(top>=0){
		current=st[top--];
		cnt++;
		if(current->rchild){
			st[++top]=current->rchild;
		}
		if(current->lchild)
			st[++top]=current->lchild;
	}
	return cnt;
}
int height(struct node*root){
	
	if(root==NULL){
		return 0;
	}
	struct node* st[100];
	int top=-1;
	int max=0;
	st[++top]=root;
	int heightt[100];
	heightt[top]=1;
	while(top>=0){
		struct node* current=st[top];
		int current_height = heightt[top--];
		if(current->lchild==NULL && current->rchild==NULL){
			max  = (current_height > max) ? current_height : max;
		}
		if(current->lchild){
			st[++top]=current->lchild;
			heightt[top]=current_height+1;
		}
		else if(current->rchild){
			st[++top]=current->rchild;
			heightt[top] = current_height+1;
		}
		
		
	}
	return max;
}
void levelwise(struct node*root){
	struct node* current=root;
	struct node* queue[100];
	int front=0;
	int rear=0;
	queue[rear++]=current;
	while(front!=rear){
		current=queue[front++];
		printf("%d ",current->data);
		if(current->lchild)
			queue[rear++]=current->lchild;
		if(current->rchild)
			queue[rear++]=current->rchild;
	}
}
void mirror(struct node *root){
	struct node* queue[100];
	int front=0;
	int rear=0;
	struct node* current=root;
	queue[rear++]=current;
	while(front<rear){
		current=queue[front++];
		struct node*temp=current->lchild;
		current->lchild=current->rchild;
		current->rchild=temp;
		if(current->lchild)
			queue[rear++]=current->lchild;
			
		if(current->rchild){
			queue[rear++]=current->rchild;
		}
	}
}
int main(){
	struct node*root=NULL;
	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
  
	printf("Preorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\npostorder traversal: ");
    postorder(root);
    printf("\nthe total number of nodes are %d: ",no_nodes(root));
    printf("\nhwight of tree is %d : ",height(root));
    printf("\nLevel wise order: ");
    levelwise(root);
    printf("\nmirror: ");
    mirror(root);
    preorder(root);
    return 0;
}
