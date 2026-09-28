/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>

static long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x % y);
}

static long long lcm(long long x, long long y)
{
    return x / gcd(x, y) * y;
}

int main(void)
{
    long long x, y;
    if (scanf("%lld %lld", &x, &y) != 2) return 0;
    printf("%lld\n", lcm(x, y));
    return 0;
}
