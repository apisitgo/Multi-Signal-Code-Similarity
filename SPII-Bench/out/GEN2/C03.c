/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Basic Calculator #1 — Add Two Numbers
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) return 1;
    printf("%lld\n", a + b);

    return 0;
}
