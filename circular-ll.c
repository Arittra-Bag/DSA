#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(struct Node* head) {
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct Node* tail = NULL;
    for (i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if (tail != NULL) {
        tail->next = head;
    }
    return head;
}

void displayList() {
    struct Node *current = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("Head (%d)\n", current->data);
}

void addToBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        head = newNode;
        current->next = newNode;
    }
    printf("Node added at the beginning.\n");
}

void addToEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    printf("Node added at the end.\n");
}

void addToPosition(int data, int position) {
    struct Node *newNode = createNode(data);
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        addToBeginning(data);
    } else {
        struct Node *current = head;
        int count = 1;
        while (count < position - 1 && current->next != head) {
            current = current->next;
            count++;
        }
        if (count != position - 1) {
            printf("Invalid position.\n");
        } else {
            newNode->next = current->next;
            current->next = newNode;
            printf("Node added at position %d.\n", position);
        }
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node *temp = head;
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        head = head->next;
        current->next = head;
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node *current = head;
        struct Node *prev = NULL;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }
        prev->next = head;
        free(current);
        printf("Node deleted from the end.\n");
    }
}

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if (position < 1) {
        printf("Invalid position.\n");
    } else if (position == 1) {
        deleteFromBeginning();
    } else {
        struct Node *current = head;
        struct Node *prev = NULL;
        int count = 1;
        while (count < position && current->next != head) {
            prev = current;
            current = current->next;
            count++;
        }
        if (count != position) {
            printf("Invalid position.\n");
        } else {
            prev->next = current->next;
            free(current);
            printf("Node deleted from position %d.\n", position);
        }
    }
}

int nodeCount() {
    int count = 0;
    struct Node *current = head;
    if (head == NULL) {
        return count;
    }
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

void sortList() {
    struct Node *current = head, *index = NULL;
    int temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        index = current->next;
        while (index != head) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current != head);
    printf("List sorted in ascending order.\n");
}

void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    head = prev;
    printf("List reversed.\n");
}

int main() {
    int choice, data, position, num;
    do {
        printf("\nMAIN MENU:\n");
        printf("1: Create a Circular Linked List\n");
        printf("2: Display the list\n");
        printf("3: Add a node at the beginning\n");
        printf("4: Add a node at the end\n");
        printf("5: Add a node at a Specified Position\n");
        printf("6: Delete a node from the beginning\n");
        printf("7: Delete a node from the end\n");
        printf("8: Delete a node from a Specified Position\n");
        printf("9: Node Count\n");
        printf("10: Sorting the List\n");
        printf("11: Reverse the List\n");   
        printf("12: EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createList(head);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                addToBeginning(data);
                break;
            case 4:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                addToEnd(data);
                break;
            case 5:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                addToPosition(data, position);
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                printf("Enter the position: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 9:
                printf("Number of nodes in the list: %d\n", nodeCount());
                break;
            case 10:
                sortList();
                break;
            case 11:
                reverseList();
                break;
            case 12:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}
