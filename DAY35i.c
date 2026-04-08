#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node *front = NULL, *rear = NULL;

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    
    printf("\nQueue elements: ");
    if (front == NULL) {
        printf("Queue is empty");
    } else {
        struct Node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    printf("\n");

    return 0;
}
