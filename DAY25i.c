#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, key, c = 0;
printf("Enter number of nodes:");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    
    for (i = 0; i < n; i=i+1) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter node %d :",i+1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
printf("Enter key u want to count its occurance:");
    scanf("%d", &key);

  
    temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            c=c+1;
        }
        temp = temp->next;
    }

    printf("%d", c);

    return 0;
}
