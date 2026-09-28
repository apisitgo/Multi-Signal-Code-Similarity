/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #8 — LCM (Least Common Multiple)
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) return 1;

    long long x = a, y = b;
    while (y != 0) {          /* Euclid's GCD */
        long long t = x % y;
        x = y;
        y = t;
    }
    long long lcm = a / x * b;  /* divide first to avoid overflow */
    printf("%lld\n", lcm);

    return 0;
}
