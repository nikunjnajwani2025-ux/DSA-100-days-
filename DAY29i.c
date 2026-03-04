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


struct Node* rotateRight(struct Node* head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

   
    temp->next = head;

    
    k = k % length;

   
    int steps = length - k;

    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    // Break circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, value, k;
    struct Node* head = NULL;

   printf("Enter number of nodes:");
    scanf("%d", &n);

    for (int i = 0; i < n; i=i+1) {
        printf("Enter %d nodes: ",i+1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    printf("Enter the position to rotate:");
    scanf("%d", &k);

    // Rotate
    head = rotateRight(head, k);

    // Output
    printList(head);

    return 0;
}
