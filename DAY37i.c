#include <stdio.h>

int main() {
    int n,i,j;
    scanf("%d", &n);

    int pq[100];
    int si = 0;

    for (i = 0; i < n; i=i+1) {
        int op;
        scanf("%d", &op);

        if (op == 1) { 
            int x;
            scanf("%d", &x);
            pq[si=si+1] = x;
        }
        else if (op == 2) { 
            if (si == 0) {
                printf("-1\n");
            } else {
                int minI = 0;

                for (j = 1; j < si; j=j+1) {
                    if (pq[j] < pq[minI]) {
                        minI = j;
                    }
                }

                printf("%d\n", pq[minI]);

               
                for (j = minI; j < si - 1; j=j+1) {
                    pq[j] = pq[j + 1];
                }
                si=si-1;
            }
        }
        else if (op == 3) { 
            if (si == 0) {
                printf("-1\n");
            } else {
                int minI = 0;

                for (int j = 1; j < si; j=j+1) {
                    if (pq[j] < pq[minI]) {
                        minI = j;
                    }
                }

                printf("%d\n", pq[minI]);
            }
        }
    }

    return 0;
}
