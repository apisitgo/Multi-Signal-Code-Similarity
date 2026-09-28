#include <stdio.h>

int main(void)
{
    /* least common multiple */
    long long a, b;
    scanf("%lld %lld", &a, &b);

    long long x = a;
    long long y = b;
    while (y != 0) {
        long long temp = x % y;
        x = y;
        y = temp;
    }

    long long lcm = a / x * b;
    printf("%lld\n", lcm);
    return 0;
}
