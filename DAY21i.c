#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int main() {
 
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value,i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i=i+1) {

       
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;      
        } else {
            temp->next = newNode; 
        }

        temp = newNode;
    }

   
    printf("\nLinked List Elements:\n");

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
