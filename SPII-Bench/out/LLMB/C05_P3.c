// LCM of two numbers
#include <stdio.h>

int main(void)
{
    long long a, b, gcd, i;
    scanf("%lld %lld", &a, &b);

    // find gcd by checking every number from the smaller one down
    gcd = 1;
    for (i = (a < b ? a : b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break;
        }
    }

    printf("%lld\n", a * b / gcd);
    return 0;
}
