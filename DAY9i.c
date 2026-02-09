#include <stdio.h>
#include <string.h>

int main() {
    int c;
    printf("Enter number of characters: ");
    scanf("%d", &c);

    char co[c + 1]; 
    int i, len;
    char temp;

    printf("Enter code name: ");
    scanf("%s", co);

    len = strlen(co);

    for (i = 0; i < len / 2; i = i + 1) {
        temp = co[i];
        co[i] = co[len - 1 - i];
        co[len - 1 - i] = temp;
    }

    printf("Mirror format: %s", co);

    return 0;
}
