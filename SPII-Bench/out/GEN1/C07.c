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
        scanf("%d", &n);
        long long a = 0, b = 1;
        printf("%lld", a);
        for (int i = 1; i < n; i++) {
            printf(" %lld", b);
            long long c = a + b;
            a = b;
            b = c;
        }
        printf("\n");


    return 0;
}
