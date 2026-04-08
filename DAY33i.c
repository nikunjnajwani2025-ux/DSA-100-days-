#include <stdio.h>
#include <string.h>

int main() {
    char infix[100], stack[100], postfix[100];
    int top = -1, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; i < strlen(infix); i=i+1) {
        char ch = infix[i];

        
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[k++] = ch;
        }
        
        else if (ch == '(') {
            stack[top=top+1] = ch;
        }
       
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k=k+1] = stack[top=top-1];
            }
            top=top-1; 
        }
        
        else {
            while (top != -1 && 
                  ((ch == '+' || ch == '-') && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')) ||
                  ((ch == '*' || ch == '/') && (stack[top] == '*' || stack[top] == '/'))) {
                
                postfix[k=k+1] = stack[top=top-1];
            }
            stack[top=top+1] = ch;
        }
    }

   
    while (top != -1) {
        postfix[k=k+1] = stack[top=top-1];
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
