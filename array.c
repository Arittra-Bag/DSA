#include<stdio.h>
int main(){
	int n,i;
	printf("Enter the No. of elements: ");
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(i=n-1;i>=0;i--){
		printf("%d ",A[i]);
	}
}

