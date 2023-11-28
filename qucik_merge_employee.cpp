//quick sort and merge sort on employee data 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee{
	char name[20] ;
	int no;
	int salary;
};
void mergeS(struct employee p[],int left,int mid,int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	struct employee L[n1];
	struct employee R[n2];
	int i;
	for(i=0;i<n1;i++){
		L[i] = p[left+i];
	}
	for(i=0;i<n2;i++){
		R[i] = p[mid+1+i];
	}
	int a=0,b=0,k=left;
	while(a<n1 && b<n2){
		if(L[a].no <= R[b].no){
			p[k]=L[a];
			a++;
		}else{
			p[k]=R[b];
			b++;
		}
		k++;
	}
	while(a<n1){
		p[k++]=L[a++];
	}
	while(b<n2){
		p[k++]=R[b++];
	}
}
void merge(struct employee p[],int left,int right){
	if(left < right){
		int mid = left +(right-left)/2;
		merge(p,left,mid);
		merge(p,mid + 1,right);
		mergeS(p,left,mid,right);
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
		scanf("%d",&em[i].no);
		printf("Enter the name of employee: ");
		scanf("%s",em[i].name);
		printf("Enter the salary of employee: ");
		scanf("%d",&em[i].salary);
	}
	merge(em,0,n-1);
	for(i=0;i<n;i++){
		printf("%d ",em[i].no);
		printf("%s ",em[i].name);
		printf("%d\n",em[i].salary);
	}
	
	return 0;
}

