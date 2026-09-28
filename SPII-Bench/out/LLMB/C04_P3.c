// print all divisors of n
#include <stdio.h>

int main(void)
{
    int n, i;
    scanf("%d", &n);

    // 1 always divides n so print it first
    printf("1");
    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;
}
