/* Least common multiple of two integers via gcd. */
#include <stdio.h>

static long long gcd(long long p, long long q)
{
    return q == 0 ? p : gcd(q, p % q);
}

int main(void)
{
    long long m, n;
    scanf("%lld %lld", &m, &n);
    long long lcm = (m / gcd(m, n)) * n;
    printf("%lld\n", lcm);
    return 0;
}
