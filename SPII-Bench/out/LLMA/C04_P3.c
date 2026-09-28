#include <stdio.h>

int main(void)
{
    /* print all divisors of n */
    int n;
    scanf("%d", &n);

    int i = 1;
    int count = 0;
    while (i <= n) {
        if (n % i == 0) {
            if (count > 0) {
                printf(" ");
            }
            printf("%d", i);
            count = count + 1;
        }
        i = i + 1;
    }
    printf("\n");
    return 0;
}
