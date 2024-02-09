#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
    }
    else {
        printf("\n");
        while (head != NULL) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n\n");
    }
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL && list2 != NULL) {
        int sum = list1->data + list2->data;
        insertNode(&result, sum);
        list1 = list1->next;
        list2 = list2->next;
    }
    return result;
}

int main() {
    struct Node* firstList = NULL;
    struct Node* secondList = NULL;
    struct Node* result = NULL;
    int n, data;
    printf("Enter the number of nodes for the 1st list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&firstList, data);
    }
    displayList(firstList);
    printf("Enter the number of nodes for the 2nd list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&secondList, data);
    }
    displayList(secondList);
    result = mergeLists(firstList, secondList);
    printf("Merged List:");
    displayList(result);
    return 0;
}
