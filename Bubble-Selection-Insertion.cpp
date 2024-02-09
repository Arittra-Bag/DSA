#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int arr[], int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void InsertionSort(int arr[], int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

void SelectionSort(int arr[], int n){
	int i,j,temp,small;
	for(i=0;i<n-1;i++){
		small=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[small]){
				small=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[small];
		arr[small]=temp;
	}
}

void Display(int arr[], int n){
	int i;
	printf("Sorted Array:\n");
	for(i=0;i<n;i++){
		printf("Array[%d]: %d\n",i+1,arr[i]);
	}
}

int main() {
	int i,n,ch;
	printf("Enter the Number of Elements you want in your Array: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Array[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("-----MENU-----\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. EXIT\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:BubbleSort(arr,n);
				Display(arr,n);
				break;
		
		case 2:InsertionSort(arr,n);
				Display(arr,n);
				break;
				
		case 3:SelectionSort(arr,n);
				Display(arr,n);
				break;
				
		case 4:exit(0);
		
		default:printf("Invalid Input!");
				break;
	}
	return 0;
}
