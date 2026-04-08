#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Enter expression: ");
    scanf("%s", s);

    int stack[100];
    int top = -1;

    int num = 0;
    char op = '+';

    for (int i = 0; i <= strlen(s); i++) {

        
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }

        
        if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' || s[i] == '\0') {

            if (op == '+') {
                stack[++top] = num;
            }
            else if (op == '-') {
                stack[++top] = -num;
            }
            else if (op == '*') {
                stack[top] = stack[top] * num;
            }
            else if (op == '/') {
                stack[top] = stack[top] / num; 
            }

            op = s[i];
            num = 0;
        }
    }

   
    int re = 0;
    for (int i = 0; i <= top; i++) {
        re = re + stack[i];
    }

    printf("Result: %d\n", re);

    return 0;
}
