#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main(){
    int n,i,c=0;
    printf("Enter No. of Nodes: ");
    scanf("%d",&n);
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for(i=0;i<n;i++){
        struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter Data for Node-%d: ",i+1);
        scanf("%d",&ptr->data);
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
            tail = ptr;
        }
        else{
            tail->next = ptr;
            tail = ptr;
        }
    }
    printf("\nLinked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d --> ",temp->data);
        temp = temp->next;
        c++;
    }
    printf("NULL");
    printf("\nNode Count: %d",c);
    return 0;
}
