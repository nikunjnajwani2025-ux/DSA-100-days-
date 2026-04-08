#include <stdio.h>

int main() {
    int size;

    printf("Enter stack size: ");
    scanf("%d", &size);

    int stack[size];
    int top = -1;

    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    printf("\nOperations:\n");
    printf("1 value -> Push\n");
    printf("2  -> Pop\n");
    printf("3  -> Display\n\n");

    for (int i = 0; i < n; i=i+1) {
        int op, value;

        printf("Enter operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);

                if (top == size - 1) {
                    printf("Stack Overflow\n");
                } else {
                    top=top+1;
                    stack[top] = value;
                }
                break;

            case 2:
                if (top == -1) {
                    printf("Stack Underflow\n");
                } else {
                    printf("Popped: %d\n", stack[top]);
                    top=top-1;
                }
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack (top to bottom): ");
                    for (int j = top; j >= 0; j--) {
                        printf("%d ", stack[j]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}
