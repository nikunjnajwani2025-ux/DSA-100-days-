#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {

    int n, i, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No nodes\n");
        return 0;
    }

    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;
    struct ListNode *cycleNode = NULL;

    
    for (i = 0; i < n; i=i+1) {

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        printf("Enter value for node %d: ", i+1);
        scanf("%d", &newNode->val);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    if (pos != -1) {
        temp = head;
        for (i = 0; i < pos; i++) {
            temp = temp->next;
        }
        cycleNode = temp;      
        
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = cycleNode;  
    }

    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *cycleStart = NULL;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            cycleStart = slow;
            break;
        }
    }

    if (cycleStart != NULL)
        printf("Cycle starts at node with value: %d\n", cycleStart->val);
    else
        printf("No cycle detected\n");

    return 0;
}
