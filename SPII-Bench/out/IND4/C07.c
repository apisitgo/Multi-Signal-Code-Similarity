/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #27 — Fibonacci Series
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, i;
    long long a = 0, b = 1, t;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%lld", a);
        t = a + b;
        a = b;
        b = t;
    }
    printf("\n");

    return 0;
}
