#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char tokens[n][20];
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i=i+1) {
        scanf("%s", tokens[i]);
    }

    for (int i = 0; i < n; i=i+1) {

       
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (strcmp(tokens[i], "+") == 0)
                result = a + b;
            else if (strcmp(tokens[i], "-") == 0)
                result = a - b;
            else if (strcmp(tokens[i], "*") == 0)
                result = a * b;
            else
                result = a / b;

            stack[top=top+1] = result;
        }
        
        else {
            int num = 0, sign = 1;
            int j = 0;

           
            if (tokens[i][0] == '-') {
                sign = -1;
                j = 1;
            }

           
            for (; tokens[i][j] != '\0'; j=j+1) {
                num = num * 10 + (tokens[i][j] - '0');
            }

            stack[top=top+1] = num * sign;
        }
    }

    printf("%d\n", stack[top]);

    return 0;
}
