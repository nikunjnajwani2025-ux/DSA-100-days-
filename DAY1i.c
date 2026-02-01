#include<stdio.h>

int main() {
    int n, pos, x, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];   
    
    printf("Enter array elements:\n");
    for(i = 0; i < n; i=i+1) {
        scanf("%d", &a[i]);
    }

    printf("Enter position : ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return 0;
    }

    
    for(i = n; i >= pos; i=i-1) {
        a[i] = a[i-1];
    }

    
    a[pos-1] = x;
    n=n+1;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i=i+1) {
        printf("%d ", a[i]);
    }

    return 0;
}
