#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

int main() {

    struct Node* head = NULL;
    int size = 0;
    int choice, index, value,i;

    while (1) {

        printf("\n1. Add at Head");
        printf("\n2. Add at Tail");
        printf("\n3. Add at Index");
        printf("\n4. Delete at Index");
        printf("\n5. Get value at Index");
        printf("\n6. Print List");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {   
            printf("Enter value: ");
            scanf("%d", &value);

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->val = value;
            newNode->next = head;
            head = newNode;
            size=size+1;
        }

        else if (choice == 2) {   
            printf("Enter value: ");
            scanf("%d", &value);

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->val = value;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
            size++;
        }

        else if (choice == 3) { 
            printf("Enter index and value: ");
            scanf("%d %d", &index, &value);

            if (index < 0 || index > size) {
                printf("Invalid index\n");
            } 
            else if (index == 0) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->val = value;
                newNode->next = head;
                head = newNode;
                size++;
            } 
            else {
                struct Node* temp = head;
                for (int i = 0; i < index - 1; i++)
                    temp = temp->next;

                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->val = value;
                newNode->next = temp->next;
                temp->next = newNode;
                size++;
            }
        }

        else if (choice == 4) {   
            printf("Enter index: ");
            scanf("%d", &index);

            if (index < 0 || index >= size) {
                printf("Invalid index\n");
            } 
            else if (index == 0) {
                struct Node* temp = head;
                head = head->next;
                free(temp);
                size--;
            } 
            else {
                struct Node* temp = head;
                for (i = 0; i < index - 1; i=i+1)
                    temp = temp->next;

                struct Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;
                free(nodeToDelete);
                size--;
            }
        }

        else if (choice == 5) {   
            printf("Enter index: ");
            scanf("%d", &index);

            if (index < 0 || index >= size) {
                printf("Invalid index\n");
            } 
            else {
                struct Node* temp = head;
                for (int i = 0; i < index; i++)
                    temp = temp->next;

                printf("Value at index %d: %d\n", index, temp->val);
            }
        }

        else if (choice == 6) {  
            struct Node* temp = head;
            printf("List: ");
            while (temp != NULL) {
                printf("%d ", temp->val);
                temp = temp->next;
            }
            printf("\n");
        }

        else if (choice == 7) {   
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
