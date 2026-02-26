#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, value,i;
    struct Node *list1 = NULL, *list2 = NULL;
    struct Node *temp, *newNode;
    
   printf("Enter number of nodes in first list:");
    scanf("%d", &n);
    for(i = 0; i < n; i=i+1) {
        printf("Enter node : %d",i+1);
        scanf("%d", &value);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(list1 == NULL) {
            list1 = newNode;
        } else {
            temp = list1;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

   printf("Enter number of nodes in second list:");
    scanf("%d", &m);
    for(i = 0; i < m; i=i+1) {
         printf("Enter node : %d",i+1);
        scanf("%d", &value);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(list2 == NULL) {
            list2 = newNode;
        } else {
            temp = list2;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }


    struct Node *merged = NULL, *last = NULL;

    while(list1 != NULL && list2 != NULL) {
        struct Node *selected;

        if(list1->data <= list2->data) {
            selected = list1;
            list1 = list1->next;
        } else {
            selected = list2;
            list2 = list2->next;
        }

        selected->next = NULL;

        if(merged == NULL) {
            merged = selected;
            last = selected;
        } else {
            last->next = selected;
            last = selected;
        }
    }

    
    if(list1 != NULL)
        last->next = list1;
    if(list2 != NULL)
        last->next = list2;

  
    temp = merged;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
