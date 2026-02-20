#include <stdio.h>

int main() {
    int n,i,ts,cs,mas,cam,mis,cim,cis;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i=i+1)
        scanf("%d", &arr[i]);

    ts = 0;

    mas = arr[0];
    cam = arr[0];

    mis = arr[0];
    cim = arr[0];

    ts = arr[0];

    for (int i = 1; i < n; i++) {

       
        if (cam + arr[i] > arr[i])
            cam = cam + arr[i];
        else
            cam = arr[i];

        if (cam > mas)
            mas = cam;

        
        if (cim + arr[i] < arr[i])
            cim = cim + arr[i];
        else
            cim = arr[i];

        if (cim < mis)
            mis = cim;

        ts =ts+arr[i];
    }

  
    if (mas < 0)
        printf("Maximum Circular Subarray Sum = %d\n", mas);
    else {
         cis = ts - mis;
        if (cis > mas)
            printf("Maximum Circular Subarray Sum = %d\n", cis);
        else
            printf("Maximum Circular Subarray Sum = %d\n", mas);
    }

    return 0;
}
