#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    
    for(i = 0; i < n; i=i+1) {

        newNode = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } 
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }


    printf("\nForward Traversal:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    
    printf("\nBackward Traversal:\n");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    return 0;
}
