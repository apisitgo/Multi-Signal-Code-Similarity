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
    scanf("%lld %lld", &a, &b);
    long long x = a, y = b;
    while (y != 0) { long long t = x % y; x = y; y = t; }
    printf("%lld\n", a / x * b);

    return 0;
}
