#include <stdio.h>

int main() {

    int n,r,l,i,j,temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i=i+1) {
        scanf("%d", &nums[i]);
    }

    
    for (i = 0; i < n - 1; i=i+1) {
        for (j = 0; j < n - i - 1; j=j+1) {
            if (nums[j] > nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int found = 0;

    printf("Triplets:\n");

    for (i = 0; i < n - 2; i=i+1) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        l = i + 1;
        r = n - 1;

        while (l<r) {

            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {

                printf("[%d, %d, %d]\n", nums[i], nums[l], nums[r]);
                found = 1;

                l=l+1;
                r=r-1;

                while (l < r  && nums[l] == nums[l - 1])
                    l=l+1;

                while (l < r && nums[r] == nums[r + 1])
                    r=r-1;

            } 
            else if (sum < 0) {
                l=l+1;
            } 
            else {
                r=r-1;
            }
        }
    }

    if (!found) {
        printf("No triplet found whose sum is 0.\n");
    }

    return 0;
}
