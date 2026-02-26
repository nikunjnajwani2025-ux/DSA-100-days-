#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, value, c = 0,i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Linked List is empty.\n");
        return 0;
    }

   
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

   
    temp = head;
    while (temp != NULL) {
        c=c+1;
        temp = temp->next;
    }

    printf("\nTotal number of nodes = %d\n", c);

    return 0;
}
