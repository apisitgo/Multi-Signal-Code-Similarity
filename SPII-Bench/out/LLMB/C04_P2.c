/* Lists every positive divisor of n, space-separated. */
#include <stdio.h>

int main(void)
{
    int n, d, printed = 0;
    scanf("%d", &n);

    for (d = 1; d <= n; d++) {
        if (n % d != 0)
            continue;
        printf(printed ? " %d" : "%d", d);
        printed++;
    }
    putchar('\n');
    return 0;
}
