/* ------------------------------------------------------------
 * Programming Fundamentals - Lab exercise
 * Task    : Algorithm #30 — Divisors of a Number
 * Student : <student id> <full name>
 * ------------------------------------------------------------ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int first = 1;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
