#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
    int max_size;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue* createQueue(int max_size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    queue->max_size = max_size;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

int isFull(struct Queue* queue) {
    return (queue->size >= queue->max_size);
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue Overflow!\n");
        return;
    }
    struct Node* node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
    printf("Enqueued %d into the queue.\n", data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    struct Node* node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    queue->size--;
    return data;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int max_size, choice, data;
    printf("Enter the max. queue size: ");
    scanf("%d", &max_size);
    if (max_size <= 0) {
        printf("Invalid queue size!\n");
        return 1;
    }
    struct Queue* queue = createQueue(max_size);
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                if (!isFull(queue)) {
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &data);
                    enqueue(queue, data);
                } else {
                    printf("Queue Overflow!\n");
                }
                break;

            case 2:
                if (isEmpty(queue)) {
                    printf("Queue Underflow!\n");
                } else {
                    printf("Dequeued %d from the queue.\n", dequeue(queue));
                }
                break;

            case 3:
                display(queue);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
