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
    int n;
    long long a = 0, b = 1;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        printf(i ? " %lld" : "%lld", a);
        long long t = a + b;
        a = b;
        b = t;
    }
    printf("\n");
    return 0;
}
