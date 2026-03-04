#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

   
    if (len1 > len2) {
        while (diff=diff-1)
            head1 = head1->next;
    } else {
        while (diff=diff-1)
            head2 = head2->next;
    }

   
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

   printf("Enter number of nodes of first list:");
    scanf("%d", &n);
    for (int i = 0; i < n; i=i+1) {
        printf("Enter %d node: ",i+1);
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }
    printf("Enter number of nodes of second list:");
    scanf("%d", &m);
    for (int i = 0; i < m; i=i+1) {
          printf("Enter %d node: ",i+1);
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    
    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No intersection found\n");

    return 0;
}
