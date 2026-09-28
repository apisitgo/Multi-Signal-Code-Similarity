#include <stdio.h>

int main(void)
{
    /* star pyramid pattern */
    int n;
    scanf("%d", &n);

    int i = 1;
    while (i <= n) {
        int j = 0;
        while (j < n - i) {
            printf(" ");
            j = j + 1;
        }
        int k = 0;
        while (k < 2 * i - 1) {
            printf("*");
            k = k + 1;
        }
        printf("\n");
        i = i + 1;
    }
    return 0;
}
