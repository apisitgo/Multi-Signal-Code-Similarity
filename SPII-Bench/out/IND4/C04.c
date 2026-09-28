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
    int n, i, f = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (!f) printf(" ");
            printf("%d", i);
            f = 0;
        }
    }
    printf("\n");

    return 0;
}
