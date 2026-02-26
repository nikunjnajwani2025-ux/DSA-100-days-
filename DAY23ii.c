#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *cycleNode = NULL;

    
    for (i = 0; i < n; i=i+1) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

      
        if (i == pos) {
            cycleNode = newNode;
        }
    }

    // Ask for cycle position
    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    
    if (pos != -1) {
        temp = head;
        for (i = 0; i < pos; i++) {
            temp = temp->next;
        }
        cycleNode = temp;

        
        struct Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = cycleNode;
    }

    
    struct Node* slow = head;
    struct Node* fast = head;
    int hasCycle = 0;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle)
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
