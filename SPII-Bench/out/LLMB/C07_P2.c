/* First n Fibonacci numbers, space separated. */
#include <stdio.h>

int main(void)
{
    int n, k;
    long long prev = 1, cur = 0;   /* cur = F(0), prev = F(-1) */

    scanf("%d", &n);
    for (k = 0; k < n; k++) {
        if (k > 0)
            putchar(' ');
        printf("%lld", cur);
        long long next = prev + cur;
        prev = cur;
        cur = next;
    }
    putchar('\n');
    return 0;
}
