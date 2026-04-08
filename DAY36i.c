#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    struct Node *front = NULL, *rear = NULL;

    printf("Enter %d elements:\n", n);

    
    for (int i = 0; i < n; i=i+1) {
        int value;
        scanf("%d", &value);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (front == NULL) {
            front = rear = newNode;
            rear->next = front; 
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; 
        }
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);

    
    for (int i = 0; i < m; i++) {
        if (front == NULL) {
            printf("Queue is empty\n");
            break;
        }

        struct Node* temp = front;

        
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }

        free(temp);
    }

    
    printf("\nQueue elements (front to rear): ");

    if (front == NULL) {
        printf("Queue is empty");
    } else {
        struct Node* temp = front;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }

    printf("\n");

    return 0;
}
