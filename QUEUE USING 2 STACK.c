#include <stdio.h>

void push(int stack[], int n, int *top, int item) {
    if (*top >= n - 1) {
        printf("Stack overflow\n");
        return;
    }
    *top = *top + 1;
    stack[*top] = item;
}

int pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
    }
    int item = stack[*top];
    *top = *top - 1;
    return item;
}

int main() {
    int i,n,item;

    printf("Enter the Number of Elements: ");
    scanf("%d", &n);

	int stack1[n];
    int stack2[n];
    int top1=-1,top2=-1; 

    printf("Enter the Elements for Stack:\n");
    for(i = 0; i < n; i++) {
    	printf("Element-%d: ",i+1);
        scanf("%d",&item);
        push(stack1,n,&top1,item);
    }

    while (top1 >= 0) {
        item = pop(stack1,&top1);
        push(stack2,n,&top2,item);
    }

    printf("QUEUE:\n");
    i=0;
    while (top2 >= 0) {
        item = pop(stack2,&top2);
        printf("Element-%d: %d\n",i+1,item);
        i=i+1;
    }
    printf("\n");
    return 0;
}
