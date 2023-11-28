//linear hashing 
#include<stdio.h>
#define max 10
int hash(int key){
	return key%max;
}
int probe(int H[],int key){
	int index= hash(key);
	int i=0;
	while(H[index+i]%max !=0){
		i++;
	}
	return (index+i)%max;
}
void insert(int H[],int key){
	int index=hash(key);
	if(H[index]!=0){
		index=probe(H,key);
	}
	H[index]=key;
}
int search(int H[],int key){
	int index=hash(key);
	int i=0;
	while(H[(index+i)%max] !=key){
		if(H[(index+i)%max]==0){
			return -1;
		}
		i++;
	}
	return (index+i)%max;
}
void display(int H[]){
	int i;
	for(i=0;i<max;i++){
		printf("%d ",H[i]);
	}
}
int main(){
	int H[10]={0};
	int s;
	insert(H,10);
	insert(H,11);
	insert(H,3);
	insert(H,7);
	insert(H,18);
	printf("\nHash table entry are: ");
	display(H);
	printf("\nEnter the element to search : ");
	scanf("%d",&s);
	int ans=search(H,s);
	if(ans==-1){
		printf("\nElement not found");
	}
	else{
		printf("\nElemenet found at location %d",ans);
	}
	return 0;
}
