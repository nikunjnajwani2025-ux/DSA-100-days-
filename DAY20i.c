#include <stdio.h>

int main() {
    int n, i, j, sum, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i=i+1)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i=i+1) {
        sum = 0;
        for (j = i; j < n; j=j+1) {
            sum += arr[j];

            if (sum == 0)
                count=count+1;
        }
    }

    printf("Number of subarrays with sum = 0: %d\n", count);

    return 0;
}
