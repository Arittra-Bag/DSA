#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node* head, struct Node* tail);
void displayList(struct Node* head);
void addNodeAtBeginning(struct Node** head, struct Node** tail);
void addNodeAtEnd(struct Node** head, struct Node** tail);
void addNodeBeforeGivenNode(struct Node** head, struct Node** tail);
void addNodeAfterGivenNode(struct Node** head, struct Node** tail);
void deleteNodeFromBeginning(struct Node** head, struct Node** tail);
void deleteNodeFromEnd(struct Node** head, struct Node** tail);
void deleteGivenNode(struct Node** head, struct Node** tail);
void deleteNodeAfterGivenNode(struct Node** head, struct Node** tail);
void deleteEntireList(struct Node** head);
void sortList(struct Node** head);

int main() {
    int option;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    do {
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createList(head,tail);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                addNodeAtBeginning(&head, &tail);
                break;
            case 4:
                addNodeAtEnd(&head, &tail);
                break;
            case 5:
                addNodeBeforeGivenNode(&head, &tail);
                break;
            case 6:
                addNodeAfterGivenNode(&head, &tail);
                break;
            case 7:
                deleteNodeFromBeginning(&head, &tail);
                break;
            case 8:
                deleteNodeFromEnd(&head, &tail);
                break;
            case 9:
                deleteGivenNode(&head, &tail);
                break;
            case 10:
                deleteNodeAfterGivenNode(&head, &tail);
                break;
            case 11:
                deleteEntireList(&head);
                break;
            case 12:
                sortList(&head);
                break;
            case 13:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 13);

    return 0;
}

void createList(struct Node* head, struct Node* tail) {
    int n;
    printf("Enter No. of Nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter Data for Node-%d: ",i+1);
        scanf("%d",&ptr->data);
        ptr->next = NULL;
        if(tail == NULL){
            head = ptr;
            tail = ptr;
        }
        else{
            tail->next = ptr;
            tail = ptr;
        }
    }
}

void displayList(struct Node* head) {
    printf("\nLinked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void addNodeAtBeginning(struct Node** head, struct Node** tail) {
    
}

void addNodeAtEnd(struct Node** head, struct Node** tail) {
    
}

void addNodeBeforeGivenNode(struct Node** head, struct Node** tail) {
    
}

void addNodeAfterGivenNode(struct Node** head, struct Node** tail) {
    
}

void deleteNodeFromBeginning(struct Node** head, struct Node** tail) {
    
}

void deleteNodeFromEnd(struct Node** head, struct Node** tail) {
    
}

void deleteGivenNode(struct Node** head, struct Node** tail) {
   
}

void deleteNodeAfterGivenNode(struct Node** head, struct Node** tail) {
    
}

void deleteEntireList(struct Node** head) {
    
}

void sortList(struct Node** head) {
    
}
