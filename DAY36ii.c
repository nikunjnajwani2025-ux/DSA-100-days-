#include <stdio.h>

int main() {
    int k;

    printf("Enter size of deque: ");
    scanf("%d", &k);

    int deque[k];
    int front = -1, rear = -1;

    int choice, value;

    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Get Front\n6.Get Rear\n7.Is Empty\n8.Is Full\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: 
            printf("Enter value: ");
            scanf("%d", &value);

            if ((front == (rear + 1) % k)) {
                printf("Deque is Full\n");
            } else {
                if (front == -1) {
                    front = rear = 0;
                } else {
                    front = (front - 1 + k) % k;
                }
                deque[front] = value;
                printf("Inserted at front\n");
            }
            break;

        case 2: 
            printf("Enter value: ");
            scanf("%d", &value);

            if ((front == (rear + 1) % k)) {
                printf("Deque is Full\n");
            } else {
                if (rear == -1) {
                    front = rear = 0;
                } else {
                    rear = (rear + 1) % k;
                }
                deque[rear] = value;
                printf("Inserted at rear\n");
            }
            break;

        case 3: 
            if (front == -1) {
                printf("Deque is Empty\n");
            } else {
                printf("Deleted from front: %d\n", deque[front]);

                if (front == rear) {
                    front = rear = -1;
                } else {
                    front = (front + 1) % k;
                }
            }
            break;

        case 4: 
            if (rear == -1) {
                printf("Deque is Empty\n");
            } else {
                printf("Deleted from rear: %d\n", deque[rear]);

                if (front == rear) {
                    front = rear = -1;
                } else {
                    rear = (rear - 1 + k) % k;
                }
            }
            break;

        case 5: 
            if (front == -1)
                printf("-1\n");
            else
                printf("Front: %d\n", deque[front]);
            break;

        case 6: 
            if (rear == -1)
                printf("-1\n");
            else
                printf("Rear: %d\n", deque[rear]);
            break;

        case 7: 
            if (front == -1)
                printf("Deque is Empty\n");
            else
                printf("Deque is Not Empty\n");
            break;

        case 8: 
            if (front == (rear + 1) % k)
                printf("Deque is Full\n");
            else
                printf("Deque is Not Full\n");
            break;

        case 9:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
