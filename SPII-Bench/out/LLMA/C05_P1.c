#include <stdio.h>

static long long gcd_of(long long p, long long q) {
    while (q != 0) {
        long long r = p % q;
        p = q;
        q = r;
    }
    return p;
}

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long g = gcd_of(a, b);
    printf("%lld\n", (a / g) * b);
    return 0;
}
