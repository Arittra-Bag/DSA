#include<stdio.h>

int main() {
    int size=10,front=-1,rear=-1,x,i;
    int arr[size];
    if(rear==size-1){
        printf("\nOverflow!\n");
    }
    else{
        if(front==-1){
            front=0;
            printf("Enter the Value to be Added: ");
            scanf("%d",&x);
            rear=rear+1;
            arr[rear]=x;
        }
    }
    if(front==-1){
        printf("\nUnderflow!\n");
    }
    else{
        printf("Elements present in Queue: ");
        for(i=front;i<=rear;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

