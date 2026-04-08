#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    int stack[n];
    int top = -1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i=i+1) {
        int value;
        scanf("%d", &value);

        top=top+1;
        stack[top] = value;
    }

    int m;
    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

   
    for (int i = 0; i < m; i=i+1) {
        if (top == -1) {
            printf("Stack Underflow\n");
            break;
        }
        top=top-1;
    }

   
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Remaining stack : ");
        for (int i = top; i >= 0; i=i-1) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}
