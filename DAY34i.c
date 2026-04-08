#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int data;
    struct Node* next;
};

int main() {
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct Node* top = NULL;

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

       
        if (ch >= '0' && ch <= '9') {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = ch - '0'; 
            newNode->next = top;
            top = newNode;
        }
        
        else {
            int b = top->data;
            struct Node* temp = top;
            top = top->next;
            free(temp);

            int a = top->data;
            temp = top;
            top = top->next;
            free(temp);

            int result;

            if (ch == '+') result = a + b;
            else if (ch == '-') result = a - b;
            else if (ch == '*') result = a * b;
            else result = a / b;

            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = result;
            newNode->next = top;
            top = newNode;
        }
    }

    printf("Result: %d\n", top->data);

    return 0;
}
