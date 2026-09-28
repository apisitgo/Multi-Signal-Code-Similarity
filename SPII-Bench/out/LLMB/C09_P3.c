// star pyramid
#include <stdio.h>

int main(void)
{
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // each line has 2n-1 positions
        for (j = 0; j < 2 * n - 1; j++) {
            if (j >= n - 1 - i && j <= n - 1 + i)
                printf("*");
            else if (j < n - 1 - i)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
