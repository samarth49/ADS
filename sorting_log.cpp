#include<stdio.h>
#include<stdlib.h>
void swapped(int arr[],int n){
	int x=-1;
	int y=-1;
	int prev =arr[0];
	for(int i=1;i<n;i++){
		if(arr[i] < prev){
			//first conflict
			if(x==-1){
				x=i-1;
				y=i;
			}
			else{
				y=i;
			}
		}
		prev=arr[i];
	}
	if(x!=-1 && y!=-1 ){
		printf("the element %d at index %d is swapped with the element %d at the index %d",arr[x],x,arr[y],y);
	}else{
		printf("No elements are swapped");
	}
}
int main(){
	int arr[]={3,5,6,9,8,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	swapped(arr,n);
}
