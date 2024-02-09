#include<stdio.h>
#include<stdlib.h>
#define Size 10

int stack[Size];
int top = -1;

int Push(int value) {
    if(top==Size-1) {
        printf("Stack Overflow \n");
    }
    else {
        top=top+1;
        stack[top] = value;
        printf("Element %d pushed into the stack \n", value);
    }
}

int Pop() {
    if(top==-1) {
        printf("Underflow \n");
    }
    else {
        printf("Element %d popped from the stack \n", stack[top]);
        top=top-1;
    }
}

int Display() {
    int i;
    if(top==-1) {
        printf("Underflow\n");
    }
    else {
        printf("Elements of the stack are: \n");
        for(i = top;i>=0;i--) {
            printf("%d \n", stack[i]);
        }
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                printf("Enter the value you want to push: ");
                scanf("%d", &value);
                Push(value);
                break;
            case 2:
                Pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exit...........");
                exit(0);
                break;
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}
