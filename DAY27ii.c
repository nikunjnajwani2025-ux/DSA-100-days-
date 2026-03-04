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

int removeCycle(struct Node* head) {

    if (head == NULL || head->next == NULL)
        return 0;

    struct Node *slow = head, *fast = head;

   
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

   
    if (fast == NULL || fast->next == NULL)
        return 0;

   
    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    
    fast->next = NULL;

    return 1;
}

int main() {
    int n, value;
    struct Node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i=i+1) {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    

    if (removeCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
