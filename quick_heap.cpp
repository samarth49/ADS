//quick sort and heap sort
#include<stdio.h>
#include<stdlib.h>
struct employee{
	int id;
	char name[20];
};
void swap(struct employee  *a , struct employee *b){
	struct employee temp = *a;
	*a=*b;
	*b=temp;
}
int partation(struct employee em[],int low,int high){
	struct employee pivot = em[high];
	int i=low-1;
	for(int j=low;j<=high-1;j++){
		if(pivot.id >= em[j].id){
			i++;
			swap(&em[i], &em[j]);
            
		}
	}
	 swap(&em[i + 1], &em[high]);
	
	return i+1;
	
}
void quick(struct employee em[],int low,int high){
	if(low < high){
		int pivot=partation(em,low,high);
		quick(em,low,pivot-1);
		quick(em,pivot+1,high);
	}
}
void heapify(struct employee em[],int n,int i){
	int largest =i;
	int left = 2 * i +1;
	int right = 2 * i +2;
	if(left < n && em[left].id > em[largest].id){
		largest=left;
	}
	if(right<n && em[right].id > em[largest].id){
		largest=right;
	}
	if(largest !=i){
		swap(&em[i],&em[largest]);
		heapify(em,n,largest);
	}
}
void heap(struct employee em[],int n){
	for(int i=n/2 ;i>=0;i--){
		heapify(em,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(&em[0],&em[i]);
		heapify(em,i,0);
	}
}
int main(){
	int n;
	printf("Enter the total number of employee: ");
	scanf("%d",&n);
	struct employee em[n];
	int i;
	for(i=0;i<n;i++){
		printf("Enter the employee no: ");
		scanf("%d",&em[i].id);
		printf("Enter the name of employee: ");
		scanf("%s",em[i].name);
	}
//	quick(em,0,n-1);
heap(em,n);
	for(i=0;i<n;i++){
		printf("%d ",em[i].id);
		printf("%s ",em[i].name);
//		printf("%d\n",em[i].salary);
	}
	
	return 0;
}
