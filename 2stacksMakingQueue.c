#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void push1(int item) {
    if (top1 == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack1[++top1] = item;
}

int pop1() {
    if (top1 == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack1[top1--];
}

void push2(int item) {
    if (top2 == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack2[++top2] = item;
}

int pop2() {
    if (top2 == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack2[top2--];
}

void enqueue(int item) {
    push1(item);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }
    return pop2();
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int num_elements, element;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    printf("Enter the elements:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &element);
        enqueue(element);
    }

    printf("Queue elements after enqueue: ");
    display();

    printf("Dequeue operation:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}
