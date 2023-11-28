//quadratic hashing
#include<stdio.h>
#define size 10
int hash(int key){
	return key%size;
}
int probe(int H[],int key){
	int index=hash(key);
	int i=0;
	while(H[index+i*i]%size!=0){
		i++;
	}
	return (index+(i*i))%size;
}
void insert(int H[],int key){
	int index=hash(key);
	while(H[index]!=0){
		index = probe(H,key);
	}
	H[index]=key;
}
int search(int H[],int key){
	int index=hash(key);
	int i=0;
	while(H[(index + i*i)%size]!=key){
		if(H[(index+ i * i)%size]==0){
			return -1;
		}
		i++;
	}
	return (index + i*i)%size;
}
void display(int H[]){
	int i;
	for(i=0;i<size;i++){
		printf("%d ",H[i]);
	}
}
int main(){
		int H[10]={0};
	int s;
	insert(H,10);
	insert(H,11);
	insert(H,21);
	insert(H,31);
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



