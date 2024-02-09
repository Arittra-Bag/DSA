#include<stdio.h>
#include<stdlib.h>

int binary_search(int n,int arr[],int low,int high,int num){
	int mid=0;
	if(high>=low){
		mid=(low+high)/2;
		if(arr[mid]==num)
		return mid;
		else if(arr[mid]>num)
		return binary_search(n,arr,low,mid-1,num);
		else
		return binary_search(n,arr,mid+1,high,num);
	}
	else
	return -1;
}

void linear_search(int n,int arr[],int num){
	int i,c=0;
	for(i=0;i<n;i++){
		if(arr[i]==num){
			c=1;
			printf("Element Found at Index: %d",i+1);
			break;
		}
	}
	if(c==0)
	printf("Element Not Found in Array!\n");
}

int main(){
	int i,j,n,num,ch,result,temp;
	printf("Enter No. of Elements:");
	scanf("%d",&n);
	int low=0,high=n-1,arr[n];
	printf("Enter Values of Array:\n");
	for(i=0;i<n;i++){
		printf("Array[%d]:",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter Value to be Searched:");
	scanf("%d",&num);
	printf("\n1. Linear Search\n2. Binary Search\n3. EXIT\nEnter your Choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:linear_search(n,arr,num);
				break;
				
		case 2:for(i=0;i<n-1;i++){
					for(j=0;j<n-i-1;j++){
						if(arr[j]>arr[j+1]){
							int temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
				}
				printf("Array after Sorting:\n");
				for(i=0;i<n;i++)
				printf("Array[%d]:%d\n",i,arr[i]);
				result=binary_search(n,arr,low,high,num);
				if(result!=-1)
				printf("Element is found at Position:%d",result+1);
				else
				printf("Element Not Found in Aarray!\n");
				break;
				
		case 3:exit(0);
		
		default:printf("Invalid Choice!");
				break;
	}
	return 0;
}	
