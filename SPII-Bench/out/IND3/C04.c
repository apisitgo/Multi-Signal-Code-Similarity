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
    int n, first = 1;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0) n = -n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf(first ? "%d" : " %d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
