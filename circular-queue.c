#include<stdio.h>
#include<stdlib.h> 
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

int main()
{
    int choice, value;
    while(1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the value to be insert: ");
                    scanf("%d", &value);
                    insert(value);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nWrong selection!!! Try again!!!");
        }
    }
    return 0;
}

// Function to add an element in Queue
void insert(int value){
    if(front == MAX){
        front = rear = 0;
        queue[rear] = value;
    }

    else if((front == 0 && rear == MAX - 1 && front<=rear) || (front == rear + 1)){
        printf("\nOverflow!");
    }
    else if(front > rear && front == MAX){
        front = 0;
        rear = 0;
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = value;
    }
}

// Function to remove an element from Queue
void delete(){
    if(front==-1 || front > rear){
        printf("\nUnderflow!");
    }
    else{
        printf("\nDeleted element is: %d", queue[front]);
        front = front + 1;
    }
}

// Function to display the elements of Queue
void display(){
    if(front == -1 || front > rear){
        printf("\nQueue is Empty!!!");
    }
    else{
        int i;
        printf("\nQueue elements are:\n");
        for(i = front; i <= rear; i++){
            printf("%d\t", queue[i]);
        }
    }
    printf("\nFront = %d", front);
    printf("\nRear = %d", rear);
}
