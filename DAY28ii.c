#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}


struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}


int isPalindrome(struct ListNode* head) {

    if (head == NULL || head->next == NULL)
        return 1;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

   
    struct ListNode *prev = NULL, *nextNode = NULL;

    while (slow != NULL) {
        nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
    }

  
    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL) {
        if (first->val != second->val)
            return 0;

        first = first->next;
        second = second->next;
    }

    return 1;
}

int main() {
    int n, value;
    struct ListNode* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i=i+1) {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    if (isPalindrome(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
