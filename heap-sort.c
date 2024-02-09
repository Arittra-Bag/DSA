#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void maxHeapify(struct Node *root) {
    if (root == NULL)
        return;
    struct Node *largest = root;
    struct Node *left = root->left;
    struct Node *right = root->right;

    if (left != NULL && left->data > largest->data)
        largest = left;
    if (right != NULL && right->data > largest->data)
        largest = right;

    if (largest != root) {
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;
        maxHeapify(largest);
    }
}

void minHeapify(struct Node *root) {
    if (root == NULL)
        return;
    struct Node *smallest = root;
    struct Node *left = root->left;
    struct Node *right = root->right;

    if (left != NULL && left->data < smallest->data)
        smallest = left;
    if (right != NULL && right->data < smallest->data)
        smallest = right;

    if (smallest != root) {
        int temp = root->data;
        root->data = smallest->data;
        smallest->data = temp;
        minHeapify(smallest);
    }
}

void buildMaxHeap(struct Node *root) {
    if (root == NULL)
        return;
    buildMaxHeap(root->left);
    buildMaxHeap(root->right);
    maxHeapify(root);
}

void buildMinHeap(struct Node *root) {
    if (root == NULL)
        return;
    buildMinHeap(root->left);
    buildMinHeap(root->right);
    minHeapify(root);
}

void insert(struct Node **root, int data) {
    struct Node *newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
    } else {
        struct Node *queue[100];
        int rear = -1;
        queue[++rear] = *root;

        while (rear != -1) {
            struct Node *temp = queue[0];
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            }
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            }
            queue[0] = NULL;
            for (int i = 0; i < rear; i++) {
                if (queue[i] == NULL && queue[i + 1] != NULL) {
                    struct Node *tmp = queue[i];
                    queue[i] = queue[i + 1];
                    queue[i + 1] = tmp;
                }
            }
            if (queue[rear] == NULL)
                rear--;
            else
                rear++;
            queue[++rear] = temp->left;
            queue[++rear] = temp->right;
        }
    }
}

void printTree(struct Node *root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, space);
}

void heapSort(struct Node **root, int order) {
    if (*root == NULL)
        return;

    struct Node *sorted = NULL;
    while (*root != NULL) {
        if (order == 0) { // Max Heap (Descending Order)
            buildMaxHeap(*root);
        } else if (order == 1) { // Min Heap (Ascending Order)
            buildMinHeap(*root);
        }

        // Extract the root and insert it into the sorted array
        struct Node *temp = createNode((*root)->data);
        temp->left = sorted;
        sorted = temp;

        // Replace the root with the last element in the heap
        struct Node *last = *root;
        while (last->left != NULL) {
            last = last->left;
        }
        last->left = (*root)->right;
        *root = (*root)->left;
        if (*root != NULL)
            (*root)->right = NULL;
    }
    *root = sorted;
}

void display(struct Node *root) {
    if (root == NULL)
        return;
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

int main() {
    struct Node *root = NULL;
    int choice, data, order, num, i;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter %d elements separated by spaces: ", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &data);
        insert(&root, data);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Original Binary Tree\n");
        printf("2. Heap Sort (Max Heap - Descending Order)\n");
        printf("3. Heap Sort (Min Heap - Ascending Order)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Original Binary Tree:\n");
                printTree(root, 0);
                break;
            case 2:
                order = 0; // Max Heap (Descending Order)
                heapSort(&root, order);
                printf("Sorted array (Max Heap - Descending Order): ");
                display(root);
                printf("\n");
                break;
            case 3:
                order = 1; // Min Heap (Ascending Order)
                heapSort(&root, order);
                printf("Sorted array (Min Heap - Ascending Order): ");
                display(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
