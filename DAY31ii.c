#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char stack[100];
    int top = -1;
    int valid = 1;

    printf("Enter string: ");
    scanf("%s", s);

  for (int i = 0; i < strlen(s); i=i+1) {
    char ch = s[i];

   
    if (ch == '(' || ch == '{' || ch == '[') {
        stack[top=top+1] = ch;
    }
    
    else if (ch == ')' || ch == '}' || ch == ']') {
        if (top == -1) {
            valid = 0;
            break;
        }

        char topChar = stack[top=top-1];

        if ((ch == ')' && topChar != '(') ||
            (ch == '}' && topChar != '{') ||
            (ch == ']' && topChar != '[')) {
            valid = 0;
            break;
        }
    }
   
}
 
    if (top != -1) {
        valid = 0;
    }

    if (valid) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
